#include "io.h"
#include <iostream>
#include <limits>

bool bekhan_adad(int& n) {
	while (true) {
		if (std::cin >> n) {
			return true;
		}
		n = 0;
		if (std::cin.eof()) {
			return false;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "adad vared konid!" << std::endl;
		std::cout << "->";
	}
}
