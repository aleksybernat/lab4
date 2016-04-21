#include "Numb.h"

using namespace std;

Numb::Numb(int n)
{
	_val=n;

	int r, l=_val; //r, l - zmienne pomocnicze

	//algorytm zapozyczony, ale tak cudowny! *.*
	r = (l - (l % 100000)); l-=r; r/=100000; _digits[0]=r;
	r = (l - (l % 10000)); l-=r; r/=10000; _digits[1]=r;
	r = (l - (l % 1000)); l-=r; r/=1000; _digits[2]=r;
	r = (l - (l % 100)); l-=r; r/=100; _digits[3]=r;
	r = (l - (l % 10)); l-=r; r/=10; _digits[4]=r;
	r = l; _digits[5]=r;
}


void Numb::lit()
{

	switch (_digits[0])
	{
	case 9: printf("dziewiecset "); break;
	case 8: printf("osiemset "); break;
	case 7: printf("siedemset "); break;
	case 6: printf("szescset "); break;
	case 5: printf("piecset "); break;
	case 4: printf("czterysta "); break;
	case 3: printf("trzysta "); break;
	case 2: printf("dwiescie "); break;
	case 1: printf("sto "); break;
	default: break;
	}

	switch (_digits[1])
	{
	case 9: printf("dziewiecdziesiat "); break;
	case 8: printf("osiemdziesiat "); break;
	case 7: printf("siedemdziesiat "); break;
	case 6: printf("szescdziesiat "); break;
	case 5: printf("piecdziesiat "); break;
	case 4: printf("czterdziesci "); break;
	case 3: printf("trzydziesci "); break;
	case 2: printf("dwadziescia "); break;
	default: break;
	}

	if (_digits[1]==1)
	{
		switch (_digits[2])
		{
		case 9: printf("dziewietnascie "); break;
		case 8: printf("osiemnascie "); break;
		case 7: printf("siedemnascie "); break;
		case 6: printf("szesnascie "); break;
		case 5: printf("pietnascie "); break;
		case 4: printf("czternascie "); break;
		case 3: printf("trzynascie "); break;
		case 2: printf("dwanascie "); break;
		case 1: printf("jedenascie "); break;
		case 0: printf("dziesiec "); break;
		default: break;
		}

	}
	else
	{
		switch (_digits[2])
		{
		case 9: printf("dziewiec "); break;
		case 8: printf("osiem "); break;
		case 7: printf("siedem "); break;
		case 6: printf("szesc "); break;
		case 5: printf("piec "); break;
		case 4: printf("cztery "); break;
		case 3: printf("trzy "); break;
		case 2: printf("dwa "); break;
		default: break;
		}

		if (_digits[0] || _digits[1]) if(_digits[2]==1) printf("jeden ");
	}

	if (!_digits[0] && !_digits[1] && _digits[2]==1) printf("tysiac ");
	else
	{
		if (_digits[1]!=1)
		{
		switch (_digits[2])
		{
		case 9: printf("tysiecy "); break;
		case 8: printf("tysiecy "); break;
		case 7: printf("tysiecy "); break;
		case 6: printf("tysiecy "); break;
		case 5: printf("tysiecy "); break;
		case 4: printf("tysiace "); break;
		case 3: printf("tysiace "); break;
		case 2: printf("tysiace "); break;
		case 1: printf("tysiecy "); break;
		}
		}
		else
		{
		printf("tysiecy ");
		}
	}


	switch (_digits[3])
	{
	case 9: printf("dziewiecset "); break;
	case 8: printf("osiemset "); break;
	case 7: printf("siedemset "); break;
	case 6: printf("szescset "); break;
	case 5: printf("piecset "); break;
	case 4: printf("czterysta "); break;
	case 3: printf("trzysta "); break;
	case 2: printf("dwiescie "); break;
	case 1: printf("sto "); break;
	default: break;
	}

	switch (_digits[4])
	{
	case 9: printf("dziewiecdziesiat "); break;
	case 8: printf("osiemdziesiat "); break;
	case 7: printf("siedemdziesiat "); break;
	case 6: printf("szescdziesiat "); break;
	case 5: printf("piecdziesiat "); break;
	case 4: printf("czterdziesci "); break;
	case 3: printf("trzydziesci "); break;
	case 2: printf("dwadziescia "); break;
	default: break;
	}
	if (_digits[4]==1)
	{
		switch (_digits[5])
		{
		case 9: printf("dziewietnascie "); break;
		case 8: printf("osiemnascie "); break;
		case 7: printf("siedemnascie "); break;
		case 6: printf("szesnascie "); break;
		case 5: printf("pietnascie "); break;
		case 4: printf("czternascie "); break;
		case 3: printf("trzynascie "); break;
		case 2: printf("dwanascie "); break;
		case 1: printf("jedenascie "); break;
		case 0: printf("dziesiec "); break;
		default: break;
		}
	}
	else
	{
		switch (_digits[5])
		{
		case 9: printf("dziewiec "); break;
		case 8: printf("osiem "); break;
		case 7: printf("siedem "); break;
		case 6: printf("szesc "); break;
		case 5: printf("piec "); break;
		case 4: printf("cztery "); break;
		case 3: printf("trzy "); break;
		case 2: printf("dwa "); break;
		case 1: printf("jeden "); break;
		default: break;
		}
	}
	if (_digits[0]==0 && _digits[1]==0 && _digits[2]==0 && _digits[3]==0 && _digits[4]==0 && _digits[5]==0) printf("zero ");
}

void Numb::desc()
{
	printf("[ %-6d, ", _val); lit(); printf("]");
}

bool Numb::getVal(int n)
{
	if (n<1000000)
	{
		_val=n;
		int r, l=_val; //r, l - zmienne pomocnicze

	//znow cudowny algorytm *.*
	r = (l - (l % 100000)); l-=r; r/=100000; _digits[0]=r;
	r = (l - (l % 10000)); l-=r; r/=10000; _digits[1]=r;
	r = (l - (l % 1000)); l-=r; r/=1000; _digits[2]=r;
	r = (l - (l % 100)); l-=r; r/=100; _digits[3]=r;
	r = (l - (l % 10)); l-=r; r/=10; _digits[4]=r;
	r = l; _digits[5]=r;
	return true;
	}
	else 
	{
		printf("\n# ERROR(Numb): New value is too large. Unsuccesful initioalization.\n");
		return false;
	}
}

int Numb::scanDigits()
{
	int ctr=0;
	for(int i=0; i<6; i++)
	{
		if (_digits[i]==0 || _digits[i]==1) ctr++;
	}
	return ctr;
}

int Numb::showDigit(int n)
{
	if (n>0 && n<7) return _digits[n-1];
	else return -1;
}