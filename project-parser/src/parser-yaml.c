#include <yaml.h>
#include <project-parser/parse.h>
#include <errno.h>

#define nullptr 0

typedef struct ap_detail_s {
  int a;
} ap_detail;



ap_proj_t ap_init() {
  ap_proj_t rv;
  rv. detail = nullptr;
  return rv;
}


void ap_free_detail(ap_detail* p) {
  if(!p)
    return;
}


void ap_free(ap_proj_t* p) {
    if(!p || !p->detail)
      return;

    ap_detail* d = (ap_detail*)(p->detail);
    ap_free_detail(d);
    free(d);
    p->detail = nullptr;
}


int ap_load(ap_proj_t* p, const char* path) {

  // Ensure theres no data loss.
  if(p->detail)
    ap_free(p);

  // Try to open the file.
  FILE* file = fopen(path, "rb");
  if(!file)
    return errno;

  // Initialize the parser.
  yaml_parser_t parser;
  if( !yaml_parser_initialize(&parser) ) {
    fclose(file);
    return -1;
  }
  yaml_parser_set_input_file(&parser,file);

  int rv = 0;
  yaml_document_t doc;
  if(!yaml_parser_load(&parser, &doc)) {
    fclose(file);
    return -2;
  }

  size_t count = 0;
  for(;;) {

    // This gets the root node.
    yaml_node_t* node = yaml_document_get_root_node(&doc);
    if( !node ) {
      printf("The end.\n");
      break;
    }

    ++count;

    switch(node->type) {
      case YAML_NO_NODE:
        printf("YAML_NO_NODE\n");
        break;

      case YAML_SEQUENCE_NODE:
        printf("YAML_SEQUENCE_NODE\n");
        break;

      case YAML_MAPPING_NODE:
        printf("YAML_MAPPING_NODE\n");
        break;

      case YAML_SCALAR_NODE:
        printf("YAML_SCALAR_NODE\n");
    }
  }

  printf("%s %d", path, count);
  yaml_document_delete(&doc);

  yaml_parser_delete(&parser);
  fclose(file);

  return rv;
}
