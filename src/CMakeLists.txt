find_package(Boost REQUIRED COMPONENTS filesystem system date_time)
find_package(Log4Cpp REQUIRED)
find_package(Qt5Core REQUIRED)

file(GLOB_RECURSE Header_Files "*.h")
file(GLOB_RECURSE Source_Files "*.cpp")
file(GLOB_RECURSE templates "*.txx")

# Regroup files by folder
GroupFiles(Header_Files)
GroupFiles(Source_Files)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${Boost_INCLUDE_DIRS}
                    ${Log4Cpp_INCLUDE_DIRS})

message(STATUS "coucou ${MONGO_DB_INCLUDE_DIRS}")

add_library(librompp ${Source_Files} ${Header_Files} ${templates})
set_target_properties(librompp PROPERTIES OUTPUT_NAME rompp)

target_link_libraries(librompp
                      ${Boost_LIBRARIES}
                      ${Log4Cpp_LIBRARIES})

set_target_properties(librompp PROPERTIES
                      VERSION ${rompp_VERSION}
                      SOVERSION ${rompp_MAJOR_VERSION})

QT5_USE_MODULES(librompp Core)
