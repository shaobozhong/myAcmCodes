#include<iostream>
using namespace std;


typedef struct 
{
	int len;
	char data[100];
}bunch;

void quan(int *num,bunch *t)//生成模式串
{
	int i,j;
	num[0]=0;
  t->len=(int)strlen(t->data);
  for(i=1;i<=t->len-1;i++)
  {
	  j=i-1;
	  while(num[j] && t->data[i-1]!=t->data[num[j]-1])
	  j=num[j]-1;
	  num[i]=num[j]+1;
  }
}


void pri(int *num,bunch *t)//打印模式串
{
	int i;
  for(i=0;i<=t->len-1;i++)
	  cout<<num[i]<<" ";
  cout<<endl;
}

int index(bunch *s,bunch *t,int *num)//匹配
{
	int i=0,j=0,k;
	while(i<=s->len-1&&j<=t->len-1)
	{
		if (s->data[i]==t->data[j]) {i++;j++;}
		else 
		{
			if (!num[j]) i++;
			else j=num[j]-1;
		}
	}
	if (j>t->len-1) return i-t->len+1;
	return 0;
}

int main()
{
    bunch s,t;
	int loc;
	int num[100];
	while(gets(s.data))
	{
		gets(t.data);
		t.len=(int)strlen(t.data);
		s.len=(int)strlen(s.data);
		quan(num,&t);
		pri(num,&t);
		loc=index(&s,&t,num);
		cout<<loc<<endl;
	}
	return 0;
}