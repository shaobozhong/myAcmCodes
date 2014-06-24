/*
ID:shaoboz2
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<math.h>
using namespace std;
	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");

void transform(int temp,int B)
{
	char a[100];
	int count=0,t,i;
	while(temp)
	{
		t=temp%B;
		switch(t)
		{
		case 0:a[count++]='0';break;
		case 1:a[count++]='1';break;
		case 2:a[count++]='2';break;
		case 3:a[count++]='3';break;
		case 4:a[count++]='4';break;
		case 5:a[count++]='5';break;
		case 6:a[count++]='6';break;
		case 7:a[count++]='7';break;
		case 8:a[count++]='8';break;
		case 9:a[count++]='9';break;
		case 10:a[count++]='A';break;
		case 11:a[count++]='B';break;
		case 12:a[count++]='C';break;
		case 13:a[count++]='D';break;
		case 14:a[count++]='E';break;
		case 15:a[count++]='F';break;
		case 16:a[count++]='G';break;
		case 17:a[count++]='H';break;
		case 18:a[count++]='I';break;
		case 19:a[count++]='J';break;
        }
		temp/=B;
	}
	for(i=count-1;i>=0;i--)
	{
		fout<<a[i];
	}

}

void print(int i,int B)
{
	int temp;
	temp=i*i;
	transform(i,B);
	fout<<" ";
	transform(temp,B);
	fout<<endl;
}
bool juge(int temp,int B)
{
	char a[100];
	int count=0,t,i,j;
	while(temp)
	{
		t=temp%B;
		switch(t)
		{
		case 0:a[count++]='0';break;
		case 1:a[count++]='1';break;
		case 2:a[count++]='2';break;
		case 3:a[count++]='3';break;
		case 4:a[count++]='4';break;
		case 5:a[count++]='5';break;
		case 6:a[count++]='6';break;
		case 7:a[count++]='7';break;
		case 8:a[count++]='8';break;
		case 9:a[count++]='9';break;
		case 10:a[count++]='A';break;
		case 11:a[count++]='B';break;
		case 12:a[count++]='C';break;
		case 13:a[count++]='D';break;
		case 14:a[count++]='E';break;
		case 15:a[count++]='F';break;
		case 16:a[count++]='G';break;
		case 17:a[count++]='H';break;
		case 18:a[count++]='I';break;
		case 19:a[count++]='J';break;
        }
		temp/=B;
	}
	j=count-1;
	for(i=0;i<=(count-1)/2;i++)
	{
		if (a[i]!=a[j]) break;
		j--;
	}
	if (i>(count-1)/2) return true;
	return false;
}

int main() {
	int B,i,j,sum,temp,t,a[7],count;
	
	fin>>B;
	for(i=1;i<=300;i++)
	{	
	  if (juge(i*i,B)) print(i,B);
	}
	return 0;
}

