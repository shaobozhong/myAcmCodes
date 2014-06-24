#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
	int s,e;
	double distance;
}farm;

bool cmp(const farm &a,const farm &b)
{
	return a.distance<b.distance;
}
int main()
{
    farm a[10001];
	bool judge;
	int n,temp,i,s,e,len,count;
	double distance;
	int father[101];
	while(cin>>n,n)
	{
		count=0;
		distance=0;
		len=n*(n-1)/2;
		for(i=1;i<=n;i++)
			father[i]=i;
		for(i=0;i<len;i++)
		{
			cin>>a[i].s>>a[i].e>>a[i].distance;
			if (a[i].s>a[i].e) {temp=a[i].s;a[i].s=a[i].e;a[i].e=temp;}
		}
		sort(a,a+len,cmp);
		i=0;
		while(i<len)
		{
			judge=true;
			s=a[i].s;
			e=a[i].e;
			while(father[s]!=s)
			{
				s=father[s];
			}
			while(father[e]!=e)
			{
				e=father[e];
			}
			if (e!=s) {count++;distance+=a[i].distance;father[a[i].e]=a[i].s;if (count==n-1) break;}
			i++;
		}
		cout<<distance<<endl;
}
	return 0;
}