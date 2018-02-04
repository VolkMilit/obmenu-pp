/*
 * leave all hope, if you see this code, you will probably die, you was been warned
 */

#include <vector>
#include <regex>
#include <experimental/filesystem>
#include <ctime>

#include "config.h"
#include "inih.h"
#include "obmenugenerator.h"

namespace fs = std::experimental::filesystem;

// macros		
#define MNAME std::string name = ini.Get("Name[en_GB]"); \
						   if (name.empty()) name = ini.Get("Name");

int main()
{
	obmenugenerator menu;
	
    std::srand(std::time(0));
    
    std::vector<std::string> trans = {"Мультимедия", "Разработка", "Игры", "Графика", "Сеть", "Оффис", "Настройки", "Система", "Утилиты"};
    int transI = 0;

    std::vector<std::string> cat = CATEGORIES;
    std::vector<std::string> path = DESKTOP_PATHS;
    std::vector<std::string> a_hide = HIDE;
    bool hide = false;
    
    std::cout << "<openbox_pipe_menu>" << std::endl;
    std::cout << "<separator label=\"OPENBOX MENU\"/>" << std::endl;
    
    USER_DEFINE // see config.h
	std::cout << "<separator/>" << std::endl;
	
	// lastes files
	#if DISPLAY_LASTES == 1
		int lineCount = 0;
		
		//if (!fs::exists(HOME + "/.cache/obmenupp-last"))
		//{
			std::ifstream is(menu.HOME + "/.cache/obmenupp-last");
			std::string str;
	
			while(getline(is, str))
			{
				lineCount += 1;
				if (!fs::exists(str)) continue;
		
				inih ini(str);
        
				MNAME
			
				if (name.length() >= 15)
					name = name.erase(15, name.length()) + " ...";
														 
				menu.element( \
					ini.Get("Icon"), \
					name, \
					std::regex_replace(ini.Get("Exec"), std::regex(" %[A-z]"), "") \
				);
			}
			
			if (lineCount >= 2)
				std::cout << "	<separator/>" << std::endl;
		//}
	#endif
	//------------
    
	for (const auto & i:cat)
	{
		std::cout << "<menu icon='" << menu.catIcon(i) << "' id='" << std::rand() << "' label='" << trans[transI] << "'>" << std::endl;
		transI++;
		
		for (const auto & j:path)
		{
			if (!fs::exists(j)) continue;
			
			for (auto & p : fs::directory_iterator(j))
			{
				inih ini(p.path());
				std::size_t found = ini.Get("Categories").find(i);

				if (found != std::string::npos)
				{
					MNAME
					
					for (auto hh : a_hide)
					{
						if (name == hh) 
						{
							hide = true;
							break;
						}
					}
					
					if (!hide && ini.Get("NoDisplay") != "true")
						menu.element( \
							ini.Get("Icon"), \
							name, \
							"lastobmenu " + std::string(p.path()) + " " + std::regex_replace(ini.Get("Exec"), std::regex(" %[A-z]"), "") \
						);
					
					hide = false;
				}
			}
		}

		std::cout << "</menu>" << std::endl;
	}
	
	std::cout << "<separator />" << std::endl;
	
	menu.pipe(menu.catIcon("Shutdown"), "Выключение", "shutdown-pipe");

    std::cout << "</openbox_pipe_menu>" << std::endl;
    
    return 0;
}
