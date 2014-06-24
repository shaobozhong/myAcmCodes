/*
ID:shaoboz2
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool transform(int n,int B)
{
	int i,j;
	char a[36];
	int temp,count=0,t;
	temp=n;
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
		case 9:a[count++]='9';
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

int main() 
{
	ofstream fout ("dualpal.out");
	ifstream fin ("dualpal.in");
	int n,s,count,i;
	fin>>n>>s;
	s++;
	while(n>=1)
	{
		count=0;
			for(i=2;i<=10;i++)
			{
				if (transform(s,i)) {count++;if (count==2) break;}
			}
			if (count==2)  {fout<<s<<endl;n--;};
			s++;
	}
	return 0;
}

