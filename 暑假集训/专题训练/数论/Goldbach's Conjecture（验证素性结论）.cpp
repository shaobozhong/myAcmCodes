#include<iostream>
#include<math.h>
using namespace std;
#define M 1000002
bool a[M]={0};


void  shai()
{ 
	int i,j;
	for(i=2;i<=M;i++)
	{
		a[i]=1;
	}
	a[1]=0;
	for(i=2;i<=(int)sqrt((double)M);i++)
	{
		if (a[i]!=0)
		{

			for(j=i*i;j<=M;j=j+i)
				a[j]=0;
		}
	}
}

int main()
{
	int i,n;
	shai();
	while(cin>>n,n)
	{
		for(i=3;i<=n/2;i+=2)
		{
			if (a[i]&&a[n-i]) {cout<<n<<" = "<<i<<" + "<<n-i<<endl;break;}

		}
		if (i>n/2) cout<<"Goldbach's conjecture is wrong."<<endl;
	}
	return 0;
}