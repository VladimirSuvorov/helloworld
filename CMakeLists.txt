cmake_minimum_required(VERSION 3.2)

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    message(STATUS "TRAVIS_BUILD_NUMBER environment variable is defined")
    project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    message(STATUS "TRAVIS_BUILD_NUMBER environment variable is not defined, set version to 0.0.1")
    project(helloworld VERSION 0.0.1)
endif()


configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

#include(gtest)
add_executable(test_version test_version.cpp)
add_dependencies(test_version googletest)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(helloworld_cli
    helloworld
)

#set(PROJECT_TEST_NAME test_version)
#include_directories(${GTEST_INCLUDE_DIRS})
#file(GLOB_RECURSE TEST_SOURCE_FILES RELATIVE ${PROJECT_SOURCE_DIR} test/*cpp)
#message(STATUS "Test case source files: " ${TEST_SRC_FILES})
#add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
#add_dependencies(${PROJECT_TEST_NAME} googletest)
#add_dependencies(${PROJECT_TEST_NAME} ${PROJECT_NAME})

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vsuvorov1996@gmail.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
