#include "stdio.h"
#include "algorithm"
using namespace std;
typedef struct
{
	int start,end;
}Show;
Show s[200];
int m[200];
int sn;
bool cmp(const Show &a,const Show &b)
{
	return a.start<b.start;
}
int main()
{
	while(scanf("%d",&sn)&&sn)
	{
		int i,j;
		int mc=1;
	//	scanf("%d",&sn);
		for(i=0;i<sn;i++)
		{
			scanf("%d%d",&s[i].start,&s[i].end);
		}
		sort(s,s+sn,cmp);
		m[0]=s[0].end;
		for(i=1;i<sn;i++)
		{
			for(j=0;j<mc;j++)
			{
				if(m[j]<s[i].start)
					break;
			}

			if(j==mc)
			{
				m[mc++]=s[i].end;
			}
			else
			{
				m[j]=s[i].end;
			//	printf("%d=%d ",j,m[j]);
			}
		}
		printf("%d\n",mc);
	}
	return 0;
}