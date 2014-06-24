#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>v;
	int a,b,t,temp;
	while(cin>>a>>b&&(a!=0||b!=0))
	{ 
		
		a%=10;
		if (a==1) {cout<<"1"<<endl;continue;}
		temp=a;
		v.push_back(a);
		while(1)
		{
			temp*=a;
			temp%=10;
			if (temp==v[0]) break;
			v.push_back(temp);
		}
		t=v.size();
		if (b>t) b=b%t;
		if (b==0) b=t;
		if (t==1) b=1;
		cout<<v[b-1]<<endl;
		v.clear();
	}
	return 0;
}