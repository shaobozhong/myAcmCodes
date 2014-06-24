#include<iostream>
#include<algorithm>
using namespace std;

struct Task
{
	int s,e;
};



bool cmp(const Task &b,const Task &c)
{
	if (b.e==c.e) return b.s<c.s;
	return b.e<c.e;
}


bool cmp1(const Task b,const Task c)
{
	return b.e<c.e;
}


int main()
{
	Task a[405];
    Task lable[405];
	int t,tmp,tmp1;
	int n,ti;
	int i,j;
	int count1;
	int minisum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d%d",&a[i].s,&ti);
			a[i].e=a[i].s+ti;
		}
		sort(a,a+n,cmp);
		minisum=0;
		for(i=0;i<n;++i)
		{
			count1=0;
			for(j=i+1;j<n;++j)
			{
				if (a[j].s<a[i].s )
				{
					lable[count1].s=j; 
					lable[count1++].e=a[j].e-(a[i].s-a[j].s);
				}
			}

			if (count1)
			{
			sort(lable,lable+count1,cmp1);
			tmp=a[i].s;
			    for(j=0;j<count1;++j)
				{
					if (a[lable[j].s].s<tmp) {tmp1=a[lable[j].s].s;a[lable[j].s].s=tmp;tmp=tmp1;}
				}
			}
			for(j=i+1;j<n;++j)
			{
				if (a[j].s<a[i].e) {minisum+=a[i].e-a[j].s; a[j].e+=a[i].e-a[j].s; a[j].s=a[i].e;}
			}
			sort(a+i+1,a+n,cmp);

		}
		printf("%d\n",minisum);
	}
	return 0;
}

