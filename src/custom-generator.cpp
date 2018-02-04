#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/stat.h>

#include "obmenugenerator.h"
#include "inih.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " schema-file" << std::endl;
		return -1;
	}
		
	obmenugenerator menu;
	inih ini("");
	
	std::string str;
	
	std::ifstream in(argv[1]);
	std::ofstream out;
	out.open(std::string(argv[1]) + "-pipe");
	
	out << "#!/bin/sh\n";
	out << "\n";
	out << "element()\n";
	out << "{\n";
	out << "	echo \"<item icon='$1' label='$2'><action name='Execute'><execute>$3</execute></action></item>\"\n";
	out << "}\n";
	out << "\n";
	out << "echo \"<openbox_pipe_menu>\"\n";
	
	while(getline(in, str))
	{
		std::vector<std::string> tmp = ini.split(str, ':');		
		out << "element \"" + menu.getIcon(tmp[2]) + "\" \"" + tmp[1] + "\" \"" + tmp[3] + "\"\n";
	}
	
	out << "echo \"</openbox_pipe_menu>\"";
	out.close();
	
	const std::string &file = std::string(argv[1]) + "-pipe";
	chmod(file.c_str(), 0744);

	return 0;
}
