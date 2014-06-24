#include<iostream>
using namespace std;

bool work(int *_count,int *c,int num)
{
	int t;
	while (num)
	{
		t=num%10;
		if (_count[t])
		{
			_count[t]--;
			c[t]++;
		}
		else return false;
		num/=10;
	}
	return true;
}

int main()
{
	int _count[10],temp,c[10];
	int i,j,n;
	bool res;
	scanf("%d",&n);
	while (n--)
	{
		for (i=0;i<10;++i)
		{
			_count[i]=0;
		}
		res=false;
		for (i=0;i<9;++i)
		{
			scanf("%d",&temp);
			_count[temp]++;
		}
		for (i=111;i<=333&&!res;++i)
		{
			for (j=1;j<10;++j)
			{
				c[j]=0;
			}
			if (work(_count,c,i))
			{
				if (work(_count,c,2*i))
				{
					if (work(_count,c,3*i))
					{
						res=true;
						break;
					}
				}
			}
			for (j=1;j<10;++j)
			{
				_count[j]+=c[j];
			}
		}
		if (res) printf("%d\n",i);
		else puts("NULL");
	}
	return 0;
}