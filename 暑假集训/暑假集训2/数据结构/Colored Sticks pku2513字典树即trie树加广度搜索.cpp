#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int count1;

#define MAX 500001
struct Letter
{
	int num;
	char letter;
	struct Letter *child;
	struct Letter *brother;
};

struct Edge
{
	int la;
	struct Edge *next;
};

int create(Letter *head,char word[])
{
	Letter *p,*q,*r;
	int i;
	int len;
	bool suc;
	len=int(strlen(word));
    p=head;
	for(i=0;i<len;++i)
	{
		suc=false;
		q=p->child;
		r=NULL;
		while(q)
		{
			r=q;
			if (q->letter==word[i]) 
			{
				if (i==len-1)
				{
					if (q->num!=-1)
					{
						return q->num;
					}
					else 
					{
						q->num=count1++;
					}
				}
				p=q;
				suc=true;
				break;
			}
			q=q->brother;
		}
		if (suc) continue;
		q=new Letter;
		q->brother=NULL;
		q->child=NULL;
		q->letter=word[i];
		if (i<len-1) q->num=-1;
		else 
		{
			q->num=count1++;
			if (!p->child)p->child=q;
			if (r) r->brother=q;
			return q->num;
		}
			if (!p->child) p->child=q;
			if (r) r->brother=q;
			p=q;
	}
}

Edge edge[MAX];
int main()
{

	Edge *q;
	Letter Dic;
	queue<int> queue1;
	int loc1,loc2;
	int i;
	char str1[15],str2[15];
	for(i=0;i<MAX;++i)
	{
		edge[i].next=NULL;
		edge[i].la=0;
	}
	Dic.brother=NULL;
	Dic.child=NULL;
	Dic.letter=0;
	Dic.num=-1;
	count1=0;
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		loc1=create(&Dic,str1);
		loc2=create(&Dic,str2);
		//建边
		q= new Edge;
		q->la=loc2;
		q->next=edge[loc1].next;
		edge[loc1].next=q;
		edge[loc1].la+=1;
		q= new Edge;
		q->la=loc1;
		q->next=edge[loc2].next;
		edge[loc2].next=q;
		edge[loc2].la+=1;
	}
	int top;
	int oddnum=0;//奇数数目
	int total=0;
	bool la=false;
	queue1.push(0);
	edge[0].la=0;
	if (edge[0].la%2==1) ++oddnum;

	while(!la&&!queue1.empty())
	{
		++total;
		top=queue1.front();
		queue1.pop();
		q=edge[top].next;
		while(!la&&q)
		{
			if (edge[q->la].la)
			{
				if (edge[q->la].la%2==1) 
				{
					++oddnum;
					if (oddnum>2) {la=true;break;}
				}
				edge[q->la].la=0;
				queue1.push(q->la);
			}
			q=q->next;
		}
	}
	if (total<count1 || (oddnum>2)) puts("Impossible");
	else puts("Possible");
	return 0;
}

