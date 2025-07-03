#include "Student.h"
int Student::num_stu = 0;

Student::Student(std::string FF, std::string LL, std::string UU, std::string PP, int NN
) :first_name{ FF }, last_name{ LL }, user_name{ UU }, password{ PP }, stu_number{ NN } {
	++num_stu;
}
Student::~Student() {
	--num_stu;
}
