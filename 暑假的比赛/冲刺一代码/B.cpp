#include<iostream>
using namespace std;

int gobei(int a, int b)
{
	int result,temp;
    if (a<b) {result=a;a=b;b=result;}
	result=a*b;
    while(a%b!=0)
	{
		temp=a;
		a=b;
		b=temp%b;
	}
	return result/b;
}

int main()
{
    int a,b,c,temp1,temp2,result;
	freopen("B.in","r",stdin);
	while(scanf("%d%d%d",&a,&b,&c)!=EOF&&(a!=0&&b!=0&&c!=0))
	{
		temp1=gobei(a,b);
		temp2=gobei(b,c);
		result=gobei(temp1,temp2);
		printf("%d %d %d\n",result/a,result/b,result/c);
	}
	return 0;
}