#include<iostream>
using namespace std;
#define MAX 10001
bool p[MAX];
int ps[MAX];
int count1;

void Prime()
{
	int i,j;

	memset(p,true,sizeof(p));
	p[0]=false;
	p[1]=false;
	
	for(i=2;i*i<MAX;++i)
	{
		if (p[i])
		{
			for(j=i+i;j<MAX;j+=i)
			{
				p[j]=false;
			}
		}
	}
    count1=0;
	for(i=2;i<MAX;++i)
	{
		if (p[i]) {ps[count1++]=i;}
	}
}
int main()
{
	int m,a,b;
	double rate; 
	int p,q;//是对应题目中素数的下标
	int resp,resq;
	int max1;
	Prime();
	while(cin>>m>>a>>b,m!=0||a!=0||b!=0)
	{	
		rate=double(a)/b;
		max1=0;
		for(p=count1-1;p>=0;--p)
		{
			for(q=count1-1;q>=p;--q)//反向后可能 针对一些数据 尤其是小数据 每次都从大的开始  很多太大的没必要去做
			{
				if (ps[p]*ps[q]<max1) break;
				if (ps[p]*ps[q]<=m && (double)ps[p]/ps[q]>=rate)
				{
					max1=ps[p]*ps[q];
					resp=ps[p];
					resq=ps[q];
					break;
				}
			}
		}
		cout<<resp<<" "<<resq<<endl;
	}
	return 0;
}