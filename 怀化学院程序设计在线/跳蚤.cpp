#include<iostream>
using namespace std;


long long a[130000];
//long long s[130000];
bool vis[130000];
int total;
long long per;
int n,m;



void product(long long  x)//求m的质因子
{
	int i;
	for (i=2;i*i<=x;++i)
	{
		if(x%i==0)	
		{
			while(x%i==0)
				x=x/i;
			a[total]=i;
			total++;
		}
	}
	if(x!=1) 
	{
		a[total]=x;
		total++;
	}	
}

long long my_pow(long long  x,long long y)
{
	int i;
	long long res;
	res=1;
	for (i=1;i<=y;++i)
	{
		res*=x;
	}
	return res;
}

/*
void get(int a, int b, int c) {
//计算个包含i+1个因子的个数
int i;
if(b==c){
long long t=m;
for(i=0;i<c;i++){
t=t/s[i];
}
per+=my_pow(t,n);
}
else{
for(i=a;i<total;i++)
{
s[b]=num[i];
get(i+1,b+1,c);
}
}
}*/

void calc(int e,int num,int  _temp)//计算num个质因子的元组数
{
	int i;
	if (num==0) {per+=my_pow(_temp,n);}
	else 
	{
		for (i=e;i<total;++i)
		{
			//if (vis[i])
			//{
				//vis[i]=false;
				calc(i+1,num-1,_temp/a[i]);
			//}
		}
	}
}

int main()
{
	long long res;
	int t,i,j;
	scanf("%d",&t);
	while (t--)
	{
		total=0;
		scanf("%d%d",&n,&m);
		product(m);
		res=my_pow(m,n);
		if (total==0)
		{
			res-=1;
			printf("%lld\n",res);
			continue;
		}


		for (i=0;i<total;++i)
		{
			/*
			for (j=0;j<total;++j)
						{
							vis[j]=true;
						}*/
			
			per=0;
			//get(0,0,i+1);
			calc(0,i+1,m);
			if (i%2==0)
			{
				res-=per;
			}
			else
			{
				res+=per;
			}
		}
		printf("%lld\n",res);
	}

	return 0;
}
