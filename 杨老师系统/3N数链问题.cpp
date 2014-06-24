#include<iostream>
using namespace std;

int main()
{
	int a,b,num;
	int i,max1,count1;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		max1=0;
		for(i=a;i<=b;++i)
		{
			num=i;
			count1=1;
			while(num!=1)
			{
				++count1;
				if (num%2==0) num/=2;
				else num=num*3+1;
			}
			if (max1<count1) max1=count1;
		}
		printf("%d\n",max1);
	}
	return 0;
}