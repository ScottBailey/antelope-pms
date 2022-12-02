#include <project-parser/parse.h>
#include <stdio.h>

int main(int argc, char** argv) {

  if(argc < 2)
    return 0;

  for(int i=1; i < argc; ++i) {

    ap_proj_t proj = ap_init();
    int result = ap_load(&proj, argv[i]);
    if(result) {
      printf("Fail %s %d\n", argv[i], result);
    }
    ap_free(&proj);
  }

  return 0;
}
