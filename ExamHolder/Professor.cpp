#include "Professor.h"
#include <vector>
 int Professor::num_pro = 0;
Professor::Professor(std::string FF, std::string LL, std::string UU, std::string PP)
	:first_name{ FF }, last_name{ LL }, user_name{ UU }, password{ PP } {
	++num_pro;
}
Professor::~Professor() {
	--num_pro;
}

int Professor::get_num_pro() {
	return num_pro;
}

