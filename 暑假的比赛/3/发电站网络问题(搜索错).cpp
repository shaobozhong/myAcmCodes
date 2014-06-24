#include<iostream>
#include<vector>
using namespace std;
typedef struct 
{
	vector <int> city;
}City;

City c[1001];
bool la[1001];
int MM;
int n,limit[1001];
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

void work(int summax)
{
	int temp;
	int i,j,imax,max;
	for(i=1;i<n;i++)
		{
			imax=0;max=-1;
			for(j=1;j<=n;j++)
			{ 
			if (panduan(j)&&max<limit[j]) {max=limit[j];imax=j;}
			}
			if (c[imax].city.size()>=2) {temp=limit[imax];limit[imax]=-1;work(summax);limit[imax]=temp;}
			la[imax]=true;
		}
		for(i=1;i<=n;i++)
		{
			if (la[i]) summax+=limit[i];
		}
		if (summax>MM) MM=summax;
}

int main()
{
	int temp;
	int m,a,b,summax,max,i,j,imax;
	while(scanf("%d",&n)>0&&n!=0)
	{
		MM=0;
		summax=0;
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
		for(i=1;i<n;i++)
		{
			imax=0;max=-1;
			for(j=1;j<=n;j++)
			{ 
			if (panduan(j)&&max<limit[j]) {max=limit[j];imax=j;}
			}
		
			if (c[imax].city.size()>=2) {temp=limit[imax];limit[imax]=-1;work(summax);limit[imax]=temp;}
			la[imax]=true;
		}
		for(i=1;i<=n;i++)
		{
			if (la[i]) summax+=limit[i];
		}
		if (summax>MM) MM=summax;
		for(i=1;i<=n;i++)
		{
			c[i].city.clear();
		}
		printf("%d\n",MM);
	}
	return 0;
}