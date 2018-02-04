cmake_minimum_required(VERSION 3.0)
project(obmenugenerator-pp)

file(GLOB_RECURSE sources      src/main.cpp src/config.h src/inih.cpp src/inih.h src/obmenugenerator.h src/obmenugenerator.cpp)
file(GLOB_RECURSE sources_customgenerator src/custom-generator.cpp src/obmenugenerator.h src/obmenugenerator.cpp src/config.h src/inih.cpp src/inih.h)

add_executable(menu ${sources})
add_executable(custom-generator ${sources_customgenerator})

target_compile_options(menu PUBLIC -O2 -std=c++14)
target_link_libraries(menu stdc++fs)
target_compile_options(custom-generator PUBLIC -O2 -std=c++14)
target_link_libraries(custom-generator stdc++fs)

include(GNUInstallDirs)

install(TARGETS menu
	DESTINATION "usr/${CMAKE_INSTALL_BINDIR}" COMPONENT prog)
	install(TARGETS custom-generator
	DESTINATION "usr/${CMAKE_INSTALL_BINDIR}" COMPONENT prog)
install(FILES "${PROJECT_SOURCE_DIR}/bin/lastobmenu"
	DESTINATION "usr/${CMAKE_INSTALL_BINDIR}" COMPONENT prog)
