#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct Fish
{
	int num;
	int price;
};

struct Limit
{
	int num1;
	int num2;
};

int fund,various;
bool map[31][31];
Fish v[31];
int maxkinds,maxmoney;
bool b[31],res[31];

bool panduan(int i)
{
	int j;
	for(j=0;j<i;++j)
	{
		if (b[j])
		{
			if (!map[v[i].num][v[j].num]) return false;
		}
	}

	return true;
}

void work(int omoney,int money,int kinds,int i)
{
	int j;
	if (money>fund) 
	{
		if (maxkinds<kinds-1 || maxkinds==kinds-1 && omoney>maxmoney )
		{
			maxkinds=kinds-1;
			maxmoney=omoney;
			for(j=0;j<31;++j)
			{
				res[j]=b[j];
			}
			b[i-1]=false;
		}
		return;
	}

	if (i>various-1)
	{
		if (maxkinds<kinds || maxkinds==kinds && money>maxmoney)
		{
			maxkinds=kinds;
			maxmoney=money;
			for(j=0;j<31;++j)
			{
				res[j]=b[j];
			}
		}
		return;
	}
	work(omoney,money,kinds,i+1);
	if (panduan(i))
	{
		b[i]=true;
		work(money,money+v[i].price,kinds+1,i+1);
		b[i]=false;
	}
}

bool cmp(const Fish &a,const Fish &b)
{
	return a.num<b.num;
}
int main()
{
	int num1,num2;
	int temp;
	int i;
	set <int> res1;
	set <int>::iterator r;
	while(cin>>fund)
	{
		res1.clear();
		maxkinds=0;
		maxmoney=0;
		memset(b,false,sizeof(b));
		memset(map,true,sizeof(map));
		cin>>various;
		for(i=0;i<various;++i)
		{
			cin>>v[i].num;
			cin>>v[i].price;
		}
		while(cin>>num1>>num2,num1!=0||num2!=0)
		{
			map[num1][num2]=false;
			map[num2][num1]=false;
		}
		work(0,0,0,0);
		cout<<maxkinds<<" "<<maxmoney<<endl;
		for(i=0;i<various;++i)
		{
     			if (res[i]==true) res1.insert(v[i].num);
		}
		for(r=res1.begin();r!=res1.end();++r)
		{
			cout<<*r<<endl;
		}
	}
	return 0;
}