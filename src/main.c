#include "repl.h"
#include "eval.h"
#include "../shared/shared.h"

int main(int argc, char **argv) {
  /* printf("%ld %ld %ld \n", sizeof(float), sizeof(int), sizeof(void*)); */
  carp_platform_init();
  obj_total_max = 100000;
  shadow_stack_pos = 0;

  Process *process = process_new();
  
  eval_text(process, process->global_env, "(load-lisp (str (getenv \"CARP_DIR\") \"lisp/boot.carp\"))", false, obj_new_string("main.c"));
  
  /* if(argc == 2) { */
  /*   char load_file[512]; */
  /*   snprintf(load_file, 512, "(load-lisp (str \"%s\"))", argv[1]); */
  /*   eval_text(process, global_env, load_file, false, obj_new_string("main.c")); */
  /* } */

  repl(process);
  carp_platform_shutdown();
  assert(obj_total == 0);
}
