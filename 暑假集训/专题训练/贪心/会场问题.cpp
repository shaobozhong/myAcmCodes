#include<iostream>
#include<algorithm>
using namespace std;

typedef struct 
{
	int start,end;
}Time;

bool cmp(const Time &a,const Time &b)
{
	if (a.start==b.start) return a.end<b.end;
	return a.start<b.start;
}


int main()
{
	bool *la;
	Time *a;
	int n,i,count,j,start;
	while(cin>>n)
	{
		count=0;
		a=new Time[n];
		la=new bool[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i].start>>a[i].end;
			la[i]=true;
		}
	    sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			if (la[i])
			{
				start=a[i].end;
                count++;
			   for(j=i+1;j<n;j++)
			   {
				   if (la[j]&&a[j].start>=start){la[j]=false;start=a[j].end;}
			   }
			}
		}
		cout<<count<<endl;
	}
	return 0;
}