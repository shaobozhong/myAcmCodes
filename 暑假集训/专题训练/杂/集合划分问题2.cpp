#include<iostream>
using namespace std;

int work(int n,int m)
{
	if (m==1) return 1;
	if (m==n) return 1;
	return work(n-1,m-1)+work(n-1,m)*m;
}

int main()
{
    int n,m,result;
	while(cin>>n>>m)
	{
		result=work(n,m);
		cout<<result<<endl;
	}
	return 0;
}