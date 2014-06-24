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

struct Father
{
	int num;
	int father;
	int degree;
};

Father father[MAX];

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
	return 0;
}

int find1(int x)
{
	int j,i=x;
	while(father[x].father!=x)
	{
		x=father[x].father;
	}

	while(i!=x)
	{
		j=i;
		i=father[i].father;
		father[j].father=x;
	}
	return x;
}

int main()
{

	Letter Dic;
	queue<int> queue1;
	int loc1,loc2,a,b;//返回字符串的下标  loc1 loc2  并查集的祖先
	int i;
	char str1[15],str2[15];
	for(i=0;i<MAX;++i)
	{
		father[i].num=1;
		father[i].father=i;
		father[i].degree=0;
	}
	Dic.brother=NULL;
	Dic.child=NULL;
	Dic.letter=0;
	Dic.num=-1;
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		loc1=create(&Dic,str1);
		loc2=create(&Dic,str2);
		a=find1(loc1);
		b=find1(loc2);
		if (a!=b)
		{
			father[a].num+=father[b].num;
			father[b].father=father[a].father;
			
		}
         ++father[loc1].degree;
         ++father[loc2].degree;
	}
	if (father[find1(0)].num<count1) {puts("Impossible");return 0;}
	int oddnum=0;
	for(i=0;i<count1;++i)
	{
		if (father[i].degree%2==1) {++oddnum;if (oddnum>2) break;}
	}
	if (oddnum>2) {puts("Impossible");return 0;}
	puts("Possible");
	return 0;
}

