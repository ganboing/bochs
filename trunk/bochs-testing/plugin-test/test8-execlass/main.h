#if defined(WIN32) || defined(__CYGWIN__)
#  ifdef MAIN_DLL_EXPORT
#    ifdef DLL_EXPORT
#      warning I will export DLL symbols for MODULE1
#      define MAINAPI(type) __declspec(dllexport) type
#    endif
#  else
#    warning I will import DLL symbols for MODULE1
#    define MAINAPI(type) __declspec(dllimport) type
#  endif
#endif
#ifndef MAINAPI
#  warning No DLL import/export is needed
#  define MAINAPI(type) type
#endif

typedef void (*modload_func)(void);

MAINAPI(extern const char *) version_string;
MAINAPI(extern int) register_module (const char *name);

// really, this should only be included in the modules.  It would be
// incorrect to call module_init from main, even if the compiler allowed
// you to.
extern "C" {
  // this prevents C++ name mangling
  void module_init ();
};

class Widget {
  int id;
  const char *name;
  float weight;
public:
  Widget(int id, const char* name, float weight);
  int getId ();
  const char* getName ();
  float getWeight ();
  void print (FILE*);
};

#define MAX_WIDGETS 10
extern Widget* widgets[MAX_WIDGETS];
