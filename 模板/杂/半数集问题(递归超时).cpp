#include<iostream>
using namespace std;

int sata(int x)
{
	int i;
	int result=x/2;
	 if (x==1) return 0;
	 for(i=1;i<=x/2;i++)
		 result+=sata(i);
	 return result;
}

int main()
{
	int n,result;
	while(cin>>n)
	{
       result=sata(n);
	   cout<<result+1<<endl;
	}
	return 0;
}