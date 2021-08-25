#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Darknet::dark" for configuration "Debug"
set_property(TARGET Darknet::dark APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Darknet::dark PROPERTIES
  IMPORTED_IMPLIB_DEBUG "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknetd.lib"
  IMPORTED_LOCATION_DEBUG "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknetd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS Darknet::dark )
list(APPEND _IMPORT_CHECK_FILES_FOR_Darknet::dark "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknetd.lib" "D:/test/Yolo-Fastest-master1/Yolo-Fastest-master/darknetd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
