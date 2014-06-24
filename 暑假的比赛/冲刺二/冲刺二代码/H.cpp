#include<iostream>
#include<math.h>
using namespace std;
const double pi=acos(-1.0);
int main()
{
	int t;
	int n;
	double r,q,res;
	cin>>t;
	int count=0;
	while(t--)
	{  
		count++;
		cin>>r>>n;
        q=pi/n;
		res=r*sin(q)/(1+sin(q));
		cout<<"Scenario #"<<count<<":"<<endl;
		
		printf("%.3f\n",res);
		if(t!=0) putchar('\n');
		
	}


return 0;
}
