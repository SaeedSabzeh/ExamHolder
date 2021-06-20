#pragma once
#include <string>
#include <vector>
#include "soal.h"
class student {
	friend class professor;
public:
	std::string first_name;
	std::string last_name;
	std::string user_name;
	std::string password;
	int stu_number;
	static int num_stu;
	std::vector<std::shared_ptr<azmoon>> azmoonha{};
	std::vector<std::string> pasokhha{};
public:
	student(std::string FF, std::string LL, std::string UU, std::string PP, int NN);
	student(std::string FF, std::string LL, int NN);
	static int get_num_stu() { return num_stu; }
	~student();
};




