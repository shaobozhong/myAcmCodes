/*
ID:shaoboz2
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


bool t_90(char a[][11],char b[][11],int n)
{
	int i,j;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if (b[i][j]!=a[n-j-1][i]) return false;
		}
	}
	return true;
}

bool t_180(char a[][11],char b[][11],int n)
{
	int i,j;
for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if (b[i][j]!=a[n-i-1][n-j-1]) return false;
		}
	}
	return true;
}

bool t_270(char a[][11],char b[][11],int n)
{
	int i,j;
for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if (b[i][j]!=a[j][i]) return false;
		}
	}
	return true;
}
bool Reflection(char a[][11],char b[][11],int n)
{
	int i,j;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if (a[i][j]!=b[i][n-j-1]) return false;
		}
	}
	return true;
}

bool Combination(char a[][11],char b[][11],int n)
{
	int i,j;
	char temp;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=(n-1)/2;j++)
		{
			temp=a[i][j];
	      a[i][j]=a[i][n-j-1];
		  a[i][n-j-1]=temp;
		}
	}
	
	if (t_90(a,b,n)) return true;
    else if (t_180(a,b,n)) return true;
	else 	if (t_270(a,b,n)) return true;
	return false;
}

bool nochange(char a[][11],char b[][11],int n)
{
	int i,j;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if (a[i][j]!=b[i][j])  return false;
		}
	}

	return true;

}

int main() {
	ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    
    int n,i,j;
	char a[11][11],b[11][11];
	fin>>n;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			fin>>a[i][j];
		}
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			fin>>b[i][j];
		}
	}
	if (t_90(a,b,n)) fout<<"1"<<endl;
	else if (t_180(a,b,n)) fout<<"2"<<endl;
	else if (t_270(a,b,n)) fout<<"3"<<endl;
	else if (Reflection(a,b,n)) fout<<"4"<<endl;
	else if (Combination(a,b,n)) fout<<"5"<<endl;
	else if (nochange(a,b,n)) fout<<"6"<<endl;
	else fout<<"7"<<endl;
    return 0;
}

