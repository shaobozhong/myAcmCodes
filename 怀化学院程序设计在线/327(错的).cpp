#include <iostream>
#include<string>
using namespace std;

string  _left,temp,seg; 
struct gather_1
{
	gather_1 *next;
	string data;
};

struct biggather
{
   gather_1 *ghead;
   biggather *next;
   string data;

};
biggather *ghead;

void _add1 (biggather *b)
{
   gather_1 *p,*q;
   
   if (!b->ghead) {b->ghead=new gather_1;b->ghead->data=seg;b->ghead->next=NULL;return;}
   p=b->ghead;
   while (p->next)
   {
	   if (p->data==seg) return;
	   p=p->next;
   }
   if (p->data==seg) return;
   q=new gather_1;
   q->data=seg;
   q->next=NULL;
   p->next=q;
}
	
void _add()
{
   biggather *b;
   
   //if (!ghead) {ghead=new biggather;ghead->data=_left;ghead->next=NULL;ghead->ghead=NULL;}
   b=ghead;
   while(b)
   {
	   if (_left==b->data) break;
	   b=b->next;
   }
   _add1(b);
   /*if (b)
   {
      _add1(b);
   }
   else 
   {
	   c=new biggather;
	   c->data=_left;
	   c->ghead=NULL;
	   c->next=NULL;
	   b->next=c;
	   b=c;
	   _add1(b);
   }*/
   
}

bool find_2(biggather *p,biggather *r)
{
    gather_1 *q;
	q=r->ghead;
	while (q)
	{
		if (p->data==q->data&&r->data!=q->data) return true;
		q=q->next;
	}
	return false;
}

bool find_1(biggather *p,gather_1 *q)
{
	biggather * r;
	r=ghead;
	while (r)
	{
		if (r->data==q->data) {if (find_2(p,r)) return true;}
		r=r->next;
	}
	return false;
}
bool panduan(biggather *p)
{
	gather_1 *q;
	q=p->ghead;
	while (q)
	{
		if (find_1(p,q)) return false;
		q=q->next;
	}
	return true;
}
void addleft()
{
	biggather *b,*c;
	
    if (!ghead) {ghead=new biggather;ghead->data=_left;ghead->next=NULL;ghead->ghead=NULL;return;}
	b=ghead;
	while(b->next)
	{
		if (b->data==_left) return;
		b=b->next;
	}
		if (b->data==_left) return;
    c=new biggather;
	c->data=_left;
	c->ghead=NULL;
	c->next=NULL;
	b->next=c;
}
int main()
{
	biggather *p;
	int i;
    while (getline(cin,temp))
    {
		_left=temp.substr(0,6);
		addleft();
		for(i=6;i<(int)temp.size();++i)
		{
			if (temp[i]=='R')  
			{
				seg=temp.substr(i,6);
				_add();
				i+=6;
			}
		}
    }
	p=ghead;
	while(p)
	{
		cout<<p->data<<" ";
		if (panduan(p)) puts("ok");
		else puts("circular");
		p=p->next;
	}
	return 0;
}