#include<iostream>
using namespace std;

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct Point
{
	int x,y;
};

Point a[4],b[4];
bool vis[65];
bool work(int step)
{
	int i,j;

	for(i=0;i<4;++i)
	{
		if (a[i].x!=b[i].x||a[i].y!=b[i].y) break;
	}
    if (step>=8) 
	{
		return false;
	}

	if (i==4) return true;

	for(i=0;i<4;++i)
	{
		for(j=0;j<4;++j)
		{
			if (a[i].x+dir[j][0]>0&&a[i].x+dir[j][0]<=8 && a[i].y+dir[j][1]<=8&&a[i].y+dir[j][1]>0) 
			{
				if(vis[(a[i].x+dir[j][0]-1)*8+(a[i].y+dir[j][1])]) 
				{

					a[i].x+=dir[j][0];
					a[i].y+=dir[j][1];
					if (work(step+1)) return true;
					a[i].x-=dir[j][0];
					a[i].y-=dir[j][1];
				}
				else 
				{
					if (a[i].x+2*dir[j][0]>0&&a[i].x+2*dir[j][0]<=8 && a[i].y+2*dir[j][1]<=8&&a[i].y+2*dir[j][1]>0)
					{
						if(vis[(a[i].x+2*dir[j][0]-1)*8+(a[i].y+2*dir[j][1])]) 
						{

							a[i].x+=2*dir[j][0];
							a[i].y+=2*dir[j][1];
							if (work(step+1)) return true;
							a[i].x-=2*dir[j][0];
							a[i].y-=2*dir[j][1];
						}
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	int i;

	for(i=0;i<=64;++i)
	{
		vis[i]=true;
	}
	for(i=0;i<4;++i)
	{
		cin>>a[i].x;
		cin>>a[i].y;
		vis[(a[i].x-1)*8+a[i].y]=false;
	}

	for(i=0;i<4;++i)
	{
		cin>>b[i].x;
		cin>>b[i].y;
	}
	if (work(0)) puts("YES");
	else puts("NO");
	return 0;
}