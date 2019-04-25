cmake_minimum_required(VERSION 3.8)

#Project config
set(PROJECT_NAME "helloworld_cli")
if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
  project(${PROJECT_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
  project(${PROJECT_NAME} VERSION 0.0.1)
endif()


#Packages
set (GTEST_ROOT /usr/src/gtest)
set (GTEST_LIBRARY /usr/src/gtest/libgtest.a)
set (GTEST_MAIN_LIBRARY /usr/src/gtest/libgtest_main.a)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(
    ../include
    ${GTEST_INCLUDE_DIRS}
)

#Configure
configure_file(version.h.in version.h)

#Targets
add_executable(application helloworld.cpp)
add_library(static_library lib.cpp)
add_executable(test_version test_version.cpp)



#Compilation setings
set_target_properties(application static_library test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra;--std=c++17;"
)
set_target_properties(test_version PROPERTIES
    INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIR}
)


#Linking
target_link_libraries(application)
target_link_libraries(test_version
    ${GTEST_LIBRARIES}
    Threads::Threads
)

#Install
install(TARGETS application RUNTIME DESTINATION bin)


#CPack
set (CPACK_GENERATOR DEB)
set (CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT vsuvorov1996@gmail.com)
include(CPack)


#Testing
enable_testing()
add_test(test_version test_version)
