#include <vector>
#include <experimental/filesystem>

#include "inih.h"
#include "config.h"

namespace fs = std::experimental::filesystem;

std::string THEME;
std::string HOME;

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

int main()
{
	THEME = getTheme();
	HOME = getHome();
	
	const std::string &STEAM_ICON = getIcon("steam");
	
	std::cout << "<openbox_pipe_menu>" << std::endl;
	element(STEAM_ICON, "Steam", "steam-wrapper 0");
	element(STEAM_ICON, "Steam (wine 2.18.0)", "steam-wrapper 1");
	element(STEAM_ICON, "Steam (wine)", "steam-wrapper 2");
	element(STEAM_ICON, "Steam (wine 32)", "steam-wrapper 4");
	element("/media/drive1/games/wine_prefix/.wine64/drive_c/Program Files (x86)/Ubisoft/Ubisoft Game Launcher/Uplay-icon.png", "Uplay", "steam-wrapper 3");
	std::cout << "</openbox_pipe_menu>" << std::endl;

	return 0;
}
