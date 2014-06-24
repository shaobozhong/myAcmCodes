#include<iostream>
using namespace std;

int main()
{
	int num[1000];
	int t,n,i,low,high,key,times,mid,loca;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		for(i=1;i<=n;++i)
		{
			cin>>num[i];
		}
		cin>>key;
		low=1;
		high=n;
		times=0;
		while(low<=high)
		{
			times++;
			mid=(low+high)/2;
			loca=mid;
			if (num[loca]==key) break;
			if (key<num[loca]) high=mid-1;
			if (key>num[loca]) low=mid+1;
		}
		if (low<=high) cout<<loca<<" "<<times<<endl;
		else cout<<"0 "<<times<<endl;
	}
	return 0;
}