#include<iostream>
#include<algorithm>
using namespace std;

int a[49];
bool vis[49];
int n;
void work(int i,int getnum)
{
	int j;
	if (i>n) return;
	if (getnum==6)
	{
		for(j=0;j<n;++j)
		{
			if (vis[j]) cout<<a[j]<<" ";
		}
        //cout<<a[j]<<endl;
		cout<<endl;
		return;
	}
	vis[i]=true;
	work(i+1,getnum+1);
	vis[i]=false;
	work(i+1,getnum);
}

int main()
{
	int i;
	int casenum;
	casenum=0;
	while(cin>>n,n!=0)
	{
		if (casenum) cout<<endl;
		casenum++;
		for(i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		work(0,0);
	}
	return 0;
}