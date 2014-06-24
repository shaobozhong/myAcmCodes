#include<iostream>
using namespace std;

struct node
{
	int num;
	struct node *next;
};

struct Top
{
	struct node *next;
};

	int n,m;
Top t[30];
int degree[30];
bool al[30];
bool finish;

void Topsort(int step,int count3)
{
	int d[30];
	int i;
	int res[30];
	int lable;
	bool va;
	node *p;
	int count1,count2;
	va=false;
	for(i=0;i<n;++i)
	{
		d[i]=degree[i];
	}

	count1=0;
	while(1)
	{
		count2=0;
		for(i=0;i<n;++i)
		{
			if (al[i]&&d[i]==0) {lable=i;++count2;}
		}
		if (count2==0) break;
		if (count2>=2) va=true;
		res[count1]=lable;
		++count1;
		--(d[lable]);
		p=t[lable].next;
		while(p)
		{
			--(d[p->num]);
			p=p->next;
		}
	}

	if (count1<count3) {finish=true;printf("Inconsistency found after %d relations.\n",step);return;}
	if (count1==n && !va)  
	{
		finish=true;
		printf("Sorted sequence determined after %d relations: ",step);
		for(i=0;i<n;++i)
		{
		    putchar(res[i]+'A');
		}
		putchar('.');
		putchar('\n');
		return;
	}


}


int main()
{
    node *q;
	int count3;
	int num1,num2;
	char a,b,ch;
	int i;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		finish=false;
		for(i=0;i<n;++i)
		{
			degree[i]=0;
			al[i]=false;
			t[i].next=NULL;
		}
		count3=0;
		for(i=1;i<=m;++i)
		{
			getchar();
			scanf("%c%c%c",&a,&ch,&b);
			if (finish) continue;
			num1=int(a-'A');
			num2=int(b-'A');
			if (!al[num1]) { ++count3; al[num1]=true;}
			if (!al[num2]){ ++count3;al[num2]=true;}


			++(degree[num2]);
			q=new node;
			q->num=num2;
			q->next=t[num1].next;
			t[num1].next=q;
			Topsort(i,count3);
		}
		if (!finish) {puts("Sorted sequence cannot be determined.");}
	}
	return 0;
}

