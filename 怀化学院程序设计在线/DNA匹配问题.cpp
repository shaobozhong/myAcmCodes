#include<iostream>
#include<string>
using namespace std;

struct Node
{
	string data;
	struct Node *next;
};

bool match(const string &a,const string &b)
{
	int i;
	if ((int)a.size()!=(int)b.size()) return false;
	for (i=0;i<(int)a.size();++i)
	{
		if ((a[i]=='A'&&b[i]!='T')||(a[i]=='T'&&b[i]!='A')||(a[i]=='G'&&b[i]!='C')||(a[i]=='C'&&b[i]!='G')) return false;
	}
	return true;
}

int main()
{
	Node head,*q;
	string str;
	int t,n,_count;
	scanf("%d",&t);
	while (t--)
	{
		head.next=NULL;
		scanf("%d",&n);
        while (n--)
		{
			q=new Node;
			cin>>q->data;
			q->next=head.next;
			head.next=q;
        }
		_count=0;
		while (head.next)
		{
			q=head.next;
			if (q)str=q->data;
			while (q->next)
			{
				if (match(q->next->data,str)) {q->next=q->next->next;_count++;break;}
				q=q->next;
			}
			head.next=head.next->next;
		}
		printf("%d\n",_count);
	}
	return 0;
}