/*
ID:shaoboz2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() { 
	ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int sunday=0,monday=0,tuesday=0,wendsday=0,thursday=0,friday=0,saturday=1,N,year,month,r;
    fin >> N;
	year=1900;month=2;r=6;
    while(year<=1899+N)
	{
		 if (month-1==2)
		 {
			 if (year%400==0||(year%4==0&&year%100!=0))
				 r+=1;
         }
		 switch(month-1)
		 {
		 case 1:
		 case 3:
		 case 5:
		 case 7:
		 case 8:
		 case 10:
		 case 0:r+=3;break;
		 case 4:
		 case 6:
		 case 9:
		 case 11:r+=2;
		 }
		 r=r%7;
		 switch(r)
		 {
		 case 1:monday++;break;
		 case 2:tuesday++;break;
		 case 3:wendsday++;break;
		 case 4:thursday++;break;
		 case 5:friday++;break;
		 case 6:saturday++;break;
		 default:sunday++;
		 }
		 month++;
		 if (month>12)
		 {
			 month=1;
			 year++;
		 } 
	}
    fout <<saturday<<" "<<sunday<<" "<<monday<<" "<<tuesday<<" "<<wendsday<<" "<<thursday<<" "<<friday<< endl;
    return 0;
}