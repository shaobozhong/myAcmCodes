#include<iostream>
using namespace std;

int main()
{
    int t,n,m,p,temp;
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&p);
		if (n==1||m==1) {printf("1\n");continue;}
		if (n>m) {temp=n;n=m;m=temp;}
        
	}
	return 0;
}