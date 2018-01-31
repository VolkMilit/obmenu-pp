cmake_minimum_required(VERSION 3.0)
project(obmenugenerator-pp)

file(GLOB_RECURSE sources      src/main.cpp src/inih.cpp src/config.h src/inih.h)
file(GLOB_RECURSE sources_steampipe src/steam-pipe.cpp src/inih.cpp src/config.h src/inih.h)

add_executable(menu ${sources})
add_executable(steam-pipe ${sources_steampipe})

target_compile_options(menu PUBLIC -O2)
target_link_libraries(menu stdc++fs)
target_compile_options(steam-pipe PUBLIC -O2)
target_link_libraries(steam-pipe stdc++fs)
