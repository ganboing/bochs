/////////////////////////////////////////////////////////////////////////
// $Id: siminterface.cc,v 1.140 2006-04-14 08:07:24 vruppert Exp $
/////////////////////////////////////////////////////////////////////////
//
// See siminterface.h for description of the siminterface concept.
// Basically, the siminterface is visible from both the simulator and
// the configuration user interface, and allows them to talk to each other.

#include "bochs.h"
#include "iodev.h"

bx_simulator_interface_c *SIM = NULL;
logfunctions *siminterface_log = NULL;
bx_list_c *root_param = NULL;
#define LOG_THIS siminterface_log->

#define BX_MAX_USER_OPTIONS 16

// bx_simulator_interface just defines the interface that the Bochs simulator
// and the gui will use to talk to each other.  None of the methods of
// bx_simulator_interface are implemented; they are all virtual.  The
// bx_real_sim_c class is a child of bx_simulator_interface_c, and it
// implements all the methods.  The idea is that a gui needs to know only
// definition of bx_simulator_interface to talk to Bochs.  The gui should
// not need to include bochs.h.  
//
// I made this separation to ensure that all guis use the siminterface to do
// access bochs internals, instead of accessing things like
// bx_keyboard.s.internal_buffer[4] (or whatever) directly. -Bryce
// 

class bx_real_sim_c : public bx_simulator_interface_c {
  bxevent_handler bxevent_callback;
  void *bxevent_callback_data;
  const char *registered_ci_name;
  config_interface_callback_t ci_callback;
  void *ci_callback_data;
  int n_user_options;
  user_option_parser_t user_option_parser[BX_MAX_USER_OPTIONS];
  user_option_save_t user_option_save[BX_MAX_USER_OPTIONS];
  const char *user_option_name[BX_MAX_USER_OPTIONS];
  int init_done;
  int enabled;
  // save context to jump to if we must quit unexpectedly
  jmp_buf *quit_context;
  int exit_code;
  unsigned param_id;
public:
  bx_real_sim_c();
  virtual ~bx_real_sim_c();
  virtual void set_quit_context(jmp_buf *context) { quit_context = context; }
  virtual int get_init_done() { return init_done; }
  virtual int set_init_done(int n) { init_done = n; return 0;}
  virtual void reset_all_param();
  // new param methods
  virtual bx_param_c *get_param(const char *pname, bx_param_c *base=NULL);
  virtual bx_param_num_c *get_param_num(const char *pname, bx_param_c *base=NULL);
  virtual bx_param_string_c *get_param_string(const char *pname, bx_param_c *base=NULL);
  virtual bx_param_bool_c *get_param_bool(const char *pname, bx_param_c *base=NULL);
  virtual bx_param_enum_c *get_param_enum(const char *pname, bx_param_c *base=NULL);
  virtual Bit32u gen_param_id();
  virtual int get_n_log_modules();
  virtual char *get_prefix(int mod);
  virtual int get_log_action(int mod, int level);
  virtual void set_log_action(int mod, int level, int action);
  virtual char *get_action_name(int action);
  virtual int get_default_log_action(int level) {
	return logfunctions::get_default_action(level);
  }
  virtual void set_default_log_action(int level, int action) {
	logfunctions::set_default_action(level, action);
  }
  virtual const char *get_log_level_name(int level);
  virtual int get_max_log_level();
  virtual void quit_sim(int code);
  virtual int get_exit_code() { return exit_code; }
  virtual int get_default_rc(char *path, int len);
  virtual int read_rc(const char *path);
  virtual int write_rc(const char *path, int overwrite);
  virtual int get_log_file(char *path, int len);
  virtual int set_log_file(char *path);
  virtual int get_log_prefix(char *prefix, int len);
  virtual int set_log_prefix(char *prefix);
  virtual int get_debugger_log_file(char *path, int len);
  virtual int set_debugger_log_file(char *path);
  virtual int get_cdrom_options(int drive, bx_list_c **out, int *device = NULL);
  virtual void set_notify_callback(bxevent_handler func, void *arg);
  virtual void get_notify_callback(bxevent_handler *func, void **arg);
  virtual BxEvent* sim_to_ci_event(BxEvent *event);
  virtual int log_msg(const char *prefix, int level, const char *msg);
  virtual int ask_param(bx_param_c *param);
  virtual int ask_param(const char *pname);
  // ask the user for a pathname
  virtual int ask_filename(char *filename, int maxlen, char *prompt, char *the_default, int flags);
  // called at a regular interval, currently by the keyboard handler.
  virtual void periodic ();
  virtual int create_disk_image (const char *filename, int sectors, bx_bool overwrite);
  virtual void refresh_ci ();
  virtual void refresh_vga () {
    // maybe need to check if something has been initialized yet?
    DEV_vga_refresh();
  }
  virtual void handle_events () {
    // maybe need to check if something has been initialized yet?
    bx_gui->handle_events ();
  }
  // find first hard drive or cdrom
  bx_param_c *get_first_atadevice(Bit32u search_type);
  bx_param_c *get_first_cdrom() {
    return get_first_atadevice(BX_ATA_DEVICE_CDROM);
  }
  bx_param_c *get_first_hd() {
    return get_first_atadevice(BX_ATA_DEVICE_DISK);
  }
#if BX_DEBUGGER
  virtual void debug_break ();
  virtual void debug_interpret_cmd (char *cmd);
  virtual char *debug_get_next_command ();
  virtual void debug_puts (const char *cmd);
#endif
  virtual void register_configuration_interface (
    const char* name, 
    config_interface_callback_t callback,
    void *userdata);
  virtual int configuration_interface(const char* name, ci_command_t command);
  virtual int begin_simulation (int argc, char *argv[]);
  virtual void set_sim_thread_func(is_sim_thread_func_t func) {}
  virtual bx_bool is_sim_thread();
  bx_bool wxsel;
  virtual bx_bool is_wx_selected() { return wxsel; }
  // provide interface to bx_gui->set_display_mode() method for config
  // interfaces to use.
  virtual void set_display_mode(disp_mode_t newmode) {
    if (bx_gui != NULL)
      bx_gui->set_display_mode(newmode);
  }
  virtual bx_bool test_for_text_console();
  // user-defined option support
  virtual int find_user_option(const char *keyword);
  virtual bx_bool register_user_option(const char *keyword, user_option_parser_t parser, user_option_save_t save_func);
  virtual Bit32s parse_user_option(int idx, const char *context, int num_params, char *params []);
  virtual Bit32s save_user_options(FILE *fp);
#if BX_SUPPORT_SAVE_RESTORE
  // save/restore support
  virtual bx_bool save_state(const char *checkpoint_path);
  virtual bx_bool restore_config();
  virtual bx_bool restore_logopts();
  virtual bx_bool restore_hardware();
#endif
};

