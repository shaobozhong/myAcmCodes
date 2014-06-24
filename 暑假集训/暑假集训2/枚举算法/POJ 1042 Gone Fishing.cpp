#include<iostream>
using namespace std;

int f[26];
int d[26];
int t[26];
int rt[26];//存储最优情况在每个湖的停留时间
int fishingmax;

void greed(int n,int fishingtime)
{
	int i;
	int tempmax;//当前单位时间捕鱼量最大的湖泊的编号
	int f1[26];//存储当前每个湖泊单位时间的捕鱼量
	int b[26];//临时的一个湖泊停留的时间方案
	int harvest;//鱼的收获量
	memset(b,0,sizeof(b));//初始化时间分配方案
	for(i=0;i<=n;++i)
	{
		f1[i]=f[i];
	}
    harvest=0;
	while(fishingtime)
	{
		tempmax=-1;
		for(i=0;i<=n;++i)
		{
			if (tempmax==-1||f1[tempmax]<f1[i]) {tempmax=i;}
		}
		harvest+=f1[tempmax];
		b[tempmax]+=1;
		if (f1[tempmax]>=d[tempmax]) 
		{
			f1[tempmax]-=d[tempmax];
		}
		else 
		{
			f1[tempmax]=0;
		}
		fishingtime-=1;
	}

	if (harvest>fishingmax || (fishingmax==harvest && b[0]>rt[0]))
	{
		fishingmax=harvest;
		for(i=0;i<=n;++i)
		{
			rt[i]=b[i];
		}
	}


}
int main()
{
	int n,h;//样例数 湖泊数 时间
	int walktime;//方案中走路所耗的时间
	int i;


	while(cin>>n,n!=0)
	{
		memset(rt,0,sizeof(rt));
		fishingmax=0;
		cin>>h;
		h*=12;
		for(i=0;i<n;++i)
		{
			cin>>f[i];
		}

		for(i=0;i<n;++i)
		{
			cin>>d[i];
		}

		for(i=0;i<n-1;++i)
		{
			cin>>t[i];
		}
		walktime=0;
		for(i=0;i<n;++i)
		{
			if (walktime>=h) break;
			greed(i,h-walktime);
			walktime+=t[i];
		}

		for(i=0;i<n-1;++i)
		{
			printf("%d, ",rt[i]*5);
		}
		printf("%d\n",rt[i]*5);
		printf("Number of fish expected: %d\n\n",fishingmax);
	}
	return 0;
}