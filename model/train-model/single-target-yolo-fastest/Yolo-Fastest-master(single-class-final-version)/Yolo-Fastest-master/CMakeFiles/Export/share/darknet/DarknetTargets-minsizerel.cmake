#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Darknet::dark" for configuration "MinSizeRel"
set_property(TARGET Darknet::dark APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(Darknet::dark PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknet.lib"
  IMPORTED_LOCATION_MINSIZEREL "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknet.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Darknet::dark )
list(APPEND _IMPORT_CHECK_FILES_FOR_Darknet::dark "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknet.lib" "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknet.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