// recursive function to find parameters from the path
static bx_param_c *find_param(const char *full_pname, const char *rest_of_pname, bx_param_c *base)
{
  const char *from = rest_of_pname;
  char component[BX_PATHNAME_LEN];
  char *to = component;
  // copy the first piece of pname into component, stopping at first separator
  // or at the end of the string
  while (*from != 0 && *from != '.') {
    *to = *from;
    to++;
    from++;
  }
  *to = 0;
  if (!component[0]) {
    BX_PANIC (("find_param: found empty component in parameter name '%s'", full_pname));
    // or does that mean that we're done?
  }
  if (base->get_type() != BXT_LIST) {
    BX_PANIC (("find_param: base was not a list!"));
  }
  BX_DEBUG(("searching for component '%s' in list '%s'", component, base->get_name()));

  // find the component in the list.
  bx_list_c *list = (bx_list_c *)base;
  bx_param_c *child = list->get_by_name(component);
  // if child not found, there is nothing else that can be done. return NULL.
  if (child == NULL) return NULL;
  if (from[0] == 0) {
    // that was the end of the path, we're done
    return child;
  }
  // continue parsing the path
  BX_ASSERT(from[0] == '.');
  from++;  // skip over the separator
  return find_param(full_pname, from, child);
}

bx_param_c *
bx_real_sim_c::get_param(const char *pname, bx_param_c *base) 
{
  if (base == NULL)
    base = root_param;
  // to access top level object, look for parameter "."
  if (pname[0] == '.' && pname[1] == 0)
    return base;
  return find_param(pname, pname, base);
}

bx_param_num_c *
bx_real_sim_c::get_param_num (const char *pname, bx_param_c *base) {
  bx_param_c *generic = get_param(pname, base);
  if (generic==NULL) {
    BX_PANIC(("get_param_num(%s) could not find a parameter", pname));
    return NULL;
  }
  int type = generic->get_type();
  if (type == BXT_PARAM_NUM || type == BXT_PARAM_BOOL || type == BXT_PARAM_ENUM)
    return (bx_param_num_c *)generic;
  BX_PANIC(("get_param_num(%s) could not find an integer parameter with that name", pname));
  return NULL;
}

bx_param_string_c *
bx_real_sim_c::get_param_string(const char *pname, bx_param_c *base) {
  bx_param_c *generic = get_param(pname, base);
  if (generic==NULL) {
    BX_PANIC (("get_param_string(%s) could not find a parameter", pname));
    return NULL;
  }
  if (generic->get_type() == BXT_PARAM_STRING)
    return (bx_param_string_c *)generic;
  BX_PANIC(("get_param_string(%s) could not find an integer parameter with that name", pname));
  return NULL;
}

bx_param_bool_c *
bx_real_sim_c::get_param_bool(const char *pname, bx_param_c *base) {
  bx_param_c *generic = get_param(pname, base);
  if (generic==NULL) {
    BX_PANIC(("get_param_bool(%s) could not find a parameter", pname));
    return NULL;
  }
  if (generic->get_type () == BXT_PARAM_BOOL)
    return (bx_param_bool_c *)generic;
  BX_PANIC(("get_param_bool(%s) could not find a bool parameter with that name", pname));
  return NULL;
}

bx_param_enum_c *
bx_real_sim_c::get_param_enum(const char *pname, bx_param_c *base) {
  bx_param_c *generic = get_param(pname, base);
  if (generic==NULL) {
    BX_PANIC(("get_param_enum(%s) could not find a parameter", pname));
    return NULL;
  }
  if (generic->get_type() == BXT_PARAM_ENUM)
    return (bx_param_enum_c *)generic;
  BX_PANIC(("get_param_enum(%s) could not find a enum parameter with that name", pname));
  return NULL;
}

Bit32u bx_real_sim_c::gen_param_id()
{
  return param_id++;
}

void bx_init_siminterface()
{
  siminterface_log = new logfunctions();
  siminterface_log->put("CTRL");
  siminterface_log->settype(CTRLLOG);
  if (SIM == NULL) 
    SIM = new bx_real_sim_c();
  if (root_param == NULL) {
    root_param = new bx_list_c(NULL,
      "bochs",
      "list of top level bochs parameters", 
      30);
    bx_list_c *list = new bx_list_c(root_param,
	"save_restore",
	"subtree for save/restore", 
	30);
    bx_list_c *cpu = new bx_list_c(list,
	"cpu",
	"CPU State", 
	BX_MAX_SMP_THREADS_SUPPORTED);
    cpu->get_options()->set(bx_list_c::USE_TAB_WINDOW);
  }
}

bx_simulator_interface_c::bx_simulator_interface_c()
{
}

bx_real_sim_c::bx_real_sim_c()
{
  bxevent_callback = NULL;
  bxevent_callback_data = NULL;
  ci_callback = NULL;
  ci_callback_data = NULL;
  is_sim_thread_func = NULL;
  wxsel = 0;
  
  enabled = 1;
  init_done = 0;
  quit_context = NULL;
  exit_code = 0;
  param_id = BXP_NEW_PARAM_ID;
  n_user_options = 0;
}

bx_real_sim_c::~bx_real_sim_c()
{
}

void bx_real_sim_c::reset_all_param()
{
  bx_reset_options();
}

int bx_real_sim_c::get_n_log_modules()
{
  return io->get_n_logfns();
}

char *bx_real_sim_c::get_prefix(int mod)
{
  logfunc_t *logfn = io->get_logfn(mod);
  return logfn->getprefix();
}

int bx_real_sim_c::get_log_action(int mod, int level)
{
  logfunc_t *logfn = io->get_logfn(mod);
  return logfn->getonoff(level);
}

void bx_real_sim_c::set_log_action(int mod, int level, int action)
{
  // normal
  if (mod >= 0) {
    logfunc_t *logfn = io->get_logfn(mod);
    logfn->setonoff(level, action);
    return;
  }
  // if called with mod<0 loop over all
  int nmod = get_n_log_modules ();
  for (mod=0; mod<nmod; mod++)
    set_log_action(mod, level, action);
}

char *bx_real_sim_c::get_action_name(int action)
{
  return io->getaction(action);
}

const char *bx_real_sim_c::get_log_level_name(int level)
{
  return io->getlevel(level);
}

int bx_real_sim_c::get_max_log_level()
{
  return N_LOGLEV;
}

