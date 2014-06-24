#include<iostream>
using namespace std;
int father[1000001];
int sata[1000001],re[100001],rs[100001];
int find(int x)
{
	int st=x,temp;
	while(x!=father[x])
	{
		x=father[x];
	}
	while(st!=father[st])
	{
		temp=father[st];
		father[st]=x;
		st=temp;
	}
	return x;
}

void union_1(int a,int b)
{
	int t1=find(a);
	int t2=find(b);
	if(sata[t1]>sata[t2])
	{
		father[t2]=t1;
		sata[t1]+=sata[t2]+1;
	}
	else
	{
		father[t1]=t2;
		sata[t2]+=sata[t1]+1;
	}
}

int main()
{
	int n,minn,maxn,i,max;
	while(cin>>n)
	{
		if (n==0) {cout<<"1"<<endl;continue;}
		max=0;
		minn=2100000000;
		maxn=0;
		for(i=0;i<n;i++)
		{

			cin>>rs[i]>>re[i];
			if (maxn<rs[i]) maxn=rs[i];
			if (maxn<re[i]) maxn=re[i];
			if (minn>re[i]) minn=re[i];
			if (minn>rs[i]) minn=rs[i];
			father[rs[i]]=rs[i];
			father[re[i]]=re[i];
			sata[rs[i]]=0;
			sata[re[i]]=0;
		}
		for(i=0;i<n;i++)
		{
			if (find(rs[i])!=find(re[i])) union_1(rs[i],re[i]);
		}
		for(i=minn;i<=maxn;i++)
		{
			if (max<sata[i]) max=sata[i];
			sata[i]=0;
		}
		cout<<max+1<<endl;
	}
	return 0;
}