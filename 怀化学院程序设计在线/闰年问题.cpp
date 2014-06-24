#include<iostream>
using namespace std;

int main()
{
	int year;
	while(cin>>year)
	{
		if (year%400==0||(year%4==0&&year%100!=0))  puts("is a leap year");
		else  puts("is not a leap year");
	}
	return 0;
}