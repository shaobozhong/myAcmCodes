
#include<iostream>
#include<algorithm>
using namespace std;

struct Result
{
	int a,b;
};

bool cmp(const Result &a,const Result &b)
{
	if (a.b==b.b) return a.a<b.a;
	return a.b<b.b;
}

int main()
{
	bool la[125505];
	int sum[35000]; //251*251=63001 ij互换最多就30000多情况
	int n,m,i,j,k;
    int len;
	Result r[15000];//题目中有说不超过10000
	int max1;
	int count1;
	while(cin>>n>>m)
	{
	max1=2*m*m;
	for(i=0;i<=max1;++i)
	{
		la[i]=false;
	}
	for(i=0;i<=m;++i)
	{
		for(j=0;j<=m;++j)
		{
			la[i*i+j*j]=true;
		}
	}
	len=0;
	for(i=0;i<max1;++i)
	{
		if (la[i]) sum[len++]=i;
	}
	count1=0;
	for(i=0;i<len;++i)
	{
		for(j=i+1;j<len;++j)
		{
			if (sum[i]+(n-1)*(sum[j]-sum[i])>max1) break;
			for(k=1;k<n;++k)
			{
				if (!la[sum[i]+k*(sum[j]-sum[i])]) break;
			}
			if (k<n) continue;
			r[count1].a=sum[i];
			r[count1++].b=sum[j]-sum[i];
		}
	}
	if (count1==0) {cout<<"NONE"<<endl;continue;}
	sort(r,r+count1,cmp);
	for(i=0;i<count1;++i)
	{
		cout<<r[i].a<<" "<<r[i].b<<endl;
	}
	}
	return 0;
}
