
find_package(Boost COMPONENTS filesystem system date_time REQUIRED)
find_package(Log4Cpp REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/
                    ${Boost_INCLUDE_DIRS}
                    ${Log4Cpp_INCLUDE_DIRS})

# Create CAMS-CLI binary
add_executable(read-ini "read-ini.cpp")
target_link_libraries(read-ini
                      ${CMAKE_SOURCE_DIR}/build/src/librompp.a
                      ${Boost_LIBRARIES}
                      ${Log4Cpp_LIBRARIES})

