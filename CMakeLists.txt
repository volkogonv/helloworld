cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)


# Создает исполняемый файл

add_library(helloworld lib.cpp)	# Создание  библиотеки

add_executable(helloworld_cli main.cpp)

add_executable(test_version test.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDART 14
    CXX_STANDART_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli
    helloworld
)		# Линковка программы с библиотекой

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)


set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vladimir.vlkgn@mail.ru)

include(CPack)

enable_testing()

add_test(test_version test_version)

