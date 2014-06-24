#include<iostream>
using namespace std;


int main()
{
	int caseNum,n,even,odd,num;
    cin>>caseNum;
	while(caseNum--)
	{
		cin>>n;
		even=0;
		odd=0;
		while(n--)
		{
			cin>>num;
			if (num%2==0) ++even;
			else ++odd;
			
		}
		cout<<even<<" even and "<<odd<<" odd."<<endl;
	}
	return 0;
}