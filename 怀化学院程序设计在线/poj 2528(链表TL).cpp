#include<iostream>
#include<set>
using namespace std;

struct node
{
	int lx,rx;
	int state;
	struct node *next;
};


int lx,rx;
int i;
node head;
node *p,*q,*r;
int casenum,n;
void work()
{
	    set<int> res;
		scanf("%d",&n);
		head.next=NULL;
		for(i=1;i<=n;++i)
		{
			scanf("%d%d",&lx,&rx);
			q=new node;
			q->lx=lx;
			q->rx=rx;
			q->state=i;
			q->next=head.next;
			head.next=q;
			p=q;
			while(p->next)
			{
				if (p->next->lx>=lx && p->next->rx <=rx){p->next=p->next->next;if (p->next&&p->next->lx==lx && p->next->rx ==rx) {break;} continue; }
				if (p->next->lx>=lx &&p->next->lx<=rx && p->next->rx>rx)  {p->next->lx=rx+1;p=p->next;continue;}
				if (p->next->lx<lx &&p->next->rx>=lx && p->next->rx<=rx )  {p->next->rx=lx-1;p=p->next;continue;}
				if (p->next->lx<rx && p->next->rx>rx)   
				{
					r=new node;
					r->lx=rx+1;
					r->rx=p->next->rx;
					p->next->rx=lx-1;
					r->state=p->next->state;
					r->next=p->next->next;
					p->next->next=r;
					p=p->next->next;
					break;
				}
				p=p->next;
			}
		}
		p=head.next;
		while(p)
		{
			res.insert(p->state);
			p=p->next;
		}
		int ans=int(res.size());
		printf("%d\n",ans);
}
int main()
{

	
	scanf("%d",&casenum);
	while(casenum--)
	{
		work();
	}
	return 0;
}