void bx_real_sim_c::quit_sim(int code) {
  BX_INFO(("quit_sim called with exit code %d", code));
  exit_code = code;
  // use longjmp to quit cleanly, no matter where in the stack we are.
  if (quit_context != NULL) {
    longjmp(*quit_context, 1);
    BX_PANIC(("in bx_real_sim_c::quit_sim, longjmp should never return"));
  }
  if (SIM->is_wx_selected()) {
    // in wxWidgets, the whole simulator is running in a separate thread.
    // our only job is to end the thread as soon as possible, NOT to shut
    // down the whole application with an exit.
    bx_stop_simulation();
  } else {
    // just a single thread.  Use exit() to stop the application.
    if (!code)
      BX_PANIC(("Quit simulation command"));
    ::exit(exit_code);
  }
}

int bx_real_sim_c::get_default_rc(char *path, int len)
{
  char *rc = bx_find_bochsrc();
  if (rc == NULL) return -1;
  strncpy(path, rc, len);
  path[len-1] = 0;
  return 0;
}

int bx_real_sim_c::read_rc(const char *rc)
{
  return bx_read_configuration(rc);
}

// return values:
//   0: written ok
//  -1: failed
//  -2: already exists, and overwrite was off
int bx_real_sim_c::write_rc(const char *rc, int overwrite)
{
  return bx_write_configuration(rc, overwrite);
}

int bx_real_sim_c::get_log_file(char *path, int len)
{
  strncpy(path, SIM->get_param_string(BXPN_LOG_FILENAME)->getptr(), len);
  return 0;
}

int bx_real_sim_c::set_log_file(char *path)
{
  SIM->get_param_string(BXPN_LOG_FILENAME)->set(path);
  return 0;
}

int bx_real_sim_c::get_log_prefix(char *prefix, int len)
{
  strncpy(prefix, SIM->get_param_string(BXPN_LOG_PREFIX)->getptr(), len);
  return 0;
}

int bx_real_sim_c::set_log_prefix(char *prefix)
{
  SIM->get_param_string(BXPN_LOG_PREFIX)->set(prefix);
  return 0;
}

int bx_real_sim_c::get_debugger_log_file(char *path, int len)
{
  strncpy(path, SIM->get_param_string(BXPN_DEBUGGER_LOG_FILENAME)->getptr(), len);
  return 0;
}

int bx_real_sim_c::set_debugger_log_file(char *path)
{
  SIM->get_param_string(BXPN_DEBUGGER_LOG_FILENAME)->set(path);
  return 0;
}

int bx_real_sim_c::get_cdrom_options(int level, bx_list_c **out, int *where)
{
  char pname[80];
  bx_list_c *devlist;

  for (Bit8u channel=0; channel<BX_MAX_ATA_CHANNEL; channel++) {
    for (Bit8u device=0; device<2; device++) {
      sprintf(pname, "ata.%d.%s", channel, (device==0)?"master":"slave");
      devlist = (bx_list_c*) SIM->get_param(pname);
      if (SIM->get_param_enum("type", devlist)->get() == BX_ATA_DEVICE_CDROM) {
        if (level==0) {
          *out = devlist;
	  if (where != NULL) *where = (channel * 2) + device;
          return 1;
        } else {
	  level--;
        }
      }
    }
  }
  return 0;
}

char *bochs_start_names[] = { "quick", "load", "edit", "run" };
int n_bochs_start_names = 3;

char *floppy_type_names[] = { "none", "1.2M", "1.44M", "2.88M", "720K", "360K", "160K", "180K", "320K", "auto", NULL };
int floppy_type_n_sectors[] = { -1, 80*2*15, 80*2*18, 80*2*36, 80*2*9, 40*2*9, 40*1*8, 40*1*9, 40*2*8, -1 };
int n_floppy_type_names = 10;

char *floppy_status_names[] = { "ejected", "inserted", NULL };
int n_floppy_status_names = 2;
char *bochs_bootdisk_names[] = { "none", "floppy", "disk","cdrom", NULL };
int n_bochs_bootdisk_names = 4;
char *loader_os_names[] = { "none", "linux", "nullkernel", NULL };
int n_loader_os_names = 3;
char *keyboard_type_names[] = { "xt", "at", "mf", NULL };
int n_keyboard_type_names = 3;

char *atadevice_type_names[] = { "disk", "cdrom", NULL };
int n_atadevice_type_names = 2;
//char *atadevice_mode_names[] = { "flat", "concat", "external", "dll", "sparse", "vmware3", "split", "undoable", "growing", "volatile", "z-undoable", "z-volatile", NULL };
char *atadevice_mode_names[] = { "flat", "concat", "external", "dll", "sparse", "vmware3", "undoable", "growing", "volatile", NULL };
int n_atadevice_mode_names = 9;
char *atadevice_status_names[] = { "ejected", "inserted", NULL };
int n_atadevice_status_names = 2;
char *atadevice_biosdetect_names[] = { "none", "auto", "cmos", NULL };
int n_atadevice_biosdetect_names = 3;
char *atadevice_translation_names[] = { "none", "lba", "large", "rechs", "auto", NULL };
int n_atadevice_translation_names = 5;
char *clock_sync_names[] = { "none", "realtime", "slowdown", "both", NULL };
int clock_sync_n_names=4;


void bx_real_sim_c::set_notify_callback(bxevent_handler func, void *arg)
{
  bxevent_callback = func;
  bxevent_callback_data = arg;
}

void bx_real_sim_c::get_notify_callback(
    bxevent_handler *func,
    void **arg)
{
  *func = bxevent_callback;
  *arg = bxevent_callback_data;
}

BxEvent *bx_real_sim_c::sim_to_ci_event(BxEvent *event)
{
  if (bxevent_callback == NULL) {
    BX_ERROR(("notify called, but no bxevent_callback function is registered"));
    return NULL;
  } else {
    return (*bxevent_callback)(bxevent_callback_data, event);
  }
}

// returns 0 for continue, 1 for alwayscontinue, 2 for die.
int bx_real_sim_c::log_msg(const char *prefix, int level, const char *msg)
{
  BxEvent be;
  be.type = BX_SYNC_EVT_LOG_ASK;
  be.u.logmsg.prefix = prefix;
  be.u.logmsg.level = level;
  be.u.logmsg.msg = msg;
  // default return value in case something goes wrong.
  be.retcode = BX_LOG_NOTIFY_FAILED;
  // calling notify
  sim_to_ci_event (&be);
  return be.retcode;
}

// Called by simulator whenever it needs the user to choose a new value
// for a registered parameter.  Create a synchronous ASK_PARAM event, 
// send it to the CI, and wait for the response.  The CI will call the
// set() method on the parameter if the user changes the value.
int bx_real_sim_c::ask_param(bx_param_c *param)
{
  BX_ASSERT(param != NULL);
  // create appropriate event
  BxEvent event;
  event.type = BX_SYNC_EVT_ASK_PARAM;
  event.u.param.param = param;
  sim_to_ci_event(&event);
  return event.retcode;
}

