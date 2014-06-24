#include<iostream>
using namespace std;
#define M 3

typedef struct 
{
	int head;
	int tail;
	int data[M];
}queue;


void en_que(queue *s,int num)
{
	if ((s->tail+1)%M==s->head)
	{
		cout<<"¶ÓÂú£¡"<<endl;
		return; 
	}
	s->data[s->tail]=num;
	s->tail=(s->tail+1)%M;
}

void out_que(queue *s)
{
	if (s->tail==s->head) 
	{
		cout<<"¶ÓÒÑ¿Õ£¡"<<endl;
		return;
	}
	cout<<s->data[s->head]<<endl;
	s->head=(s->head+1)%M;
}

int main()
{
	queue s;
	s.head=s.tail=0;
	en_que(&s,1);
	en_que(&s,2);
	out_que(&s);
	en_que(&s,3);
	en_que(&s,4);
	out_que(&s);
	return 0;
}