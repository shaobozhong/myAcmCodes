#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int res;
	int n,weight,i;
	char str[30];
	scanf("%d",&n);

	while(n--)
	{
		res=0;
		scanf("%s",str);
		weight=1;
		for(i=int(strlen(str)-1);i>=0;--i)
		{
			res+=(int(str[i])-48)*weight;
			weight*=2;
		}
		printf("%d\n",res);
	}
	

	return 0;
}