int bx_real_sim_c::ask_param(const char *pname)
{
  bx_param_c *paramptr = SIM->get_param(pname);
  BX_ASSERT(paramptr != NULL);
  // create appropriate event
  BxEvent event;
  event.type = BX_SYNC_EVT_ASK_PARAM;
  event.u.param.param = paramptr;
  sim_to_ci_event(&event);
  return event.retcode;
}

int bx_real_sim_c::ask_filename(char *filename, int maxlen, char *prompt, char *the_default, int flags)
{
  BxEvent event;
  bx_param_string_c param(NULL, "filename", prompt, "", the_default, maxlen);
  flags |= param.IS_FILENAME;
  param.get_options()->set (flags);
  event.type = BX_SYNC_EVT_ASK_PARAM;
  event.u.param.param = &param;
  sim_to_ci_event (&event);
  if (event.retcode >= 0)
    memcpy(filename, param.getptr(), maxlen);
  return event.retcode;
}

void bx_real_sim_c::periodic()
{
  // give the GUI a chance to do periodic things on the bochs thread. in 
  // particular, notice if the thread has been asked to die.
  BxEvent tick;
  tick.type = BX_SYNC_EVT_TICK;
  sim_to_ci_event (&tick);
  if (tick.retcode < 0) {
    BX_INFO(("Bochs thread has been asked to quit."));
    bx_atexit();
    quit_sim(0);
  }
  static int refresh_counter = 0;
  if (++refresh_counter == 50) {
    // only ask the CI to refresh every 50 times periodic() is called.
    // This should obviously be configurable because system speeds and
    // user preferences vary.
    refresh_ci();
    refresh_counter = 0;
  }
#if 0
  // watch for memory leaks.  Allocate a small block of memory, print the
  // pointer that is returned, then free.
  BxEvent *memcheck = new BxEvent ();
  BX_INFO(("memory allocation at %p", memcheck));
  delete memcheck;
#endif
}

// create a disk image file called filename, size=512 bytes * sectors.
// If overwrite is 0 and the file exists, returns -1 without changing it.
// Otherwise, opens up the image and starts writing.  Returns -2 if
// the image could not be opened, or -3 if there are failures during
// write, e.g. disk full.
// 
// wxWidgets: This may be called from the gui thread.
int bx_real_sim_c::create_disk_image(
    const char *filename,
    int sectors,
    bx_bool overwrite) 
{
  FILE *fp;
  if (!overwrite) {
    // check for existence first
    fp = fopen(filename, "r");
    if (fp) {
      // yes it exists
      fclose(fp);
      return -1;
    }
  }
  fp = fopen(filename, "w");
  if (fp == NULL) {
#ifdef HAVE_PERROR
    char buffer[1024];
    sprintf(buffer, "while opening '%s' for writing", filename);
    perror(buffer);
    // not sure how to get this back into the CI
#endif
    return -2;
  }
  int sec = sectors;
  /*
   * seek to sec*512-1 and write a single character.
   * can't just do: fseek(fp, 512*sec-1, SEEK_SET)
   * because 512*sec may be too large for signed int.
   */
  while (sec > 0)
  {
    /* temp <-- min(sec, 4194303)
     * 4194303 is (int)(0x7FFFFFFF/512)
     */
    int temp = ((sec < 4194303) ? sec : 4194303);
    fseek(fp, 512*temp, SEEK_CUR);
    sec -= temp;
  }

  fseek(fp, -1, SEEK_CUR);
  if (fputc('\0', fp) == EOF)
  {
    fclose(fp);
    return -3;
  }
  fclose(fp);
  return 0;
}

void bx_real_sim_c::refresh_ci() {
  if (SIM->is_wx_selected()) {
    // presently, only wxWidgets interface uses these events
    // It's an async event, so allocate a pointer and send it.
    // The event will be freed by the recipient.
    BxEvent *event = new BxEvent ();
    event->type = BX_ASYNC_EVT_REFRESH;
    sim_to_ci_event(event);
  }
}

bx_param_c *bx_real_sim_c::get_first_atadevice(Bit32u search_type) {
  char pname[80];
  for (int channel=0; channel<BX_MAX_ATA_CHANNEL; channel++) {
    sprintf(pname, "ata.%d.resources.enabled", channel);
    if (!SIM->get_param_bool(pname)->get())
      continue;
    for (int slave=0; slave<2; slave++) {
      sprintf(pname, "ata.%d.%s.present", channel, (slave==0)?"master":"slave");
      Bit32u present = SIM->get_param_bool(pname)->get();
      sprintf(pname, "ata.%d.%s.type", channel, (slave==0)?"master":"slave");
      Bit32u type = SIM->get_param_enum(pname)->get();
      if (present && (type == search_type)) {
        sprintf(pname, "ata.%d.%s", channel, (slave==0)?"master":"slave");
	return SIM->get_param(pname);
      }
    }
  }
  return NULL;
}

#if BX_DEBUGGER

// this can be safely called from either thread.
void bx_real_sim_c::debug_break() {
  bx_debug_break();
}

// this should only be called from the sim_thread.
void bx_real_sim_c::debug_interpret_cmd(char *cmd) {
  if (!is_sim_thread()) {
    fprintf(stderr, "ERROR: debug_interpret_cmd called but not from sim_thread\n");
    return;
  }
  bx_dbg_interpret_line(cmd);
}

char *bx_real_sim_c::debug_get_next_command()
{
  fprintf(stderr, "begin debug_get_next_command\n");
  BxEvent event;
  event.type = BX_SYNC_EVT_GET_DBG_COMMAND;
  BX_INFO(("asking for next debug command"));
  sim_to_ci_event (&event);
  BX_INFO(("received next debug command: '%s'", event.u.debugcmd.command));
  if (event.retcode >= 0)
    return event.u.debugcmd.command;
  return NULL;
}

void bx_real_sim_c::debug_puts(const char *text)
{
  if (SIM->is_wx_selected()) {
    // send message to the wxWidgets debugger
    BxEvent *event = new BxEvent();
    event->type = BX_ASYNC_EVT_DBG_MSG;
    event->u.logmsg.msg = text;
    sim_to_ci_event (event);
    // the event will be freed by the recipient
  } else {
    // text mode debugger: just write to console
    fputs(text, stderr);
    delete [] (char *)text;
  }
}
#endif

void bx_real_sim_c::register_configuration_interface(
  const char* name, 
  config_interface_callback_t callback,
  void *userdata)
{
  ci_callback = callback;
  ci_callback_data = userdata;
  registered_ci_name = name;
}

