#include<iostream>
#include<cmath>
using namespace std;
bool la[1000];

void pick()
{
	int i,j;
	memset(la,true,sizeof(la));
	la[1]=false;
	for(i=2;i<=sqrt((double)999);++i)
	{
		if (la[i]) 
		{
			for(j=i*i;j<=999;j+=i)
			{
				la[j]=false;
			}
		}
	}
	la[1]=true;
	la[0]=true;
}

bool panduan(int n)
{
	int temp=n;
	while(temp)
	{
		if (la[temp]) return false;
		temp/=10;
	}
	return true;
}

int main()
{
	int i;
    pick();
	for(i=100;i<=999;++i)
	{
		if (!la[i])
		{
			if (panduan(i)) cout<<i<<endl;
		}
	}
	return 0;
}
