#include<iostream>
using namespace std;
int resultweight;
int m,w;
int a[11];
void the_m(int i,int tempweight)
{
	if (tempweight<=w&&tempweight>resultweight) {resultweight=tempweight;}
	if (tempweight>w) 
	{
		if (tempweight-a[i-1]>resultweight)
			resultweight=tempweight-a[i-1];
		return;
	}
	if (i>m-1) return;
	the_m(i+1,tempweight+a[i]);
	the_m(i+1,tempweight);
}
int main()
{

	int n,i;
	cin>>n;
	for(;n>=1;n--)
	{
		resultweight=0;
		cin>>m>>w;
		for(i=0;i<m;i++)
			cin>>a[i];
		the_m(0,0);
		cout<<resultweight<<endl;
	}
	return 0;
}