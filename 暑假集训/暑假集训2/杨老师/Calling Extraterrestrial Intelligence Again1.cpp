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
			for(q=p;q<count1;++q)//能否改为从大到小  但是大到小 虽然可以直接过滤掉乘积小于max1的p值的情况  则条件判断不能直接跳出 必须要全部做 
			{
				if (ps[p]*ps[q]>m || (double)ps[p]/ps[q]<rate ) break;
				if (max1<ps[p]*ps[q])
				{
					max1=ps[p]*ps[q];
					resp=ps[p];
					resq=ps[q];
				}
			}
		}
		cout<<resp<<" "<<resq<<endl;
	}
	return 0;
}