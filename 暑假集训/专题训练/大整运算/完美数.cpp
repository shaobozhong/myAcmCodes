#include<iostream>
using namespace std;

int main()
{
	int per[6]={6,28,496,8128,33550336};
	int time,a,b,i;

	while(cin>>a>>b,a!=0||b!=0)
	{
		time=0;
		for(i=0;i<=4;i++)
		{
			if (per[i]>=a) break;
		}
		for(;i<=4;i++)
		{
		
			if (per[i]<=b) 
			{	time++;
				if (per[i+1]>b||(i==4)) break;
				cout<<per[i]<<" ";
			}
		}
		if (time!=0) cout<<per[i];
		else cout<<"No";
		cout<<endl;
	}
	return 0;
}