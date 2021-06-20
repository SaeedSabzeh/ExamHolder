#include "student.h"
int student::num_stu = 0;

student::student(std::string FF, std::string LL, std::string UU, std::string PP, int NN)
	:first_name{ FF }, last_name{ LL }, user_name{ UU }, password{ PP }, stu_number{ NN } {
	++num_stu;
}
student::student(std::string FF, std::string LL, int NN)
	: first_name{ FF }, last_name{ LL }, user_name{ std::to_string(NN) }, password{ std::to_string(NN) }, stu_number{ NN } {
	++num_stu;
}
student::~student() {
	--num_stu;
}
