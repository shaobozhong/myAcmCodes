#include<iostream>
using namespace std;

bool map[26][26];

int main()
{
	int maxx,maxy,count,already;
	int rob,x,y,i,j,k;
	while(1)
	{
		rob=0;
		already=0;
		count=0;
		maxx=0;maxy=0;
		memset(map,false,sizeof(map));
		while(scanf("%d%d",&x,&y)!=EOF&&(x!=0||y!=0)&&(x!=-1||y!=-1))
		{
			++count;
			map[x][y]=true;
			if (maxx<x) maxx=x;
			if (maxy<y) maxy=y;
		}
		while(already<count)
		{
			++rob;
			i=1;j=1;
			while(i<=maxx)
			{
				if (map[i][j]) {++already;map[i][j]=false;}
				while(1)
				{
					for(k=j+1;k<=maxy;++k)
					{
						if (map[i][k]) {map[i][k]=false;already++;j=k;break;} 
					}
					if (k>=maxy) {++i;break;}
				}
			}
		}
		
		if (x==-1&&y==-1) break;
		printf("%d\n",rob);
	}
	return 0;
}