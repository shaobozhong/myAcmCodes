#include<iostream>
using namespace std;



typedef struct list
{
  struct list *next;
  int data;
}List;


void creat(List *head,int n)
{
	int i;
	List *p,*q;
 
p=head;
head->next=NULL;
for(i=1;i<=n;i++)
{
  q=new List;
  cin>>(q->data);
  p->next=q;
  p=q;
}
p->next=NULL;

}

void de(List *head,int n,int m)
{
	int i=0;
	List *p,*q;
	p=head;
	while(p&&i<m-1)
	{
      p=p->next;
	  i++;
	}
	q=p->next;
	p->next=q->next;
    free(q);

}


void insert(List *head,int n,int w)
{int i=0;
   List *p,*q;
p=head;
while(i<w-1)
{
  p=p->next;
  i++;
}
q=new List;
cin>>q->data;
q->next=p->next;
p->next=q;
}

void pri(List *head)
{
	List *p;
	p=head->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	cout<<endl;
}


int main()
{
	int n,m,w;
List *head;

	cin>>n;
head=new List;
creat(head,n);
cin >>m;
if (m>0&&m<=n)
de(head,n,m);
cin>>w;
if (w>0&&w<=n)
insert(head,n-m,w);
pri(head);
	return 0;
}