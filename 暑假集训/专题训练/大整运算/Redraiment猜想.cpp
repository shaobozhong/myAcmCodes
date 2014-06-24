#include<iostream>
#include<math.h>
using namespace std;
bool a[100000001];
void  shai()
{ 
	int i,j;
	for(i=2;i<=100000000;i++)
	{
		a[i]=1;
	}
	a[1]=0;
	for(i=2;i<=(int)sqrt((double)100000000);i++)
	{
		if (a[i]!=0)
		{
                for(j=i*i;j<=100000000;j=j+i)
				a[j]=0;
		}
	}
}

int main()
{
	int count=2,n;
	int time,i;
	shai();
	while(cin>>n)
	{
		time=0;
		for(i=2;i<=n;i++)
           if (a[i]) time++;
			   cout<<time<<endl;
	}
	return 0;
}