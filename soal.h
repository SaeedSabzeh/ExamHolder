#pragma once
#include <string>
#include <memory>
#include <vector>
#include <iostream>
class soal
{
protected:
	std::string soorat;
public:
	std::string get_soorat() const { return soorat; }
	virtual void show() const= 0;
	soal(std::string so);
};

class soal_gozine:
	public soal
{
private: 
	std::string yek;
	std::string dow;
	std::string se;
	std::string chahar;
public:
	std::string get_gozine1() { return yek; }
	std::string get_gozine2() { return dow; }
	std::string get_gozine3() { return se; }
	std::string get_gozine4() { return chahar; }
	soal_gozine(std::string so, std::string alef, std::string be, std::string jim, std::string dal);
	virtual void show() const;
};

class soal_truefalse :
	public soal
{
private:
	std::string dorost{ dorost };
	std::string qalat{ qalat };
public:
	soal_truefalse(std::string ss);
	virtual void show() const;
};

class soal_tashrihi :
	public soal
{
public:
	soal_tashrihi(std::string ss);
	virtual void show() const;
};
class azmoon
{
public:
	azmoon(std::string n, int tim)
		:name{ n } ,time {tim} {
	}
	std::string name{ "exam" };
	int tedad_soal = soalat.size();
	std::vector<std::unique_ptr<soal>> soalat{};
	std::string get_name() { return name; }
	std::string set_name(std::string n) { this->name = n; }
	void add_soal();
	std::vector<int> students{};
	std::vector<double> nomreha{};

	int time;

};

