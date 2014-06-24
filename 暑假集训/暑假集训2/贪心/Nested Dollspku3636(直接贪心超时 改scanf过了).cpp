#include<iostream>
#include<algorithm>
using namespace std;

struct Doll
{
	int w,h;
	bool la;
};

bool cmp(const Doll &a,const Doll &b)
{
	if (a.w==b.w) return a.h>b.h;//¸ßÒªÓÃ½µÐò
	return a.w<b.w;
}

int main()
{ 
    Doll d[ 20001];
	int casenum;
	int count1;
	int n,i,j;
	int w,h;
	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%d",&n);
        for(i=0;i<n;++i)
		{
			scanf("%d%d",&d[i].w,&d[i].h);
			d[i].la=false;
		}
		sort(d,d+n,cmp);
		count1=0;
		for(i=0;i<n;++i)
		{
			if (d[i].la) continue;
			++count1;
			d[i].la=true;
			w=d[i].w;
			h=d[i].h;
			for(j=i+1;j<n;++j)
			{
				if (d[j].la) continue;
				if (d[j].w>w && d[j].h>h)
				{
					d[j].la=true;
					w=d[j].w;
					h=d[j].h;
				}
			}
		}
		printf("%d\n",count1);
	}
	return 0;
}