int bx_real_sim_c::configuration_interface(const char *ignore, ci_command_t command)
{
  bx_param_enum_c *ci_param = SIM->get_param_enum(BXPN_SEL_CONFIG_INTERFACE);
  char *name = ci_param->get_selected();
  if (!ci_callback) {
    BX_PANIC(("no configuration interface was loaded"));
    return -1;
  }
  if (strcmp(name, registered_ci_name) != 0) {
    BX_PANIC(("siminterface does not support loading one configuration interface and then calling another"));
    return -1;
  }
  if (!strcmp(name, "wx")) 
    wxsel = 1;
  else
    wxsel = 0;
  // enter configuration mode, just while running the configuration interface
  set_display_mode(DISP_MODE_CONFIG);
  int retval = (*ci_callback)(ci_callback_data, command);
  set_display_mode(DISP_MODE_SIM);
  return retval;
}

int bx_real_sim_c::begin_simulation(int argc, char *argv[])
{
  return bx_begin_simulation(argc, argv);
}

bx_bool bx_real_sim_c::is_sim_thread()
{
  if (is_sim_thread_func == NULL) return 1;
  return (*is_sim_thread_func)();
}

// check if the text console exists.  On some platforms, if Bochs is
// started from the "Start Menu" or by double clicking on it on a Mac,
// there may be nothing attached to stdin/stdout/stderr.  This function
// tests if stdin/stdout/stderr are usable and returns 0 if not.
bx_bool bx_real_sim_c::test_for_text_console()
{
#if BX_WITH_CARBON
  // In a Carbon application, you have a text console if you run the app from
  // the command line, but if you start it from the finder you don't.
  if(!isatty(STDIN_FILENO)) return 0;
#endif
  // default: yes
  return 1;
}

int bx_real_sim_c::find_user_option(const char *keyword)
{
  int i = 0;
  while (i < n_user_options) {
    if (!strcmp(keyword, user_option_name[i])) {
      return i;
    }
    i++;
  }
  return -1;
}

bx_bool bx_real_sim_c::register_user_option(const char *keyword, user_option_parser_t parser,
                                            user_option_save_t save_func)
{
  int idx;

  if (n_user_options >= BX_MAX_USER_OPTIONS) {
    return 0;
  }
  idx = find_user_option(keyword);
  if (idx >= 0) {
    if (parser == user_option_parser[idx]) {
      // parse handler already registered
      return 1;
    } else {
      // keyword already exists
      return 0;
    }
  } else {
    user_option_name[n_user_options] = keyword;
    user_option_parser[n_user_options] = parser;
    user_option_save[n_user_options++] = save_func;
    return 1;
  }
}

Bit32s bx_real_sim_c::parse_user_option(int idx, const char *context, int num_params, char *params [])
{
  if ((idx < 0) || (idx >= n_user_options)) {
    return -1;
  }
  return (*user_option_parser[idx])(context, num_params, params);
}

Bit32s bx_real_sim_c::save_user_options(FILE *fp)
{
  int i;

  for (i = 0; i < n_user_options; i++) {
    if (user_option_save[i] != NULL) {
      (*user_option_save[i])(fp);
    }
  }
  return 0;
}

#if BX_SUPPORT_SAVE_RESTORE
bx_bool bx_real_sim_c::save_state(const char *checkpoint_path)
{
  char config[BX_PATHNAME_LEN];
  char logopts[BX_PATHNAME_LEN];
  char prefix[8];
  int i, dev, ndev = SIM->get_n_log_modules();
  int type, ntype = SIM->get_max_log_level();
  FILE *fp;

  sprintf(config, "%s/config", checkpoint_path);
  write_rc(config, 1);
  sprintf(logopts, "%s/logopts", checkpoint_path);
  fp = fopen(logopts, "w");
  if (fp != NULL) {
    for (dev=0; dev<ndev; dev++) {
      strcpy(prefix, get_prefix(dev));
      strcpy(prefix, prefix+1);
      prefix[strlen(prefix) - 1] = 0;
      i = strlen(prefix) - 1;
      while ((i >= 0) && (prefix[i] == ' ')) prefix[i--] = 0;
      if (strlen(prefix) > 0) {
        fprintf(fp, "%s: ", prefix);
        for (type=0; type<ntype; type++) {
          if (type > 0) fprintf(fp, ", ");
          fprintf(fp, "%s=%s", get_log_level_name(type), get_action_name(get_log_action(dev, type)));
        }
        fprintf(fp, "\n");
      }
    }
    fclose(fp);
  }
  // TODO
  fprintf(stderr, "save_state (not yet complete)\n");
  return 0;
}

bx_bool bx_real_sim_c::restore_config()
{
  char config[BX_PATHNAME_LEN];

  sprintf(config, "%s/config", get_param_string(BXPN_RESTORE_PATH)->getptr());
  BX_INFO(("restoring '%s'", config));
  read_rc(config);
  return 0;
}

bx_bool bx_real_sim_c::restore_logopts()
{
  char logopts[BX_PATHNAME_LEN];
  FILE *fp;
  char line[512], string[512], prefix[8];
  char *ret, *ptr;
  int d, i, j, dev = 0, type = 0, action = 0;
  int ndev = SIM->get_n_log_modules();

  sprintf(logopts, "%s/logopts", get_param_string(BXPN_RESTORE_PATH)->getptr());
  BX_INFO(("restoring '%s'", logopts));
  fp = fopen(logopts, "r");
  if (fp != NULL) {
    do {
      ret = fgets(line, sizeof(line)-1, fp);
      line[sizeof(line) - 1] = '\0';
      int len = strlen(line);
      if ((len>0) && (line[len-1] < ' '))
        line[len-1] = '\0';
      i = 0;
      if ((ret != NULL) && strlen(line)) {
        ptr = strtok(line, ":");
        while (ptr) {
          strcpy(string, ptr);
          while (isspace(string[0])) strcpy(string, string+1);
          while (isspace(string[strlen(string)-1])) string[strlen(string)-1] = 0;
          if (i == 0) {
            sprintf(prefix, "[%-5s]", string);
            dev = -1;
            for (d = 0; d < ndev; d++) {
              if (!strcmp(prefix, get_prefix(d))) {
                dev = d;
              }
            }
          } else if (dev >= 0) {
            j = 6;
            if (!strncmp(string, "DEBUG=", 6)) {
              type = LOGLEV_DEBUG;
            } else if (!strncmp(string, "INFO=", 5)) {
              type = LOGLEV_INFO;
              j = 5;
            } else if (!strncmp(string, "ERROR=", 6)) {
              type = LOGLEV_ERROR;
            } else if (!strncmp(string, "PANIC=", 6)) {
              type = LOGLEV_PANIC;
            } else if (!strncmp(string, "PASS=", 5)) {
              type = LOGLEV_PASS;
              j = 5;
            }
            if (!strcmp(string+j, "ignore")) {
              action = ACT_IGNORE;
            } else if (!strcmp(string+j, "report")) {
              action = ACT_REPORT;
            } else if (!strcmp(string+j, "ask")) {
              action = ACT_ASK;
            } else if (!strcmp(string+j, "fatal")) {
              action = ACT_FATAL;
            }
            set_log_action(dev, type, action);
          } else {
            if (i == 1) {
              BX_ERROR(("restore_logopts(): log module '%s' not found", prefix));
            }
          }
          i++;
          ptr = strtok(NULL, ",");
        }
      }
    } while (!feof(fp));
    fclose(fp);
  }
  return 0;
}

