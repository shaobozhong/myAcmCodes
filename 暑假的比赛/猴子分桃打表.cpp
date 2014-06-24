#include<iostream>
using namespace std;

int n;
int work(__int64 temp,int count)
{
	if (count==n-1) {printf("%I64d\n",temp);return 0;}
	if (temp%4!=0) return 0;
	return 1+work(temp*5/4+1,count+1);
}

int main()
{
	freopen("2.txt","r",stdin);
	__int64 temp;
	int i,count;
	while(scanf("%d",&n)!=EOF&&n)
	{
		if (n==1) puts("1");
	for(i=0;i<100000000;++i)
	{
		count=0;
		temp=i*5+1;
		if (temp%4==0)
		{
		  count=work(temp,0);
		}
		if (count==n-1) break;
	}
	//if (i<100000000) printf("%I64d\n",temp);
	}
	return 0;
}