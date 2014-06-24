#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef struct node
{
	char  ch[100];
	struct node *next;
}Q;

void find(Q *head)
{
	bool t=false;
	int i,j,plen,qlen;
	Q *p=head,*q=head->next;
	{
		while(q->next)
		{
			i=0;
			plen=(int)strlen(p->next->ch)-1;
			qlen=(int)strlen(q->next->ch)-1;
			while(i<=plen&&i<=qlen)
			{
				if (p->next->ch[i]<q->next->ch[i]) {p=q;t=true;break;}
				if (p->next->ch[i]>q->next->ch[i]) { t=true;break;}
				i++;
			}
			
			if (!t) 
			{
			
			while(i<=plen)
			{
				for(j=0;j<=qlen;j++)
				{
					if ((p->next->ch)[i]<(q->next->ch)[j]) {p=q;t=true;break;}
				}
				if (t) break;
				i++;
			}
			while(i<=qlen)
			{
				for(j=0;j<=qlen;j++)
				{
					if ((p->next->ch)[j]>(q->next->ch)[i]) {t=true;break;}
				}
				if (t) break;
				i++;
			}
		
			}
			q=q->next;
		}
		cout<<p->next->ch;
		p->next=p->next->next;
	}
}
int main()
{
	Q head;
	Q *p;
	char s[100];  
int n,i;
head.next=NULL;
 cin>>n;
 getchar();
 for(i=0;i<=n-1;i++)
 {
	gets(s);
	 p=new Q;
	 strcpy(p->ch,s);
	 p->next=head.next;
	 head.next=p;
 }
 for(i=0;i<=n-2;i++)
 {
   find(&head);
 }
 cout<<head.next->ch<<endl;
  return 0;
}