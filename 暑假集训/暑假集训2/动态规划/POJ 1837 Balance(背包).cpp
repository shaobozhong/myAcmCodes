#include<iostream>
using namespace std;

int res[21][8000];

int main()
{
	int C,G;
	int W[21],P[21];//Weight Position
	int sum,mid,max1;//动态的计算平衡点  和最大值的变量
	int i,j,k;
	scanf("%d%d",&C,&G);
	for(i=1;i<=C;++i)
	{
		scanf("%d",&P[i]);
	}
    sum=0;
	for(i=1;i<=G;++i)
	{
		scanf("%d",&W[i]);
		sum+=W[i];
	}
	mid=sum*15/2+1;//一边不能超过总和的一半   mid是平衡量
	max1=2*mid;//最大值是看mid行事

	for(i=1;i<=G;++i)
	{
		for(j=0;j<=max1;++j)
		{
		  res[i][j]=0;
		}
	}

	for(i=1;i<=C;++i)
	{
		res[1][mid+W[1]*P[i]]++;
	}

	for(i=2;i<=G;++i)
	{
		for(j=1;j<=C;++j)
		{
			for(k=0<P[j]*W[i]?0:(-1*P[j]*W[i]);k<=max1&&k+P[j]*W[i]<=max1;++k)
			{
				if (res[i-1][k])
				{
					res[i][k+P[j]*W[i]]+=res[i-1][k];
				}
			}
		}
	}
	printf("%d\n",res[G][mid]);
	return 0;
}