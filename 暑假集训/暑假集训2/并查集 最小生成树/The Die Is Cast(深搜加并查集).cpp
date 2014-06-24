#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


struct point 
{
	int x,y;
	int father;
};

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[51][51];
vector <point> X;
int Xnum;
int w,h;

bool cmp(int a,int b)
{
	return a<b;
}

int find1(int x)
{
	while(X[x].father!=x)
	{
		x=X[x].father;
	}
	return x;
}

void del()
{
	int i,j;
	int loc1,loc2;
	for(i=0;i<int(X.size());++i)
	{
		for(j=0;j<int(X.size());++j)
		if (X[i].x==X[j].x &&abs(X[i].y-X[j].y)==1  ||X[i].y==X[j].y &&abs(X[i].x-X[j].x)==1) 
		{
			loc1=find1(i);
			loc2=find1(j);
			if (loc1!=loc2)
			{
			  Xnum--;
			  X[loc2].father=X[loc1].father;
			}
		}
	}
}

void work(int i,int j)
{
	if (map[i][j]=='X') 
	{ 
		
		point temp;
		temp.x=i;
		temp.y=j;
		temp.father=Xnum++;
		X.push_back(temp);
	}
	map[i][j]='@';
	for(int k=0;k<4;++k)
	{
		int x,y;
		x=i+dir[k][0];
		y=j+dir[k][1];
		if (x<0 || x>=h || y<0 || y>=w) continue;
		if (map[x][y]=='*'||map[x][y]=='X') 
		{
			work(x,y);
		}
	}
}

int main()
{
	vector<int> res;
	int i,j;
	int casenum=0;
	//freopen("1.txt","w",stdout);
	while(scanf("%d%d",&w,&h),w!=0||h!=0)
	{
		++casenum;
		res.clear();
		getchar();
		for(i=0;i<h;++i)
		{
			for(j=0;j<w;++j)
			{
				map[i][j]=getchar();
			}
			getchar();
		}

		for(i=0;i<h;++i)
		{
			for(j=0;j<w;++j)
			{
				if (map[i][j]=='*' || map[i][j]=='X')
				{
					Xnum=0;
					X.clear();
					work(i,j);
                    del();
					res.push_back(Xnum);
				}
			}
		}
		printf("Throw %d\n",casenum);
		sort(res.begin(),res.end(),cmp);
		for(i=0;i<int(res.size());++i)
		{
			printf("%d ",res[i]);
		}
		putchar('\n');
		putchar('\n');
	}
	return 0;
}
