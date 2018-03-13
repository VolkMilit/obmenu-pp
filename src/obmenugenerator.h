#include <iostream>
#include <vector>
#include <regex>
#include <experimental/filesystem>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "inih.h"
#include "config.h"

namespace fs = std::experimental::filesystem;

class obmenugenerator final
{
	public:
	obmenugenerator();
	~obmenugenerator();
	
	const std::string catIcon(const std::string &category);
	std::string getIcon(std::string icon);
	void element(const std::string &icon, const std::string &name, const std::string &exec);
	void pipe(const std::string &icon, const std::string &name, const std::string &exec);
	void xmlmenu(const std::string &menu, const std::string &icon, const std::string &name);	
	
	std::string HOME;
	std::string THEME;
	
	private:
	const std::string getHome();
	const std::string getTheme();
};
