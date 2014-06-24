#include<iostream>
using namespace std;

int main()
{
	int i,a[12],store,temp,k;
	temp=0;store=0;
	for(i=0;i<12;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<12;++i)
	{
		temp+=300;
		temp-=a[i];
		if (temp<0) break;
		if (temp>100) {k=temp/100*100;store+=k;temp-=k;}
	}
	if (i<12) cout<<"-"<<i+1<<endl;
	else 
	{
		cout<<temp+store*1.2<<endl;
	}

	return 0;
}