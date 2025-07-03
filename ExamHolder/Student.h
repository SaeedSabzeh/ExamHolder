#pragma once
#include <string>
#include <vector>

class Student {
private:
	std::string first_name;
	std::string last_name;
	std::string user_name;
	std::string password;
	int stu_number;
	static int num_stu;

public:
	Student(std::string first_name , std::string last_name, std::string user_name, std::string password, int stu_number
	);
	static int get_num_stu() { return num_stu; }
	~Student();
};




