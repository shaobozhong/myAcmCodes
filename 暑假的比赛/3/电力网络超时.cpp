#include<iostream>
#include<vector>
using namespace std;
typedef struct 
{
	vector <int> city;
}City;

City c[1001];
bool la[1001];

int Max,limit[1001],n;
bool panduan(int i)
{
	int j;
	if (la[i]) return false;
	if (limit[i]==-1) return false;
	for(j=0;j<c[i].city.size();j++)
	{
		if (la[c[i].city[j]]) return false;
	}
}

void work(int summax,int temp)
{
	int j; 
    bool sign;
	sign=true;
	for(j=1;j<=n;++j)
	{

		if (panduan(j))
		{
			sign=false;
			temp=limit[j];
			limit[j]=-1;
			work(summax,0);
			limit[j]=temp;
			la[j]=true;
			work(summax+limit[j],0);
			la[j]=false;
		}
	}
	if(sign) {if (summax>Max) Max=summax; return;}

}


int main()
{
  int m,a,b,i;
	while(scanf("%d",&n)>0&&n!=0)
	{
		memset(la,false,sizeof(la));
		for(i=1;i<=n;++i)
		{
			scanf("%d",&limit[i]);
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			c[a].city.push_back(b);
			c[b].city.push_back(a);
		}
		Max=0;
		work(0,0);
		for(i=1;i<=n;i++)
		{
			c[i].city.clear();
		}
		printf("%d\n",Max);
		
	}
	return 0;
}