#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Numb.h"

using namespace std;

int search(Numb*);

int main(int argc, char *argv[])
{

int n;
printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

if (argc==2) {n=atoi(argv[1]);}
else {printf("# ERROR: Number value is not exists. \nPlease enter a new value: "); scanf("%d", &n);}

if (n>999999) {printf("# ERROR: Number value is too large. \nPlease enter a new value: "); scanf("%d", &n);}

Numb* numb1=new Numb(n);

printf("\n# LOADED NUMBER: \n");
numb1->desc();

search(numb1);

delete numb1;

printf("\n\nAuthor: Aleksy Bernat, 226023\n");
printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

}

int search(Numb* numb1)
{

int startTime=clock();
int endTime;
int workTime;
Numb* numbR=new Numb(0);
Numb* numbK=new Numb(0);

printf("\n\n# SEARCHING...\n");
int k=1; //to bedzie czynnik przez ktory trzeba pomnozyc aby otrzymac liczbe z samych 0 i 1
int n=numb1->val();
int result;
int ctr, loop=0; //licznik cyfr i licznik petli
int brk=1; //zmienna wyrzucajaca z petli jak trzeba
int lastDigit;

//dopoki nie zliczymy szesciu zer lub jedynek to szukamy (najpierw sprawdzana jest jedynka)


	loop++; //licznik petli inkrementujemy, bo powyzsza operacja rowniez jest poszukiwaniem czynnika
	result=n*k;
	numbR->getVal(result);
	ctr=numbR->scanDigits();
//okazuje sie ze dla odpowiednich cyfr wystarczy sprawdzac co dziesiata, odpowiednia liczbe,
//wiec jesli jeden nie spelnia wymagan to szukamy nastepnych:
if (ctr!=6)
{
	lastDigit=numb1->showDigit(6);  //zapisujemy szosta cyfre
	switch (lastDigit)
	{
		case 0: k=7; break;
		case 1: k=11; break;  //jedynka byla juz sprawdzona, wiec o 10 wieksza
		case 2: k=5; break;
		case 3: k=7; break;
		case 4: k=5; break;
		case 5: k=2; break;  //tutaj bedzie wyjatek, trzeba brac parzyste k (pieta achillesowa algorytmu)
		case 6: k=5; break;
		case 7: k=3; break;
		case 8: k=5; break;
		case 9: k=9; break;
		default: k=-1; break;
	}
if (lastDigit!=5)
{
	while(ctr!=6)
	{
		result=n*k;

		brk=numbR->getVal(result);
		if (brk==0) break;
		ctr=numbR->scanDigits();
		loop++;
		if (ctr!=6) k+=10;  //co dziesiata liczba!
	}
}
else
	while(ctr!=6)
	{
		result=n*k;
		
		brk=numbR->getVal(result);
		if (brk==0) break;
		ctr=numbR->scanDigits();
		loop++;
		if (ctr!=6) k+=2;  //dla piatki co druga liczba!

	}
}

numbK->getVal(k);

endTime=clock();
workTime=endTime-startTime;

printf("\n# RESULTS:\n\n");
printf("  #>  Found factor: \n      ");
if (brk==1)
{
	numbK->desc();
	printf("\n  #>  Result of multiplication %d by %d: \n      ", n, k);
	numbR->desc();
	printf("\n");
}
 else printf("Unfortunately, searching aborted. The number is too long.\n");
printf("  #>  Loops: %d\n  #>  Searching time: %d [ms]\n", loop, workTime);
delete numbR, numbK;
}