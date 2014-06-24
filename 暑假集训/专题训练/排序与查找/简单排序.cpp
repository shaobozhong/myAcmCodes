#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int a,const int b)
{
	return a<b;
}

int main()
{
	int *a;
	int n,number,i;
	cin>>n;
	while(n--)
	{
		cin>>number;
		a=new int[number];
		for(i=0;i<number;i++)
			cin>>a[i];
		sort(a,a+number,cmp);
		for(i=0;i<number-1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[i]<<endl;
	}
}