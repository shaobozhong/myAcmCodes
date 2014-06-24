#include<iostream>
using namespace std;

int main()
{
	int a[]={6 ,28 ,496 ,8128 ,33550336 };
    int i,m,n;
	bool la;
	
    while(cin>>m>>n,m!=0||n!=0)
	{
		la=true;
		for(i=0;i<5;i++)
		{
		
			if (a[i]>=m&&a[i]<=n) {cout<<a[i];la=false;}
			if (i<4&&a[i+1]<=n&&a[i]>=m) cout<<" ";
		}
		if (la) cout<<"No";
		cout<<endl;
	}
    return 0;
}
