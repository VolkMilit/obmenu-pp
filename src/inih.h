#ifndef __INI_H__
#define __INI_H__

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <vector>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class inih
{
		public:
			inih(const std::string &f);
			~inih();
			
			const std::string Get(const std::string &str);
			std::vector<std::string> split(const std::string &s, char delim);
			
		private:
			std::string file;
};

#endif /* __INI_H__ */
