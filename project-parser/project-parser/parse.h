#ifndef project_parser_parse_h
#define project_parser_parse_h

#include <project-parser/so_support.h>
#include <project-parser/ap_proj.h>

#ifdef __cplusplus
extern "C" {
#endif


  /// Initialize the data structure.
  /// return An initilized data structure.
  AP_API ap_proj_t ap_init();
  /// Return resources to the system and return data structure to initialized, free state.
  /// @param p Pointer to the proj object.
  AP_API void ap_free(ap_proj_t* p);

  /// Load a project file.
  /// @param p Pointer to a previously initiliazed proj object. If the object contains data, it is free'd before the load.
  /// @param path  Location of the project file.
  /// @return 0 for success, other value for error.
  AP_API int ap_load(ap_proj_t* p, const char* path);


#ifdef __cplusplus
}  // extern "C"
#endif



#endif
