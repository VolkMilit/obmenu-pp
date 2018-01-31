/*
 * leave all hope, if you see this code, you will probably die, you was been warned
 */

#include <vector>
#include <regex>
#include <experimental/filesystem>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "config.h"
#include "inih.h"

namespace fs = std::experimental::filesystem;

// global
std::string THEME;
std::string HOME;

// macros		
#define MNAME std::string name = ini.Get("Name[en_GB]"); \
						   if (name.empty()) name = ini.Get("Name");

const std::string getHome()
{
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;
	
	return std::string(homedir);
}

const std::string getTheme()
{
		std::string theme = "";
		inih ini(getHome() + "/.gtkrc-2.0");
		
		theme = ini.Get("gtk-icon-theme-name");
		
		if (!theme.empty())
			return std::regex_replace(theme, std::regex("\""), "");
		
		return "";
}

const std::string catIcon(const std::string &category)
{
		std::string icon = "";
		//std::vector<std::string> paths = CAT_ICONS_PATHS;
		const std::string &i = CAT_ICONS_PATHS;
		
		//for (auto & i:paths)
		//{
			if (category == "AudioVideo")
			{
				icon = i + "applications-multimedia.svg";
				//break;
			}
				
			if (category ==  "Development")
			{
				icon = i + "applications-development.svg";
				//break;
			}
					
			if (category ==  "Game")
			{
				icon = i + "applications-games.svg";
				//break;
			}
				
			if (category ==  "Graphics")
			{
				icon = i + "application-graphics.svg";
				//break;
			}
				
			if (category ==  "Network")
			{
				icon = i + "applications-internet.svg";
				//break;
			}
					
			if (category ==  "Office")
			{
				icon = i + "applications-office.svg";
				//break;
			}
					
			if (category ==  "Settings")
			{
				icon = i + "applications-system.svg";
				//break;
			}
					
			if (category ==  "System")
			{
				icon = i + "applications-system.svg";
				//break;
			}
				
			if (category ==  "Utility")
			{
				icon = i + "applications-utilities.svg";
				//break;
			}
			
			if (category == "Shutdown")
			{
				icon = i + "preferences-tweaks-anim.svg";
				//break;
			}
		//}
		
		return icon;
}

std::string getIcon(std::string icon)
{
		if (icon == "")
			return "";

		std::vector<std::string> paths = ICONS_PATHS;
	
		if (!fs::exists(icon))
		{
			for (auto & i:paths)
			{
				if (fs::exists(i + ".svg"))
				{
					icon = i + ".svg";
					break;
				}
				else if (fs::exists(i + ".png"))
				{
					icon = i + ".png";
					break;
				}
				/*else if (fs::exists(i + ".xpm"))
				{	
					icon = i + ".xpm";
					break;
				}*/
				else if (fs::exists(i))
				{
					icon = i;
					break;
				}
				else
				{
					icon = MISSING;
				}
			}
		}
		
		return icon;
}

const void element(const std::string &icon, const std::string &name, const std::string &exec)
{
	std::cout << "  <item icon='" << getIcon(icon) << "' label='" << name << "'><action name='Execute'>" << std::endl
							<< "      <execute>" << exec << "</execute>" << std::endl
							<< "  </action> </item>"
							<< std::endl;
}

const void pipe(const std::string &icon, const std::string &name, const std::string &exec)
{
		std::cout << "<menu id='" << std::rand() << "' icon='" << icon << "' label='" << name << "' execute=\"/bin/sh -c '" << exec << "'\"/>" << std::endl;
}

int main()
{
	THEME = getTheme();
	HOME = getHome();
	
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
			std::ifstream is(HOME + "/.cache/obmenupp-last");
			std::string str;
	
			while(getline(is, str))
			{
				lineCount += 1;
				if (!fs::exists(str)) continue;
		
				inih ini(str);
        
				MNAME
			
				if (name.length() >= 15)
					name = name.erase(15, name.length()) + " ...";
														 
				element( \
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
		std::cout << "<menu icon='" << catIcon(i) << "' id='" << std::rand() << "' label='" << trans[transI] << "'>" << std::endl;
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
						element( \
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
	
	const std::string &shut = getIcon("shutdown");
	
	std::cout << "<menu icon='" << catIcon("Shutdown") << "' id='" << std::rand() << "' label='Выключение'>" << std::endl;
	element(shut, "Суспенд", "sudo pm-suspend");
	element(shut, "Перезагрузка", "sudo reboot");
	element(shut, "Выключение", "sudo halt");
	element(shut, "Выйти из Openbox", "openbox --exit");
	
	std::cout << "</menu>" << std::endl;

    std::cout << "</openbox_pipe_menu>" << std::endl;
    
    return 0;
}
