#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	bool result;
	int a[10];
	int n,i,temp;
	double pass;
	double  p;
	while(cin>>n>>p)
	{
		result=true;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,cmp);
	    pass=1;
		temp=0;
        for(i=0;i<n;i++)
		{
			if (a[i]-temp==1) {result=false;break;}
		    if (a[i]-temp==2) pass=pass*(1-p);
			else pass=pass*(1-+pass/2*p*(1-p);
			temp=a[i];
		}
		if (result) printf("%.7f\n",pass);
		else cout<<"0.0000000"<<endl;
	}
	
	return 0;
}