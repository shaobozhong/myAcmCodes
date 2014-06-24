#include<iostream>
using namespace std;

int main()
{
	int n,m;
	int a,b;
	int i;
	int max1;
	int fang[10001];
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		max1=0;
		for(i=0;i<10001;++i)
		{
			fang[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			++fang[a];
			++fang[b];
			if (max1<fang[a]) max1=fang[a];
			if (max1<fang[b]) max1=fang[b];
		}
		printf("%d\n",max1);
	}
	return 0;
}