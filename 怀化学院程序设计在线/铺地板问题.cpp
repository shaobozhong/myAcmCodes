#include<iostream>
using namespace std;
int m,w,l;
bool la;
void work(int i,int a[],int b[],int sum)
{
	if (i==m||sum>w*l) return;
	sum+=a[i]*b[i];
	if (sum==w*l) {la=false;return;}
	work(i+1,a,b,sum);
	work(i+1,a,b,sum-a[i]*b[i]);
}


int main()
{
	int a[15],b[15],t,i;
	cin>>t;
	while(t--)
	{
		la=true;
		cin>>w>>l>>m;
		for(i=0;i<=m-1;i++)
			cin>>a[i]>>b[i];
		work(0,a,b,0);
		if (la) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}