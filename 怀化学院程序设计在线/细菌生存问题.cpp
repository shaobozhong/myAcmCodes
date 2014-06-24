#include<iostream>
using namespace std;

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b),(a!=0||b!=0))
	{

		while(a!=b&&a!=0&&b!=0)
		{
			if (a%b==0) {a=b;break;}
			if (b%a==0) {b=a;break;} 
			if (a>b) {if (a%b!=0) a%=b;else a-=b;}
			else {if (b%a!=0) b%=a;else b-=a;}
		}
		if (a!=0&&b!=0)
		printf("%d\n",b);                            
		else puts("0");
	}
    return 0;
}