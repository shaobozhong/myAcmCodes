#include<iostream>
#include<queue>
#include<iostream>
using namespace std;

#define MAX 40001

struct Information
{
	int num1,num2,distance;
	char direct;
};

struct Question
{
	int num1,num2,limit;
	int q;
};


struct Point
{
	int x,y;
};


Information Infor[MAX];
Question qu[10001];

int n,m,k;//输入的 各种量

void work(int num1,int num2,int limit)
{
	queue<int> q;
	int ex;
	bool vis[MAX];
	Point p[MAX];
	int i;
	bool la;
	for(i=0;i<=n;++i)
	{
		vis[i]=true;
	}
	la=false;
	vis[num1]=false;
	p[num1].x=0;
	p[num1].y=0;
	q.push(num1);
	while(!la&&!q.empty())
	{
		    ex=q.front();
			q.pop();
			for(i=0;!la&&i<limit;++i)
			{
				if (Infor[i].num1==(ex) && vis[Infor[i].num2])
				{
					switch(Infor[i].direct)
					{
					case 'N':p[Infor[i].num2].x=p[ex].x; p[Infor[i].num2].y=p[ex].y+Infor[i].distance;break;
					case 'S':p[Infor[i].num2].x=p[ex].x; p[Infor[i].num2].y=p[ex].y-Infor[i].distance;break;
					case 'E':p[Infor[i].num2].x=p[ex].x+Infor[i].distance; p[Infor[i].num2].y=p[ex].y;break;
					case 'W':p[Infor[i].num2].x=p[ex].x-Infor[i].distance; p[Infor[i].num2].y=p[ex].y;break;
					}
					vis[Infor[i].num2]=false;
					q.push(Infor[i].num2);
					if (Infor[i].num2==num2) {la=true;break;}
				}
				else 
				{
					if (Infor[i].num2==(ex) && vis[Infor[i].num1])
					{
						switch(Infor[i].direct)
						{
						case 'N':p[Infor[i].num1].x=p[ex].x; p[Infor[i].num1].y=p[ex].y-Infor[i].distance;break;
						case 'S':p[Infor[i].num1].x=p[ex].x; p[Infor[i].num1].y=p[ex].y+Infor[i].distance;break;
						case 'E':p[Infor[i].num1].x=p[ex].x-Infor[i].distance; p[Infor[i].num1].y=p[ex].y;break;
						case 'W':p[Infor[i].num1].x=p[ex].x+Infor[i].distance; p[Infor[i].num1].y=p[ex].y;break;
						}
						vis[Infor[i].num1]=false;
						if (Infor[i].num1==num2) {la=true;break;}
						q.push(Infor[i].num1);
					}
				}
			}
	}

	if (vis[num2]) puts("-1"); 
	else 
	{
		printf("%d\n",abs(p[num2].x)+abs(p[num2].y));
	}
}

int main()
{
	int i;
	int num1,num2,limit;
	char ch;
	//cin>>n>>m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<m;++i)
		{
			scanf("%d%d%d%c%c",&Infor[i].num1,&Infor[i].num2,&Infor[i].distance,&ch,&Infor[i].direct);

			//cin>>Infor[i].num1>>Infor[i].num2>>Infor[i].distance>>Infor[i].direct;
		}
		scanf("%d",&k);
		for(i=0;i<k;++i)
		{
			scanf("%d%d%d",&qu[i].num1,&qu[i].num2,&qu[i].limit);
			//cin>>num1>>num2>>limit;
			if (num1==num2) {puts("0");continue;}
			work(num1,num2,limit);
		}
	}
	return 0;
}