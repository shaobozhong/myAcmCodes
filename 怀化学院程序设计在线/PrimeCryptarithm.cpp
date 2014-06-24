#include <iostream>
using namespace std;
bool a[10];

bool work(int num)
{
	int t;
    while (num)
    {
		t=num%10;
		if (!a[t]) return false;
		num/=10;
    }
	return true;
}

int main()
{
    int i,j,n,temp,_count,num;
	
	while (scanf("%d",&n)!=EOF)
	{
	    _count=0;
		memset(a,false,sizeof(a));
		for (i=0;i<n;++i)
		{
			scanf("%d",&temp);
			a[temp]=true;
		}
		for (i=111;i<=999;++i)
		{
			for (j=11;j<=10000/i+1;++j)
			{
				if (work(i))
				{
					if (work(j)&&j>=10&&j<100)
					{
						num=i*(j%10);
						if (work(num)&&num>=100&&num<1000)
						{
							num=i*(j/10);
							if (work(num)&&num>=100&&num<1000)
							{
								num=i*j;
								if (work(num)&&num>=1000&&num<10000)
								{
								   _count++;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n",_count);
	}
	return 0;
}