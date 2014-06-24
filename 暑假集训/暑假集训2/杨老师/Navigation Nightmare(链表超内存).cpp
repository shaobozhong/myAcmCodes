#include<iostream>
#include<queue>
using namespace std;

#define MAX 40001

struct Information
{
	int num1,num2,distance;
	char direct;
};

struct Node
{
	int num;
	struct Node *next;
	int distance;
	char direct;
};

struct Point
{
	int x,y;
};

Information Infor[MAX];

int n,m,k;//输入的 各种量

void work(int num1,int num2,int limit)
{
	queue<int> q;
	int ex;
	int i;
	bool vis[MAX];
	Point p[MAX];
	bool la;
	Node Link[MAX];
	Node *l;
    //建邻接表 
	for(i=0;i<=n;++i)
	{
		vis[i]=true;
		Link[i].next=NULL;
	}

    for(i=0;i<limit;++i)
	{
		l=new Node;
		l->num=Infor[i].num2;
		l->distance=Infor[i].distance;
		l->direct=Infor[i].direct;
		l->next=Link[Infor[i].num1].next;
		Link[Infor[i].num1].next=l;
		l=new Node;
		l->num=Infor[i].num1;
		l->distance=-1*Infor[i].distance;
		l->direct=Infor[i].direct;
		l->next=Link[Infor[i].num2].next;
		Link[Infor[i].num2].next=l;
	}

	//广度扩展
	la=false;
	vis[num1]=false;
	p[num1].x=0;
	p[num1].y=0;
	q.push(num1);
	while(!la&&!q.empty())
	{
		    ex=q.front();
			q.pop();
			l=Link[ex].next;
			while(l)
			{
				if (vis[l->num])
				{
					switch(l->direct)
					{
					case 'N':p[l->num].x=p[ex].x; p[l->num].y=p[ex].y+l->distance;break;
					case 'S':p[l->num].x=p[ex].x; p[l->num].y=p[ex].y-l->distance;break;
					case 'E':p[l->num].x=p[ex].x+l->distance; p[l->num].y=p[ex].y;break;
					case 'W':p[l->num].x=p[ex].x-l->distance; p[l->num].y=p[ex].y;break;
					}
					vis[l->num]=false;
					if (l->num==num2) {la=true;break;}
					q.push(l->num);

				}
				l=l->next;
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
	while(cin>>n>>m)
	{
		for(i=0;i<m;++i)
		{
			cin>>Infor[i].num1>>Infor[i].num2>>Infor[i].distance>>Infor[i].direct;
		}
		cin>>k;
		for(i=1;i<=k;++i)
		{
			cin>>num1>>num2>>limit;
			if (num1==num2) {puts("0");continue;}
			work(num1,num2,limit);
		}
		
	}
	return 0;
}