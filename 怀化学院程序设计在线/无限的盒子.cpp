#include<iostream>
using namespace std;

bool map[1005][1005];
struct point 
{
	int x,y;
};


int main()
{
	point p[1005];
	int n,m,k;
	int count1,step,i,j;
	int lx,rx,ly,ry;
	while(scanf("%d%d%d",&n,&m,&k),n!=0||m!=0||k!=0)
	{
		count1=0;
		step=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
			{
				map[i][j]=false;
			}
		}
		for(i=0;i<k;++i)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		while(count1<n*m)
		{
			for(i=0;i<k;++i)
			{
				lx=p[i].x-step>1?p[i].x-step:1;
				rx=p[i].x+step<n?p[i].x+step:n;
				ly=p[i].y-step>1?p[i].y-step:1;
				ry=p[i].y+step<m?p[i].y+step:m;
				for(j=ly;j<=ry;++j)
				{
					if (!map[lx][j]) {map[lx][j]=true;++count1;}
					if (!map[rx][j]) {map[rx][j]=true;++count1;}
				}
				for(j=lx;j<=rx;++j)
				{
					if (!map[j][ly]) {map[j][ly]=true;++count1;}
					if (!map[j][ry]) {map[j][ry]=true;++count1;}
				}
			}
			++step;
		}

		printf("%d\n",step);
	}
	return 0;
}