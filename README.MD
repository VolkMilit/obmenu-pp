# OpenBox menu generator using (some) C++14
suuuuuuucks

#### config.h
You can configure some thing in config.h, ofc you need to recompile every time you do that.
In bin/lastobmenu you can configure which program will be ignored.

#### custom-generator
With this tool you can generate any pipe menu. See example file in common.

#### build
$ mkdir build && cd build

$ mkdir install

$ cmake .. or cmake .. -DCMAKE_INSTALL_PREFIX=${PWD}/install

$ make

$ make install

#### todo
- Still need to generate ignored lastes files.
