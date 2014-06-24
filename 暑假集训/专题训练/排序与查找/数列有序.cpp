#include<iostream>
using namespace std;



int main()
{
	bool in;
	int a[100];
	int n,m,i;
	while(cin>>n>>m,n!=0||m!=0)
	{  
		in=true;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n-1;i++)
		{
			if (m<a[i]&&in) {cout<<m<<" ";in=false;}
			cout<<a[i]<<" ";
		}
		if (in) {if(m<a[i]) cout<<m<<" "<<a[i]<<endl;else cout<<a[i]<<" "<<m<<endl;}
		else cout<<a[i]<<endl;
	}

	return 0;
}