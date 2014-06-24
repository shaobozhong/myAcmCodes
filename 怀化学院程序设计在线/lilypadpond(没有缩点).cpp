//Ã»ÓÐËõµã

#include<iostream>
#include<vector>
using namespace std;

struct pos
{
	int x,y;
	int style;
};

struct _rou
{
	int x,y;
};
pos p[31][31];

vector <_rou> route;
vector  <_rou> rtemp;
int _num,n,m;
bool _Isend;
void work(int x,int y,int _count)
{
	_rou _temp;
	if (_count==1) {_temp.x=x;_temp.y=y;route.push_back(_temp);return;}
	if (p[x][y].style==2||x<0||x>=n||y<0||y>=m) return;
	_temp.x=x;
	_temp.y=y;
	rtemp.push_back(_temp);
	if (p[x][y].style==4) {_Isend=false;++_num;return;}
	if (p[x][y].style==0)
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
 
	_rou temp;
    int _count,ex,ey,i,j,sx,sy,_len;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		_num=0;
    for (i=0;i<n;++i)
    {
		for (j=0;j<m;++j)
		{
			scanf("%d",&p[i][j].style);
			if (p[i][j].style==3)
			{
				sx=i;
				sy=j;
			}
			else 
			{
				if (p[i][j].style==4)
				{
					ex=i;
					ey=j;
				}
			}
		}
    }
	temp.x=sx;
	temp.y=sy;
	route.push_back(temp);
	_count=0;
	_Isend=true;
	while(_Isend)
	{
		_len=(int)route.size();
        for (i=0;i< _len;++i)
        {
			work(route[i].x,route[i].y,0);
        }
		for (i=0;i<(int)rtemp.size();++i)
		{
			p[rtemp[i].x][rtemp[i].y].style=2;
		}
		rtemp.clear();
		for (i=0;i< _len;++i)
		{
		  route.erase(route.begin());
		}
		++ _count;
	}
	printf("%d %d\n",_count-1,_num);
	}
	return 0;
}