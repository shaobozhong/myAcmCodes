#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
char map[5][5];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int minStep=INT_MAX;

struct Elem{
	int x,y;
};
Elem Etemp;
vector<Elem> res,temp;
void shortPath(int x,int y,int step)
{
	int i;
    int tempx,tempy;
	if (step>=minStep) return;
	if (x==4&&y==4) 
	{
		if (step<minStep)
		{
			minStep=step;
			res.clear();
			for(i=0;i<int(temp.size());++i)
			{
				res.push_back(temp[i]);
			}
		}
		return;
	}

	for(i=0;i<4;++i)
	{
        tempx=x+dir[i][0];
		tempy=y+dir[i][1];
		if (tempx<0||tempx>4||tempy<0||tempy>4) continue;
		if (map[tempx][tempy]=='0')
		{
          map[tempx][tempy]='1';
		  Etemp.x=tempx;
		  Etemp.y=tempy;
		  temp.push_back(Etemp);
          shortPath(tempx,tempy,step+1);
		  temp.pop_back();
		  map[tempx][tempy]='0';
		}
	}
}



int main()
{
	
	
	int i,j;
    for(i=0;i<5;++i)
	{
		for(j=0;j<5;++j)
		{
			scanf("%c",&map[i][j]);
			getchar();
		}
	}
	res.clear();
	temp.clear();
	Etemp.x=0;Etemp.y=0;
	temp.push_back(Etemp);
	shortPath(0,0,0);
	for(i=0;i<int(res.size());++i)
	{
		printf("(%d, %d)\n",res[i].x,res[i].y);
	}
	return 0;
}