bx_bool bx_real_sim_c::restore_hardware()
{
  // TODO
  fprintf(stderr, "restore_hardware (not implemented yet)\n");
  return 0;
}
#endif 


/////////////////////////////////////////////////////////////////////////
// define methods of bx_param_* and family
/////////////////////////////////////////////////////////////////////////

bx_object_c::bx_object_c(Bit32u id)
{
  this->id = id;
  this->type = BXT_OBJECT;
}

void bx_object_c::set_type(bx_objtype type)
{
  this->type = type;
}

const char* bx_param_c::default_text_format = NULL;

bx_param_c::bx_param_c(Bit32u id, char *name, char *description)
  : bx_object_c(id)
{
  set_type(BXT_PARAM);
  this->name = name;
  this->description = description;
  this->text_format = default_text_format;
  this->long_text_format = default_text_format;
  this->ask_format = NULL;
  this->label = NULL;
  this->group_name = NULL;
  this->runtime_param = 0;
  this->enabled = 1;
  this->parent = NULL;
}

int bx_param_c::get_param_path(char *path_out, int maxlen)
{
  if ((get_parent() == NULL) || (get_parent() == root_param)) {
    // Start with an empty string.
    // Never print the name of the root param.
    path_out[0] = 0;
  } else {
    // build path of the parent, add a period, add path of this node
    if (get_parent()->get_param_path(path_out, maxlen) > 0) {
      strncat(path_out, ".", maxlen);
    }
  }
  strncat(path_out, name, maxlen);
  return strlen(path_out);
}

const char* bx_param_c::set_default_format(const char *f) {
  const char *old = default_text_format;
  default_text_format = f; 
  return old;
}

bx_param_num_c::bx_param_num_c(bx_param_c *parent,
    char *name,
    char *label,
    char *description,
    Bit64s min, Bit64s max, Bit64s initial_val)
  : bx_param_c(SIM->gen_param_id(), name, description)
{
  set_type(BXT_PARAM_NUM);
  this->label = label;
  this->min = min;
  this->max = max;
  this->initial_val = initial_val;
  this->val.number = initial_val;
  this->handler = NULL;
  this->enable_handler = NULL;
  this->base = default_base;
  // dependent_list must be initialized before the set(),
  // because set calls update_dependents().
  dependent_list = NULL;
  set(initial_val);
  if (parent) {
    BX_ASSERT(parent->get_type() == BXT_LIST);
    this->parent = (bx_list_c *)parent;
    this->parent->add(this);
  }
}

Bit32u bx_param_num_c::default_base = 10;

Bit32u bx_param_num_c::set_default_base(Bit32u val) {
  Bit32u old = default_base;
  default_base = val; 
  return old;
}

void bx_param_num_c::reset()
{
  this->val.number = initial_val;
}

void bx_param_num_c::set_handler(param_event_handler handler)
{ 
  this->handler = handler; 
  // now that there's a handler, call set once to run the handler immediately
  //set (get ());
}

void bx_param_num_c::set_enable_handler(param_enable_handler handler)
{ 
  this->enable_handler = handler; 
}

void bx_param_num_c::set_dependent_list(bx_list_c *l) {
  dependent_list = l;
  update_dependents();
}

Bit64s bx_param_num_c::get64()
{
  if (handler) {
    // the handler can decide what value to return and/or do some side effect
    return (*handler)(this, 0, val.number);
  } else {
    // just return the value
    return val.number;
  }
}

void bx_param_num_c::set(Bit64s newval)
{
  if (handler) {
    // the handler can override the new value and/or perform some side effect
    val.number = newval;
    (*handler)(this, 1, newval);
  } else {
    // just set the value.  This code does not check max/min.
    val.number = newval;
  }
  if ((val.number < min || val.number > max) && (Bit64u)max != BX_MAX_BIT64U)
    BX_PANIC(("numerical parameter '%s' was set to " FMT_LL "d, which is out of range " FMT_LL "d to " FMT_LL "d", get_name (), val.number, min, max));
  if (dependent_list != NULL) update_dependents();
}

void bx_param_num_c::set_range(Bit64u min, Bit64u max)
{
  this->min = min;
  this->max = max;
}

void bx_param_num_c::set_initial_val(Bit64s initial_val) { 
  this->val.number = this->initial_val = initial_val;
}

void bx_param_num_c::update_dependents()
{
  if (dependent_list) {
    int en = val.number && enabled;
    for (int i=0; i<dependent_list->get_size(); i++) {
      bx_param_c *param = dependent_list->get(i);
      if (param != this)
	param->set_enabled(en);
    }
  }
}

void bx_param_num_c::set_enabled(int en)
{
  // The enable handler may wish to allow/disallow the action
  if (enable_handler) {
    en = (*enable_handler)(this, en);
    }
  bx_param_c::set_enabled(en);
  update_dependents();
}

// Signed 64 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *description,
    Bit64s *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, description, NULL, BX_MIN_BIT64S, BX_MAX_BIT64S, *ptr_to_real_val)
{
  this->varsize = 16;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p64bit = ptr_to_real_val;
}

// Unsigned 64 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit64u *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT64U, BX_MAX_BIT64U, *ptr_to_real_val)
{
  this->varsize = 16;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p64bit = (Bit64s*) ptr_to_real_val;
}

// Signed 32 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit32s *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT32S, BX_MAX_BIT32S, *ptr_to_real_val)
{
  this->varsize = 16;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p32bit = ptr_to_real_val;
}

// Unsigned 32 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit32u *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT32U, BX_MAX_BIT32U, *ptr_to_real_val)
{
  this->varsize = 32;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p32bit = (Bit32s*) ptr_to_real_val;
}

// Signed 16 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit16s *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT16S, BX_MAX_BIT16S, *ptr_to_real_val)
{
  this->varsize = 16;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p16bit = ptr_to_real_val;
}

