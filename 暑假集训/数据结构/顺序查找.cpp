#include<iostream>
using namespace std;

typedef struct  node
{
   int data;
   struct node *next;
}Linklist;

int main()
{
	int t,n,num,loca,times,key;
    Linklist L,*p;
	cin>>t;
	while(t--)
	{
		L.next=NULL;
		cin>>n;	
		loca=n;
		while(n--)
		{
			cin>>num;
            p=new Linklist;
			p->data=num;
			p->next=L.next;
			L.next=p;
		}
		cin>>key;
		p=L.next;
	    times=0;
		
		while(p)
		{
			times++;
			if (p->data==key)  break;
			loca--;
			p=p->next;
		}
		if (!p) cout<<"0 "<<times<<endl;
        cout<<loca<<" "<<times<<endl;
	}
	return 0;
}