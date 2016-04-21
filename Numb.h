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
	bool getVal(int);  //nowa wartosc
	void lit();  //tutaj dzieje sie cala rzecz
	int scanDigits();  //skanowanie cyfr pod wzgledem zer i jedynej
	int showDigit(int); //pokaz cyfre numer n
	void desc(); //opis obiektu
};