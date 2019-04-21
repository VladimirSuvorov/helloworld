cmake_minimum_required(VERSION 3.6)

#Project config
set(PROJECT_NAME "helloworld_cli")
project(${PROJECT_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
  project(${PROJECT_NAME} VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
  project(${PROJECT_NAME} VERSION 0.0.1)
endif()



#Packages
find_package(GTest REQUIRED)
include_directories(
    ../include
    ${GTEST_INCLUDE_DIRS}
)

#Configure
configure_file(version.h.in version.h)

#Targets
add_executable(application main.cpp)
add_library(static_library lib.cpp)
add_executable(test test_version.cpp)



#Compilation setings
set_target_properties(application static_library test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)
set_target_properties(test PROPERTIES
    INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIR}
)


#Linking
target_link_libraries(application static_library)
target_link_libraries(test_version
    ${GTEST_LIBRARIES}
    static_library
)


#CPack
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT vsuvorov1996@gmail.com)
include(CPack)


#Testing
enable_testing()
add_test(test_version test)
