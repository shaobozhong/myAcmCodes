#include<iostream>
using namespace std;

int main()
{
	int s_n,s_result;
    cin>>s_n;
	s_result=1;
	while(s_n>1)
	{
		s_result*=s_n;
		s_n--;
	}
	cout<<s_result<<endl;
	return 0;
}