// Unsigned 16 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit16u *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT16U, BX_MAX_BIT16U, *ptr_to_real_val)
{
  this->varsize = 16;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p16bit = (Bit16s*) ptr_to_real_val;
}

// Signed 8 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit8s *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT8S, BX_MAX_BIT8S, *ptr_to_real_val)
{
  this->varsize = 16;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p8bit = ptr_to_real_val;
}

// Unsigned 8 bit
bx_shadow_num_c::bx_shadow_num_c(bx_param_c *parent,
    char *name,
    char *label,
    Bit8u *ptr_to_real_val,
    Bit8u highbit,
    Bit8u lowbit)
: bx_param_num_c(parent, name, label, NULL, BX_MIN_BIT8U, BX_MAX_BIT8U, *ptr_to_real_val)
{
  this->varsize = 8;
  this->lowbit = lowbit;
  this->mask = (1 << (highbit - lowbit)) - 1;
  val.p8bit = (Bit8s*) ptr_to_real_val;
}

Bit64s bx_shadow_num_c::get64() {
  Bit64u current = 0;
  switch (varsize) {
    case 8: current = *(val.p8bit);  break;
    case 16: current = *(val.p16bit);  break;
    case 32: current = *(val.p32bit);  break;
    case 64: current = *(val.p64bit);  break;
    default: BX_PANIC(("unsupported varsize %d", varsize));
  }
  current = (current >> lowbit) & mask;
  if (handler) {
    // the handler can decide what value to return and/or do some side effect
    return (*handler)(this, 0, current) & mask;
  } else {
    // just return the value
    return current;
  }
}

void bx_shadow_num_c::set(Bit64s newval)
{
  Bit64u tmp = 0;
  if ((newval < min || newval > max) && (Bit64u)max != BX_MAX_BIT64U)
    BX_PANIC (("numerical parameter %s was set to " FMT_LL "d, which is out of range " FMT_LL "d to " FMT_LL "d", get_name (), newval, min, max));
  switch (varsize) {
    case 8: 
      tmp = (*(val.p8bit) >> lowbit) & mask;
      tmp |= (newval & mask) << lowbit;
      *(val.p8bit) = (Bit8s)tmp;
      break;
    case 16:
      tmp = (*(val.p16bit) >> lowbit) & mask;
      tmp |= (newval & mask) << lowbit;
      *(val.p16bit) = (Bit16s)tmp;
      break;
    case 32:
      tmp = (*(val.p32bit) >> lowbit) & mask;
      tmp |= (newval & mask) << lowbit;
      *(val.p32bit) = (Bit32s)tmp;
      break;
    case 64:
      tmp = (*(val.p64bit) >> lowbit) & mask;
      tmp |= (newval & mask) << lowbit;
      *(val.p64bit) = tmp;
      break;
    default: 
      BX_PANIC(("unsupported varsize %d", varsize));
  }
  if (handler) {
    // the handler can override the new value and/or perform some side effect
    (*handler)(this, 1, tmp);
  }
}

void bx_shadow_num_c::reset()
{
  BX_PANIC(("reset not supported on bx_shadow_num_c yet"));
}

bx_param_bool_c::bx_param_bool_c(bx_param_c *parent,
    char *name,
    char *label,
    char *description,
    Bit64s initial_val)
  : bx_param_num_c(parent, name, label, description, 0, 1, initial_val)
{
  set_type(BXT_PARAM_BOOL);
  set(initial_val);
}

bx_shadow_bool_c::bx_shadow_bool_c(bx_param_c *parent,
      char *name,
      char *label,
      bx_bool *ptr_to_real_val,
      Bit8u bitnum)
  : bx_param_bool_c(parent, name, label, NULL, (Bit64s) *ptr_to_real_val)
{
  val.pbool = ptr_to_real_val;
  this->bitnum = bitnum;
}

Bit64s bx_shadow_bool_c::get64() {
  if (handler) {
    // the handler can decide what value to return and/or do some side effect
    Bit64s ret = (*handler)(this, 0, (Bit64s) *(val.pbool));
    return (ret>>bitnum) & 1;
  } else {
    // just return the value
    return (*(val.pbool)) & 1;
  }
}

void bx_shadow_bool_c::set(Bit64s newval)
{
  // only change the bitnum bit
  Bit64s tmp = (newval&1) << bitnum;
  *(val.pbool) &= ~tmp;
  *(val.pbool) |= tmp;
  if (handler) {
    // the handler can override the new value and/or perform some side effect
    (*handler)(this, 1, newval&1);
  }
}

bx_param_enum_c::bx_param_enum_c(bx_param_c *parent,
      char *name,
      char *label,
      char *description,
      char **choices,
      Bit64s initial_val,
      Bit64s value_base)
  : bx_param_num_c(parent, name, label, description, value_base, BX_MAX_BIT64S, initial_val)
{
  set_type(BXT_PARAM_ENUM);
  this->choices = choices;
  // count number of choices, set max
  char **p = choices;
  while (*p != NULL) p++;
  this->min = value_base;
  // now that the max is known, replace the BX_MAX_BIT64S sent to the parent
  // class constructor with the real max.
  this->max = value_base + (p - choices - 1);
  set(initial_val);
}

int bx_param_enum_c::find_by_name(const char *string)
{
  char **p;
  for (p=&choices[0]; *p; p++) {
    if (!strcmp(string, *p))
      return p-choices;
  }
  return -1;
}

bx_bool bx_param_enum_c::set_by_name(const char *string)
{
  int n = find_by_name(string);
  if (n<0) return 0;
  set(n + min);
  return 1;
}

bx_param_string_c::bx_param_string_c(bx_param_c *parent,
    char *name,
    char *label,
    char *description,
    char *initial_val,
    int maxsize)
  : bx_param_c(SIM->gen_param_id(), name, description)
{
  set_type(BXT_PARAM_STRING);
  this->label = label;
  if (maxsize < 0) 
    maxsize = strlen(initial_val) + 1;
  this->val = new char[maxsize];
  this->initial_val = new char[maxsize];
  this->handler = NULL;
  this->enable_handler = NULL;
  this->maxsize = maxsize;
  strncpy(this->val, initial_val, maxsize);
  strncpy(this->initial_val, initial_val, maxsize);
  this->options = new bx_param_num_c(NULL,
      "stringoptions", NULL, NULL, 0, BX_MAX_BIT64S, 0);
  set(initial_val);
  if (parent) {
    BX_ASSERT(parent->get_type() == BXT_LIST);
    this->parent = (bx_list_c *)parent;
    this->parent->add(this);
  }
}

bx_param_filename_c::bx_param_filename_c(bx_param_c *parent,
    char *name,
    char *label,
    char *description,
    char *initial_val,
    int maxsize)
  : bx_param_string_c(parent, name, label, description, initial_val, maxsize)
{
  get_options()->set(IS_FILENAME);
}

