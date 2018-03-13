#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/stat.h>

#include "obmenugenerator.h"
#include "inih.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Usage: " << argv[0] << " schema-file [-pipe] [-xml]" << std::endl;
		return -1;
	}
		
	obmenugenerator menu;
	inih ini("");
	
	std::string str;
	
	std::ifstream in(argv[1]);
	std::ofstream out;
	
	if (std::string(argv[2]) == "-pipe")
	{
		std::cout << argv[2] << std::endl;
		
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
	
		const std::string &file = std::string(argv[1]) + "-pipe";
		chmod(file.c_str(), 0744);
	}
	else if (std::string(argv[2]) == "-xml")
	{
		std::cout << argv[2] << std::endl;
		
		out.open(std::string(argv[1]) + ".xml");
		
		while(getline(in, str))
		{
			std::vector<std::string> tmp = ini.split(str, ':');
			out << "<item icon='" + menu.getIcon(tmp[2]) + "' label='" + tmp[1] + "'>" << std::endl;
			out << "	<action name='Execute'>" << std::endl;
			out << "		" + tmp[3] << std::endl;
			out << "	</action>" << std::endl;
			out << "</item>" << std::endl;
			out << std::endl;
		}
	}
	else
	{
		return -1;
	}
	
	out.close();
	
	return 0;
}
