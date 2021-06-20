#include "soal.h"
soal::soal(std::string so)
	: soorat{ so } {

}

soal_gozine::soal_gozine(std::string so, std::string alef, std::string be, std::string jim, std::string dal)
	: soal(so), yek{ alef }, dow{ be }, se{ jim }, chahar{ dal }  {
}
void soal_gozine::show() const {
	std::cout << soorat << std::endl;
	std::cout << "1. " << yek <<std::endl;
	std::cout << "2. " << dow << std::endl;
	std::cout << "3. " << se << std::endl;
	std::cout << "4. " << chahar << std::endl;
};
soal_tashrihi::soal_tashrihi(std::string ss)
	:soal(ss) {
}
soal_truefalse::soal_truefalse(std::string ss) 
	:soal(ss) {

}
void soal_tashrihi::show() const {
	std::cout << soorat << std::endl;
}

void soal_truefalse::show() const {
	std::cout << soorat << std::endl;
	std::cout << "1. sahih" << std::endl;
	std::cout << "2. qalat" << std::endl;
};
void azmoon::add_soal() {
	int tedad{ 0 };
	std::cout << "tedad soalati ke mikhahid ezafe konid:\n" << std::endl;
	std::cin >> tedad;
	for (int i = 0; i < tedad; i++) {
		std::cout << "type e soal ra moshakhas mokin: \n 1.chahar gozinei \n 2.tashrihi \n 3.sahih qalat\n " << std::endl;
		int a;
		std::string u,sss, y, d, see, ch;
		std::cin >> a;

		switch (a) {
		case 1:
			getline(std::cin, u);
			std::cout << "soorat soal ra vared konid:\n";
			getline(std::cin, sss);
			std::cout << "gozine 1 ra vared konid:\n";
			getline(std::cin, y);
			std::cout << "gozine 2 ra vared konid:\n";
			getline(std::cin, d);
			std::cout << "gozine 3 ra vared konid:\n";
			getline(std::cin, see);
			std::cout << "gozine 4 ra vared konid:\n";
			getline(std::cin, ch);
			soalat.push_back(std::make_unique<soal_gozine>(sss, y, d, see, ch));
			break;

		case 2:
			getline(std::cin, u);
			std::cout << "soorat soal ra vared konid:\n" << std::endl;
			getline(std::cin, sss);
			soalat.push_back(std::make_unique<soal_tashrihi>(sss));
			break;

		case 3:
			getline(std::cin, u);
			std::cout << "soorat soal ra vared konid:\n" << std::endl;
			getline(std::cin, sss);
			soalat.push_back(std::make_unique<soal_truefalse>(sss));
			break;

		}
	}
}