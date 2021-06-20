#pragma once
#include <string>
#include "soal.h"
class professor {
public:
	std::string first_name;
	std::string last_name;
	std::string user_name;
	std::string password;
	static int num_pro;
	std::vector<std::shared_ptr<azmoon>> azmoonha{};

public:
	professor(std::string first_name, std::string last_name, std::string user_name, std::string password);
	static int get_num_pro();
	~professor();
};
