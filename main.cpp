#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "Numb.h"

using namespace std;

int search(Numb*);

int main(int argc, char *argv[])
{

int n;

if (argc==2) {n=atoi(argv[1]);}
else {printf("# ERROR: Number value is not exists. \nPlease enter a new value: "); scanf("%d", &n);}

if (n>999999) {printf("# ERROR: Number value is too large. \nPlease enter a new value: "); scanf("%d", &n);}

Numb* numb1=new Numb(n);

printf("\n");
numb1->desc();
printf("\n\n");

search(numb1);

delete numb1;
}

int search(Numb* numb1)
{

Numb* numbR=new Numb(0);
Numb* numbK=new Numb(0);

int k=0; //to bedzie czynnik przez ktory trzeba pomnozyc aby otrzymac liczbe z samych 0 i 1
int n=numb1->val();
int result;
int ctr, loop=0; //licznik cyfr i licznik petli

//POMYSLEC NAD LEPSZYM ALGORYTMEM!!!!

//if (numbK->scanDigits()!=6)
{
while(ctr!=6) //dopoki nie zliczymy szesciu zer lub jedynek to szukamy
{
	k++;
	result=n*k;
	numbR->getVal(result);
	ctr=numbR->scanDigits();
	loop++;
}
}

numbK->getVal(k);

printf("Result of searching a required factor to product:\n\n");
printf("Loops: %d\nFound factor: ", loop);
numbK->desc();
printf("\nResult of multiplication %d by %d:", n, k);
numbR->desc();
printf("\n");

delete numbR, numbK;
}