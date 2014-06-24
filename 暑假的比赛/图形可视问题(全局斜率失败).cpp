#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct
{
	int x,y,length;
}loca;
vector <loca> l;

typedef struct
{
	double s,e;
}slope;
vector <slope> pk,nk;

bool cmp(const slope &a,const slope &b)
{
	return a.s<b.s;
}

bool panduan(int i)
{
	
   return false;
}

int main()
{
	vector<int> num;
	vector <slope>::iterator k;
    loca temp;
	slope stemp;
	int n,i,count;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d%d%d",&temp.x,&temp.y,&temp.length);
			l.push_back(temp);
			stemp.s=temp.y/(temp.x+temp.length);
			stemp.e=(temp.y+temp.length)/(temp.x);
			if (stemp.s>=0) pk.push_back(stemp);
			else nk.push_back(stemp);
		}
		sort(pk.begin(),pk.end(),cmp);
		sort(nk.begin(),nk.end(),cmp);
		for(k=pk.end()-2;k>=pk.begin();--k)
		{
			if ((*k).e>=(*(k+1)).s)
			{
				(*k).e=(*k).e>(*(k+1)).e?(*k).e:(*(k+1)).e;
				pk.erase(k+1);
			}
		}
		for(k=nk.end()-2;k>=nk.begin();--k)
		{
			if ((*k).e>=(*(k+1)).s)
			{
				(*k).e=(*k).e>(*(k+1)).e?(*k).e:(*(k+1)).e;
				pk.erase(k+1);
			}
		}
		if (pk[pk.size()-1].e<0&&pk[pk.size()-1].e>=nk[0].s)
		{
			pk[pk.size()-1].e=pk[pk.size()-1].e>nk[0].e?pk[pk.size()-1].e:nk[0].e;
		}
		count=0;
		for(i=0;i<l.size();++i)
		{
			if (panduan(i)) {++count; num.push_back(i+1);}
		}
	}
	return 0;
}