#pragma once
#include <string>

using namespace std;

class Numb
{
private:

	int _val;
	string _lit;
	int _digits[6];

public:

	Numb(int);
	int val() {return _val;} //aktualna wartosc
	void getVal(int);  //nowa wartosc
	void lit();  //tutaj dzieje sie cala rzecz
	int scanDigits();  //skanowanie cyfr pod wzgledem zer i jedynej
	void desc(); //opis obiektu
};