bx_param_string_c::~bx_param_string_c()
{
    if ( this->val != NULL )
    {
        delete [] this->val;
        this->val = NULL;
    }
    if ( this->initial_val != NULL )
    {
        delete [] this->initial_val;
        this->initial_val = NULL;
    }

    if ( this->options != NULL )
    {
        delete [] this->options;
        this->options = NULL;
    }
}

void bx_param_string_c::reset() {
  strncpy(this->val, this->initial_val, maxsize);
}

void bx_param_string_c::set_handler(param_string_event_handler handler)
{
  this->handler = handler; 
  // now that there's a handler, call set once to run the handler immediately
  //set (getptr ());
}

void bx_param_string_c::set_enable_handler(param_enable_handler handler)
{ 
  this->enable_handler = handler; 
}

void bx_param_string_c::set_enabled(int en)
{
  // The enable handler may wish to allow/disallow the action
  if (enable_handler) {
    en = (*enable_handler)(this, en);
    }
  bx_param_c::set_enabled(en);
}

Bit32s bx_param_string_c::get(char *buf, int len)
{
  if (options->get() & RAW_BYTES)
    memcpy(buf, val, len);
  else
    strncpy(buf, val, len);
  if (handler) {
    // the handler can choose to replace the value in val/len.  Also its
    // return value is passed back as the return value of get.
    (*handler)(this, 0, buf, len);
  }
  return 0;
}

void bx_param_string_c::set(const char *buf)
{
  if (options->get() & RAW_BYTES)
    memcpy(val, buf, maxsize);
  else {
    strncpy(val, buf, maxsize);
    val[maxsize - 1] = 0;
  }
  if (handler) {
    // the handler can return a different char* to be copied into the value
    buf = (*handler)(this, 1, buf, -1);
  }
}

bx_bool bx_param_string_c::equals(const char *buf)
{
  if (options->get() & RAW_BYTES)
    return (memcmp(val, buf, maxsize) == 0);
  else
    return (strncmp(val, buf, maxsize) == 0);
}

void bx_param_string_c::set_initial_val(char *buf) { 
  if (options->get() & RAW_BYTES)
    memcpy(initial_val, buf, maxsize);
  else
    strncpy(initial_val, buf, maxsize);
  set(initial_val);
}

bx_list_c::bx_list_c(bx_param_c *parent, int maxsize)
  : bx_param_c(SIM->gen_param_id(), "list", "")
{
  set_type(BXT_LIST);
  this->size = 0;
  this->maxsize = maxsize;
  this->list = new bx_param_c*  [maxsize];
  this->parent = NULL;
  if (parent) {
    BX_ASSERT(parent->get_type() == BXT_LIST);
    this->parent = (bx_list_c *)parent;
    this->parent->add(this);
  }
  init("");
}

bx_list_c::bx_list_c(bx_param_c *parent, char *name, char *title,
    int maxsize)
  : bx_param_c(SIM->gen_param_id(), name, "")
{
  set_type (BXT_LIST);
  this->size = 0;
  this->maxsize = maxsize;
  this->list = new bx_param_c*  [maxsize];
  this->parent = NULL;
  if (parent) {
    BX_ASSERT(parent->get_type() == BXT_LIST);
    this->parent = (bx_list_c *)parent;
    this->parent->add(this);
  }
  init(title);
}

bx_list_c::bx_list_c(bx_param_c *parent, char *name, char *title, bx_param_c **init_list)
  : bx_param_c(SIM->gen_param_id(), name, "")
{
  set_type(BXT_LIST);
  this->size = 0;
  while (init_list[this->size] != NULL)
    this->size++;
  this->maxsize = this->size;
  this->list = new bx_param_c*  [maxsize];
  for (int i=0; i<this->size; i++)
    this->list[i] = init_list[i];
  this->parent = NULL;
  if (parent) {
    BX_ASSERT(parent->get_type() == BXT_LIST);
    this->parent = (bx_list_c *)parent;
    this->parent->add(this);
  }
  init(title);
}

bx_list_c::~bx_list_c()
{
    if (this->list)
    {
        delete [] this->list;
        this->list = NULL;
    }
    if ( this->title != NULL)
    {
        delete this->title;
        this->title = NULL;
    }
    if (this->options != NULL)
    {
        delete this->options;
        this->options = NULL;
    }
    if ( this->choice != NULL )
    {
        delete this->choice;
        this->choice = NULL;
    }
}

void bx_list_c::init(const char *list_title)
{
  // the title defaults to the name
  this->title = new bx_param_string_c(NULL,
      "list_title",
      "", "",
      get_name(), 80);
  if ((list_title != NULL) && (strlen(list_title) > 0)) {
    this->title->set((char *)list_title);
  }
  this->options = new bx_param_num_c(NULL,
      "list_option", "", "", 0, BX_MAX_BIT64S,
      0);
  this->choice = new bx_param_num_c(NULL,
      "list_choice", "", "", 0, BX_MAX_BIT64S,
      1);
}

void bx_list_c::set_parent(bx_param_c *newparent) { 
  if (parent) {
    // if this object already had a parent, the correct thing
    // to do would be to remove this object from the parent's
    // list of children.  Deleting children is currently
    // not supported.
    BX_PANIC(("bx_list_c::set_parent: changing from one parent to another is not supported"));
  }
  if (newparent) {
    BX_ASSERT(newparent->get_type() == BXT_LIST);
    this->parent = (bx_list_c *)newparent;
    this->parent->add(this);
  }
}

bx_list_c* bx_list_c::clone()
{
  bx_list_c *newlist = new bx_list_c(NULL, name, title->getptr(), maxsize);
  for (int i=0; i<get_size(); i++)
    newlist->add(get(i));
  newlist->get_options()->set(options->get());
  return newlist;
}

void bx_list_c::add(bx_param_c *param)
{
  if (this->size >= this->maxsize)
    BX_PANIC(("add param '%s' to bx_list_c '%s': list capacity exceeded",
              param->get_name(), get_name()));
  list[size] = param;
  size++;
}

bx_param_c* bx_list_c::get(int index)
{
  BX_ASSERT(index >= 0 && index < size);
  return list[index];
}

bx_param_c* bx_list_c::get_by_name(const char *name)
{
  int i, imax = get_size();
  for (i=0; i<imax; i++) {
    bx_param_c *p = get(i);
    if (0 == strcmp (name, p->get_name())) {
      return p;
    }
  }
  return NULL;
}

void bx_list_c::reset()
{
  int i, imax = get_size();
  for (i=0; i<imax; i++) {
    get(i)->reset();
  }
}
