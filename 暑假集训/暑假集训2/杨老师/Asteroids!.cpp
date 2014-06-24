#include<iostream>
#include<string>
#include<queue>
using namespace std;

#define MAX 15
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct Point
{
	int x,y,z;
};

char map[MAX][MAX][MAX];

int main()
{
	bool la;
	int weight; 
	int n,i,j,k;
	string str;
	Point temp,s,e;
	int count1,qsize;
	queue <Point> expand;
	Point top;
	int step;
	while(cin>>str)
	{
		while(!expand.empty())
		{
			expand.pop();
		}
		la=false;
		cin>>n;
		weight=1;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				for(k=0;k<n;++k)
				{
					cin>>map[i][j][k];
				}
			}
		}

		cin>>s.z>>s.y>>s.x;
		map[s.x][s.y][s.z]=false;
		cin>>e.z>>e.y>>e.x;
		cin>>str;
		step=0;

		if (s.x==e.x &&s.y==e.y &&s.z==e.z )
		{
			printf("%d %d\n",n,step);
			continue;
		}

		expand.push(s);
		step=1;
		count1=0;
		qsize=int(expand.size());
		while(!la&&!expand.empty())
		{
			count1++;
			if (count1>qsize)
			{
				step++;
				count1=0;
				qsize=int(expand.size());
				continue;
			}

			top=expand.front();
			expand.pop();

			for(i=0;i<6;++i)
			{
				temp.x=top.x+dir[i][0];
				temp.y=top.y+dir[i][1];
				temp.z=top.z+dir[i][2];
				if (map[temp.x][temp.y][temp.z]=='O'&&temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<n&&temp.z>=0&&temp.z<n)
				{
					map[temp.x][temp.y][temp.z]='X';
					expand.push(temp);
					if (temp.x==e.x &&temp.y==e.y &&temp.z==e.z )
					{
						la=true;
						break;
					}
				}
			}
		}
		if (la) printf("%d %d\n",n,step);
		else puts("NO ROUTE");
	}
	return 0;
}