//ÉîËÑ´úÂë³¬Ê±

#include<iostream>
using namespace std;

struct Point
{
	bool la;
	int style;
	int count;
};
Point r[31][31];

int n,m,ex,ey,_min,_minnum;
void work(int x,int y,int _count)
{
	if (x<0||x>=n||y<0||y>=m||r[x][y].style==2||(!(r[x][y].la)&&_count>r[x][y].count))
	{
		return;
	}
    if (r[x][y].count>_count) r[x][y].count=_count;
	if (x==ex&&y==ey) 
	{
		if (_count<_min) {_min=_count;_minnum=1;}
		else 
		{
			if (_count==_min) 
			{
				++_minnum;
			}
		}
		return;
	}
	r[x][y].la=false;
	if ((r[x][y].style)==0) 
	{
		work(x+1,y+2,_count+1);
		work(x-1,y+2,_count+1);
		work(x+2,y+1,_count+1);
		work(x-2,y+1,_count+1);
		work(x+1,y-2,_count+1);
		work(x-1,y-2,_count+1);
		work(x+2,y-1,_count+1);
		work(x-2,y-1,_count+1);
	}
	else 
	{
		work(x+1,y+2,_count);
		work(x-1,y+2,_count);
		work(x+2,y+1,_count);
		work(x-2,y+1,_count);
		work(x+1,y-2,_count);
		work(x-1,y-2,_count);
		work(x+2,y-1,_count);
		work(x-2,y-1,_count);
	}
}
int main()
{

	int i,j,sx,sy;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		_min=INT_MAX;
		for (i=0;i<n;++i)
		{
			for (j=0;j<m;++j)
			{
				scanf("%d",&(r[i][j].style));
				r[i][j].la=true;
				r[i][j].count=INT_MAX;
				if (r[i][j].style==3) 
				{
					sx=i;
					sy=j;
				}
				else 
				{
					if(r[i][j].style==4) 
					{
						ex=i;
						ey=j;
					}
				} 
			}
		}
		work(sx,sy,0);
		printf("%d\n%d\n",_min,_minnum);
	}
	return 0;
}