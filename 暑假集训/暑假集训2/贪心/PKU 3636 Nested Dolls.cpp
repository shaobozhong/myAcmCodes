#include<iostream>
#include<algorithm>
using namespace std;

struct Doll
{
	int w,h;
	bool la;
};

bool cmp(const Doll &a,const Doll &b)
{
	if (a.w==b.w) return a.h>b.h;
	return a.w<b.w;
}

int main()
{ 
	Doll d[ 20001];
	int px[20001];
	int casenum;
	int n,i;
	int l,r,len,m;
	cin>>casenum;
	while(casenum--)
	{
		cin>>n;
		for(i=0;i<n;++i)
		{
			cin>>d[i].w>>d[i].h;
			d[i].la=false;
		}
		sort(d,d+n,cmp);
		len=0;
		for(int i = 0; i < n; ++i) 
		{
			l = 0;
			r = len;
			while(l < r) 
			{
				m = (l + r) / 2;
				if(px[m] >= d[i].h) l = m + 1;//w 已经排好 只看h
				else r = m;
			}
			if(len == l) len++;
			px[l] = d[i].h;
		}
		cout<<len<<endl;
	}
	return 0;
}