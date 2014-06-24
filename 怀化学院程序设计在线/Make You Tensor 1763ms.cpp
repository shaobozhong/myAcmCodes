#pragma warning(disable:4786)
#include<iostream>
#include<cmath>
#include<set>
using namespace std;

typedef struct  node
{
	int x;
	int y;
	bool operator<(const node a)const
	{
		if(x<a.x)
			return true;
		if(x==a.x&&y<a.y)
			return true;
		return false;
	}
}Node;

#define eps 1e-6
Node p;
int map2[505][505];
int n,m;
set<Node>set1;

int work(int cl,int col,int r,int c)
{
	int tmpr,tmpc,i,j;
	double rate,trate;
	for(i=0;i<r;i+=r)
	{
		for(j=0;j<c;j+=c)
		{
			rate=(double)map2[i][j]/map2[0][0];
			for(tmpr=i;tmpr<i+cl;++tmpr)
			{
				for(tmpc=j;tmpc<j+col;++tmpc)
				{
					trate=double(map2[tmpr][tmpc])/map2[tmpr-i][tmpc-j];
					if (fabs(trate-rate)>=eps) return 0;
				}
			}
		}
	}
	return 1;
}

int Judge(int r,int c)
{
	int min1,sum=1;
	int i,j,k;
	double rate,trate;
	int tmpr,tmpc;
	min1=INT_MAX;
	for(i=0;i<r;++i)
	{
		for(j=0;j<c;++j)
		{
			if (min1>map2[i][j]) min1=map2[i][j];
		}
	}
	for(i=0;i<n;i+=r)
	{
		for(j=0;j<m;j+=c)
		{
			rate=(double)map2[i][j]/map2[0][0];
			for(tmpr=i;tmpr<i+r;++tmpr)
			{
				for(tmpc=j;tmpc<j+c;++tmpc)
				{
					trate=double(map2[tmpr][tmpc])/map2[tmpr-i][tmpc-j];
					if (fabs(trate-rate)>=eps) return 0;
				}
			}
		}
	}
    bool flag;
    int count2;
	count2=1;
	for(i=2;i<=min1;++i)
	{
			flag=true;
		for(j=0;flag&&j<n;++j)
		{
			for(k=0;k<m;++k)
			{
                if (map2[j][k]%i!=0)
				{
					flag=false;
					break;
				}
			}
		}
		if (flag) ++count2;
	}
	for(i=1;i<r;i++)
	{
		for(j=1;j<c;j++)
		{
			p.x=i;
			p.y=j;
			if(set1.count(p)>0)
				continue;
			if ((i==1 && j==1)|| (r%i!=0) || (c%j!=0) || (r/i==1 && c/j==1)) continue;
			if(work(i,j,r,c))
			{
				set1.insert(p);
				sum++;
			}
		}
	}
	return count2*sum;
}

int main()
{
	
	int i,j;
	int count1;
	
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		set1.clear();
		count1=0;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				scanf("%d",&map2[i][j]);
			}
		}
		for(i=n;i>=1;i--)
		{
			for(j=m;j>=1;j--)
			{
				p.x=i;
				p.y=j;
				if(set1.count(p)>0)
					continue;
				if ((i==1 && j==1)|| (n%i!=0) || (m%j!=0) || (n/i==1 && m/j==1)) continue;
				count1+=Judge(i,j);
			}
		}
		printf("%d\n",count1);
	}
	return 0;
}