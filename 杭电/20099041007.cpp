#include<iostream>
#include<algorithm>
using namespace std;

typedef struct 
{
	int begin,end;
}elem;

bool cmp(const elem &a,const elem &b)
{
	if (a.begin==b.begin) return a.end<b.end;
	return a.begin+(a.end-a.begin+1)/2<b.begin+(b.end-b.begin+1)/2;
}

int main()
{
	int i,n;
	elem *a;
	while(cin>>n,n)
	{
		a=new elem[n+2];
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].begin,&a[i].end);
		}
		sort(a,a+n,cmp);
		a[0].end=a[0].begin+(a[0].end-a[0].begin+1)/2;
		for(i=0;i<n-1;i++)
		{
			if (a[i+1].begin>=a[i].end) {a[i+1].end=a[i+1].end-(a[i+1].end-a[0].begin+1)/2;continue;}
			if (a[i+1].end-(a[i+1].end-a[i+1].begin)/2>=a[i].end) {a[i+1].end=a[i].end+(a[i+1].end-a[i+1].begin+1)/2;continue;}
			break;
		}
		if (i==n-1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}