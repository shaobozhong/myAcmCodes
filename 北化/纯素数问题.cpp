#include<iostream>
#include<cmath>
using namespace std;
bool la[100000];

void pick()
{
	int i,j;
	memset(la,1,sizeof(la));
	la[1]=false;
	for(i=2;i<=sqrt(double(99999));++i)
	{
		if (la[i])
		{
			for(j=i*i;j<=99999;j+=i)
			{
				la[j]=false;
			}
		}
	}

}

bool panduan(int n)
{
	int t,temp;
	temp=n;
	t=1000;
	while(t/10)
	{
		temp%=t;
		if (!la[temp]) break;
		t/=10;
	}
	if (t>=10) return false;
	return true;
}

int main()
{
	int i;
    pick();
	for(i=1001;i<=9999;++i)
	{
		if (la[i]) 
		{
			if (panduan(i)) {cout<<i<<endl;}
		}
	}

	return 0;
}