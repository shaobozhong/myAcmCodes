#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int num;
	bool state;
};

int main()
{
	stack <node> s;
	int n,i;
	int k,num;
	int rnum,lnum;
	node a[105];
	node b[105];
	char ch;
	int casenum;
	casenum=0;
	
	while(scanf("%d",&n),n!=0)
	{
		++casenum;
		getchar();
		for(i=1;i<=n;++i)
		{
			a[i].num=i;
			ch=getchar();
			if (ch=='U') a[i].state=true;
			else a[i].state=false;
		}

		rnum=n;
		lnum=1;
		num=n-2;
		getchar();
		while(num--)
		{
			ch=getchar();
			if (ch=='R')
			{
				for(i=rnum;i<=n;++i)
				{
					a[i].state=!a[i].state;
					s.push(a[i]);
				}
				--rnum;
				a[n]=a[rnum];
				for(i=rnum;i<n;++i)
				{
					a[i]=s.top();
					s.pop();
				}
			}
			else 
			{

				for(i=1;i<=lnum;++i)
				{
					a[i].state=!a[i].state;
					s.push(a[i]);
				}

				++lnum;
				for(i=1;i<lnum;++i)
				{
					a[i]=s.top();
					s.pop();
				}
			}
		}


		//最后一次
		ch=getchar();
		if (ch=='R')
		{
			for(i=rnum;i<=n;++i)
			{
				a[i].state=!a[i].state;
				s.push(a[i]);
			}
			for(i=n-rnum+2;i<=n;++i)
			{
				b[i]=a[i-(n-rnum+1)];
			}
			for(i=rnum;i<=n;++i)
			{
				b[i-rnum+1]=s.top();
				s.pop();
			}

		}
		else 
		{

			for(i=1;i<=lnum;++i)
			{
				a[i].state=!a[i].state;
				s.push(a[i]);
			}
			++lnum;
			for(i=1;i<lnum;++i)
			{
				b[i]=s.top();
				s.pop();
			}
			for(i=lnum;i<=n;++i)
			{
				b[i]=a[i];
			}
		}
		printf("Pile %d\n",casenum);
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&num);
			printf("Card %d is a face ",num);
			if (b[num].state==false) printf("down %d.\n",b[num].num);
			else printf("up %d.\n",b[num].num);
		}
	}
	return 0;
}