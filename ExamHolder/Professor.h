#pragma once
#include <string>
class Professor {
private:
	std::string first_name;
	std::string last_name;
	std::string user_name;
	std::string password;
	static int num_pro;
public:
	Professor(std::string first_name, std::string last_name, std::string user_name, std::string password);
	static int get_num_pro();
	~Professor();
};
