//program fish;
#include<iostream>
using namespace std;
const int maxn=32;				//	{	鱼数的最大值		}




int n,m;						//	{	鱼的数目，资金				}
int a[maxn][maxn];		//{	各鱼之间的共处性				}
int v[maxn];			//{	各鱼的价格					}
int h[maxn];			//{	估计函数值					}
int p[maxn],pbest[maxn];		//{	买鱼的情况，及最佳方案		}
int cone,best;					//	{	买鱼的数目，及最优值			}
int sumbest,sum;				//	{	买鱼的花费，及最优值			}


void  best_found()//					{	最优值初始化		}
{
	int i,j;
	best=0;
	sumbest=0;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			a[i][j]=0;
		}
	}
}

void h_found() //{	计算启发函数		}
{
	int d[maxn];
	int nbak;
	int s,c,t;
	int i,j,k;
	h[0]=0;
	nbak=n;
	for (n=1;n<=nbak;++n)
	{
		for (j=1;j<=n;++j)
		{
			d[j]=0;
			for (k=1;k<=n;++k)
				if (a[j][k]==1 )  d[j]=d[j]+1;
		}
		s=0;
		for (i=1;i<=n;++i) s+=d[i];

		for (i=1;i<=n-1;++i)//冒泡排序  从大到小
			for (j=i+1;j<=n;++j)
				if (d[i]<d[j])
				{
					k=d[i];
					d[i]=d[j];
					d[j]=k;
				}

				c=0;
				t=0;
				while(c<s)
				{
					++t;
					c=c+d[t]+d[t];
				}

				h[n]=n-t;
	}
	n=nbak;
}

void  p_found(int t)	//		{	递归搜索		}
{
	bool bb;
	int i,j;
	p[t]=-1;
	do
	{
		p[t]=p[t]+1;
		if (p[t]==1) 
		{
			++cone;
			sum=sum+v[t];
		}
		if (sum<=m)  bb=true;
		else bb=false;
		if (cone+h[t-1]<best)  bb=false;
		if ((bb==true) && (p[t]==1))
		{
			for (i=n;i>=t+1;--i) 
			{
				if (bb) 
				{
					if ((p[i]==1) && (a[i][t]==1))  bb=false;
				}
			}
		}


		if (bb==true) 
			if (t==1)
			{
				if ((cone>best) ||(cone==best&&sum>sumbest))
				{
					best=cone;
					sumbest=sum;
					for(j=0;j<=n;++j)
					{
						pbest[j]=p[j];
					}
				}
			}
			else p_found(t-1);

			if (p[t]==1)
			{
				--cone;
				sum=sum-v[t];
			}
	}while(p[t]!=1);

}

void  p_output()//						{	输出解	}
{
	int i;

	cout<<best<<' '<<sumbest<<endl;
	for (i=1;i<=n;++i)
		if (pbest[i]==1)  cout<<i<<endl;
}

void  data_input() //	{	数据输入		}
{


	int t1,t2;
	int i,j;
	(cin>>m>>n);
	{
		best_found();
		for (i=1;i<=n;++i)
		{
			cin>>t1>>t2;
			v[t1]=t2;
		}

		for (i=1;i<=n;++i)
			for (j=1;j<=n;++j) a[i][j]=0;

		cin>>t1>>t2;
		while ((t1!=0) || (t2!=0)) 
		{
			a[t1][t2]=1;
			a[t2][t1]=1;
			cin>>t1>>t2;
		}

		h_found();
		cone=0;
		sum=0;
		p_found(n);
		p_output();
	}
}


int  main()
{
	data_input();
	return 0;
}







