#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define eps 1e-6
struct Position
{
	double x,y;

};

struct Segment
{
		double sx,sy;
};

bool cmp(const Segment &a,const Segment &b)
{
	if (a.sx==b.sx) return a.sy<b.sy;
	return a.sx<b.sx;
}

int main()
{
	Segment  s[1001];
	Position p[1001];
	bool la;
	int casenum;
	int n,d,i;
	casenum=0;
	int count1;
	while(cin>>n>>d,n!=0||d!=0)
	{
		la=true;
		casenum++;
		for(i=0;i<n;++i)
		{
			cin>>p[i].x>>p[i].y;
			s[i].sx=p[i].x-sqrt(d*d-p[i].y*p[i].y);
			s[i].sy=p[i].x+sqrt(d*d-p[i].y*p[i].y);
			if (p[i].y>d) la=false;
		}
		if (!la) {printf("Case %d: %d\n",casenum,-1);continue;}
		sort(s,s+n,cmp);
		count1=1;
		for(i=1;i<n;++i)
		{
			if (s[i].sx<s[i-1].sy || abs(s[i].sx-s[i-1].sy)<=eps) 
			{
				s[i].sy=s[i-1].sy<s[i].sy?s[i-1].sy:s[i].sy;
			}
			else 
			{
				count1++;
			}
		}

		printf("Case %d: %d\n",casenum,count1);
	}
}