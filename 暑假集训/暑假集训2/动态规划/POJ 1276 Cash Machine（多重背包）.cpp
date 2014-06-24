#include<iostream>
#include<algorithm>
using namespace std;

bool res[100001];
struct Data
{
	int num,value;
};
int main()
{

	int cash,n;
	Data data[1001];
	int i,j,k;
	while(scanf("%d",&cash)!=EOF)
	{
		for(i=0;i<=cash;++i)
		{
			res[i]=false;
		}
		res[0]=true;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&data[i].num,&data[i].value);
			if (data[i].num==0 || data[i].value>cash) {--n;--i;}
		}
		if (cash*n==0) {puts("0");continue;}
		for(i=0;!res[cash]&&i<n;++i)
		{
			for(j=cash;!res[cash]&&j>=0;--j)
			{
				if (res[j])
				{
					for(k=1;!res[cash]&&k<=data[i].num&&k*data[i].value+j<=cash&&!res[k*data[i].value+j];++k)
                    //for(k=1;!res[cash]&&k<=data[i].num&&k*data[i].value+j<=cash;++k)
					{
						if (!res[k*data[i].value+j])
						{
							res[k*data[i].value+j]=true;
						}
					}
				}
			}
		}

		for(i=cash;i>=0;--i)
		{
			if (res[i]) break;
		}
		printf("%d\n",i);
	}
	return 0;
}