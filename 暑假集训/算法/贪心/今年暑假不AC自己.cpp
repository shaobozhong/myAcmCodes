#include<iostream>
using namespace std;

typedef struct 
{
	int begin,end;
	bool la;
}period;

int repeat(period *s,int i,int n,int *a)
{
	int j,time=0;
	for(j=0;j<=n-1;j++)
	{
		if (i!=j&&s[j].la&&((s[j].begin>=s[i].begin&&s[j].begin<s[i].end)||(s[j].end>s[i].begin&&s[j].end<=s[i].end)||(s[j].begin<=s[i].begin&&s[j].end>=s[i].end)))
			a[time++]=j;
	}
	return time;
}

void sign(period *s,int *a,int re)
{
	int i;
	for(i=0;i<=re-1;i++)
		s[a[i]].la=false;
}

int main()
{
	period s[102];
	int n,i,must,a[102],re,time,total,max;
	while(cin>>n,n!=0)
	{	
		total=0;
		for(i=0;i<=n-1;i++)
		{
			cin>>s[i].begin>>s[i].end;
			s[i].la=true;
		}
		max=i;
		i=0;
		must=0;
		while(must!=-1&&max>0)
		{
			
			must=-1;
			re=10000;
			for(i=0;i<=n-1;i++)
			{
				if (s[i].la)
				{
					time=repeat(s,i,n,a);
					if (time<re) {re=time;must=i;}
				}
			}	
			if (must!=-1) 
			{
				s[must].la=false;
				time=repeat(s,must,n,a);

				sign(s,a,re);
			}
			else break;
			total++;
		}
		cout<<total<<endl;
	}
	return 0;
}