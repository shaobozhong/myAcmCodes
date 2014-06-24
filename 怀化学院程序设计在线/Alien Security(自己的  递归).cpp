#include<iostream>
#include<vector>
using namespace std;

bool success,la;

typedef struct node 
{
	int la;
	struct node *next;
}child;
int etroom;
child *room;
vector<int> road,already;

bool search_in(int s ,const vector <int> &temp)
{
	int i;
	for(i=0;i<temp.size();i++)
	{
		if (s==temp[i]) break;
	}
	if (i<temp.size()) return true;
	return false;
}

void work(int start)
{
	int i;
	child *p;
	if (success&&la)
	{
		for(i=0;i<already.size();i++)
		{
			if (search_in(already[i],road)) return;
		}
		if (i>=already.size()) la=false;
	}
	if (room[0].la==1) return;
	if (start==0) 
	{
		if (!success)
		{
			road.push_back(0);
			success=true;
			return;
		}
		else 
		{
			room[0].la=1;
			return;
		}
	}
	if (search_in(start,already)) return;
	if (success) 
	{
		if (search_in(start,road))  
		{
			room[start].la=1;
			return;
		}
	}
	already.push_back(start);
	if (!success&&start!=etroom) road.push_back(start);
	p=room[start].next;
	while(p)
	{
		work(p->la);
		p=p->next;
	}
	already.pop_back();
	if (!success) road.pop_back();
}

int main()
{
	
	child *p,*q;
	int k,t,n,i,rooms,s,e,res;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		la=true;
		success=false;
		scanf("%d%d",&rooms,&etroom);
		room=new child[rooms+2];
		for(i=0;i<rooms;i++)
		{
			room[i].next=NULL;
			room[i].la=0;
		}
	scanf("%d",&n);
		while(n--)
		{
			scanf("%d%d",&s,&e);
		
			p=&room[e];
			while(p->next&&p->next->la<s)
			{
				p=p->next;
			}
			q=new child;
			q->la=s;
			q->next=p->next;
			p->next=q;
		}
		work(etroom);
		p=room[etroom].next;
		res=p->la;

		while(p)
		{
			room[p->la].la=1;
			p=p->next;
		}
		for(i=0;i<road.size();i++)
		{
			if (room[road[i]].la==1) res=road[i];
		}
		printf("Put guards in room %d.\n",res);
		road.clear();
		already.clear();
}
	return 0;
}