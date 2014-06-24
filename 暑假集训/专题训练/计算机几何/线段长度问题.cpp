#include<iostream>
#include<algorithm>
using namespace std;


typedef struct 
{
	double start,end;
}Interzone;

bool cmp(const Interzone &a,const Interzone &b)
{
	if (a.start==b.start) return a.end<b.end;
	return a.start<b.start;
}

int main()
{
	double sum;
	Interzone a[10001];
	int t,n,i,j,count;
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i].start>>a[i].end;

		sort(a,a+n,cmp);
		sum=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if (a[i].end>=a[j].start&&a[j].end>a[i].end) a[i].end=a[j].end;
				else break;
			}
			sum+=a[i].end-a[i].start;
		i=j-1;
		}
		cout<<sum<<endl;
	}
	return 0;
}