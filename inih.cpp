#include "inih.h"

inih::inih(const std::string &f)
{
	this->file = f;
}
inih::~inih(){}

std::vector<std::string> inih::split(const std::string &s, char delim) 
{
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;
  
	while (std::getline(ss, item, delim))
		elems.push_back(item);
	
	return elems;
}

const std::string inih::Get(const std::string &str)
{
	std::string s = "";
	std::vector<std::string> ss;
	std::string line = "";
	std::ifstream file (this->file);
	
	std::string tmp = "";
		
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (line.size() > 0 && line.at(0) == '#') continue;
			
			if((line.find(str)) != std::string::npos)
			{
				s = line;
				break;
			}
		}
		file.close();
	}
	
	if (!s.empty())
	{
		try
		{
			ss = split(s, '=');
			s = "";
			
			for (auto i = 1; i < ss.size(); i++)
			{
				if (i > 1 && i < ss.size())
					s += "=";
					
				s += ss.at(i);
			}
		}
		catch(...){s = "";}
	}
	
	return s;
}
