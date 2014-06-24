#include<iostream>
using namespace std;

struct Win
{
	int lx,ly,rx,ry;
};

int main()
{
	Win windows[105];
	int n,k;
	int w,h,x,y;
	int i;
	int casenum=0;
	while(scanf("%d",&n),n!=0)
	{
		++casenum;
		for(i=1;i<=n;++i)
		{
			scanf("%d%d%d%d",&windows[i].lx,&windows[i].ly,&w,&h);
			windows[i].rx=windows[i].lx+h;
			windows[i].ry=windows[i].ly+w;
		}
		printf("Desktop %d:\n",casenum);
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d",&x,&y);
			for(i=n;i>=1;--i)
			{
				if (x>=windows[i].lx && x<windows[i].rx && y>=windows[i].ly && y<windows[i].ry ) 
				{
					printf("window %d\n",i); break;
				}
			}
			if (i<1) puts("background");
		}
	}
	return 0;
}