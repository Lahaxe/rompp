find_package(Log4Cpp REQUIRED)

file(GLOB_RECURSE Header_Files "*.h")
file(GLOB_RECURSE Source_Files "*.cpp")
file(GLOB_RECURSE templates "*.txx")

# Regroup files by folder
GroupFiles(Header_Files)
GroupFiles(Source_Files)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${Log4Cpp_INCLUDE_DIRS})

add_library(librompp ${Source_Files} ${Header_Files} ${templates})
set_target_properties(librompp PROPERTIES OUTPUT_NAME rompp)

target_link_libraries(librompp ${Log4Cpp_LIBRARIES})

set_target_properties(librompp PROPERTIES
				 VERSION ${rompp_VERSION}
				 SOVERSION ${rompp_MAJOR_VERSION})
