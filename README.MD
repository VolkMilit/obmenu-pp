# OpenBox menu generator using (some) C++14
suuuuuuucks

#### config.h
You can configure some thing in config.h, ofc you need to recompile every time you do that.
In bin/lastobmenu you can configure which program will be ignored.

#### custom-generator
With this tool you can generate menu.

	``` bash
		custom-generator schema -pipe # to create pipe menu
		custom-generator schema -xml # to create xml menu
	```
	
All xml menus must be in $HOME/.config/obmenu-generator-pp. In config.h under USER_DEFINE:

	``` cpp
		/*
			1 argument - menu file (for example shutdown.xml is shutdown)
			2 argument - menu icon
			3 argument - menu name
		*/
		menu.xmlmenu("shutdown", menu.catIcon("Shutdown"), "Shutdown");
		
		/*
			1 argument - menu icon
			2 argument - menu name
			3 argument - executable pipe
		*/
		menu.pipe(menu.getIcon("steam"), "Steam", "steam-pipe");
	```

#### build
``` bash
	mkdir build && cd build
	mkdir install
	cmake .. 
	# or 
	cmake .. -DCMAKE_INSTALL_PREFIX=${PWD}/install
	make -j$(nproc)
	make install # optional
```

#### todo
- Still need to generate ignored lastes files.
