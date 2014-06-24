#include<iostream>
#include<cmath>
using namespace std;
int sign[4];
int num[4];
int calcnum[4];
bool vis[4];

double calc(double a,int sign,double b)
{
	switch(sign)
	{
	case 0:return a+b;
	case 1:return a-b;
	case 2:return a*b;
	case 3:return a/b;
	}
}

bool panduan(int i,double sum)
{
	if (i==2)
	{
		double sum2;
		double sum1=calc(double(calcnum[2]),sign[2],double(calcnum[3]));
        sum2=calc(sum,sign[1],sum1);
		if (abs(sum2-24)<0.000001) return true;
		sum2=calc(sum1,sign[1],sum);
		if (abs(sum2-24)<0.000001) return true;
		sum1=calc(double(calcnum[3]),sign[2],double(calcnum[2]));
        sum2=calc(sum,sign[1],sum1);
		if (abs(sum2-24)<0.000001) return true;
		sum2=calc(sum1,sign[1],sum);
		if (abs(sum2-24)<0.000001) return true;
	}
	if (i==4) 
	{
		if (abs(sum-24)<0.000001) return true;
		return false;
	}
	if (panduan(i+1,calc(sum,sign[i-1],double(calcnum[i])))) return true;
	if (panduan(i+1,calc(double(calcnum[i]),sign[i-1],sum))) return true;
	return false;

}

bool Sign(int i)
{
	double sum;
	int j;
	if (i==3)
	{
		sum=calcnum[0];
        if (panduan(1,sum)) return true;

		return false;
	}
	for(j=0;j<4;++j)
	{

		sign[i]=j;
		if (Sign(i+1)) return true;
	}
	return false;
}
bool numsort(int i)
{
	int j;
	if (i==4)
	{
		if (Sign(0)) return true;
		return false;
	}
	for(j=0;j<4;++j)
	{
		if (vis[j])
		{
			vis[j]=false;
			calcnum[i]=num[j];
			if (numsort(i+1)) return true;
			vis[j]=true;
		}
	}
	return false;
}
int main()
{
    //freopen("1.txt","w",stdout);
	while(scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3])!=EOF)
	{
		memset(vis,true,sizeof(vis));
		if (numsort(0)) puts("YES");
		else puts("NO");
	}
	return 0;
}