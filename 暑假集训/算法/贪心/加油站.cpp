#include<iostream>
using namespace std;

int main()
{
	int temp,max,n,*a,count,i;
	cin>>max>>n;

	count=0;
	temp=max;
	a=new int[n+2];
	for(i=1;i<=n+1;i++)
	{
		cin>>a[i];
	}
	i=1;
	while(i<=n+1)
	{
		
		if (max<a[i]) {cout<<"NoSolution"<<endl;return 0;}
		if (temp<a[i]) {temp=max;count++;}
		temp=temp-a[i];
		i++;
	}
	cout<<count<<endl;
	free(a);
	
	return 0;
}