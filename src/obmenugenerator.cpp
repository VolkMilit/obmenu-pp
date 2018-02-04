#include "obmenugenerator.h"

obmenugenerator::obmenugenerator()
{
		this->HOME = this->getHome();
		this->THEME = this->getTheme();
}

obmenugenerator::~obmenugenerator()
{}

const std::string obmenugenerator::getHome()
{
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;
	
	return std::string(homedir);
}

const std::string obmenugenerator::getTheme()
{
		std::string theme = "";
		inih ini(getHome() + "/.gtkrc-2.0");
		
		theme = ini.Get("gtk-icon-theme-name");
		
		if (!theme.empty())
			return std::regex_replace(theme, std::regex("\""), "");
		
		return "";
}

const std::string obmenugenerator::catIcon(const std::string &category)
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

std::string obmenugenerator::getIcon(std::string icon)
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

void obmenugenerator::element(const std::string &icon, const std::string &name, const std::string &exec)
{
	std::cout << "  <item icon='" << this->getIcon(icon) << "' label='" << name << "'><action name='Execute'>" << std::endl
							<< "      <execute>" << exec << "</execute>" << std::endl
							<< "  </action> </item>"
							<< std::endl;
}

void obmenugenerator::pipe(const std::string &icon, const std::string &name, const std::string &exec)
{
		std::cout << "<menu id='" << std::rand() << "' icon='" << icon << "' label='" << name << "' execute=\"/bin/sh -c '" << exec << "'\"/>" << std::endl;
}
