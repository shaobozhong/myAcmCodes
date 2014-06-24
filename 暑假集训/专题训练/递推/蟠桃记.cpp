#include<iostream>
using namespace std;

int work(int n)
{
	int result;
	if (n==1) return 1;
	else result=(work(n-1)+1)*2;
	return result;
}

int main()
{
	int result;
	int n;
	while(cin>>n)
	{
		result=work(n);
		cout<<result<<endl;
	}
 return 0;
}