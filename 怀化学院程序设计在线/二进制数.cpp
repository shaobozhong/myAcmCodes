#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t,d,i,temp;
	vector<int> num;
	cin>>t;
	while(t--)
	{
		cin>>d;
		while(d)
		{
			temp=d%2;
			num.push_back(temp);
			d/=2;
		}
		for(i=0;i<(int)num.size();i++)
		{
			if (num[i]) cout<<i<<" ";
		}
		cout<<endl;
		num.clear();
	}
	return 0;
}