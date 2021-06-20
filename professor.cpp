#include "professor.h"
#include <vector>
int professor::num_pro = 0;
professor::professor(std::string FF, std::string LL, std::string UU, std::string PP)
	:first_name{ FF }, last_name{ LL }, user_name{ UU }, password{ PP } {
	++num_pro;
}
professor::~professor() {
	--num_pro;
}

int professor::get_num_pro() {
	return num_pro;
}

