#include<iostream>
using namespace std;

typedef struct 
{
	int limit;
	int score;
	bool la;
}homework;

int main()
{
	homework h[1005];
	int j,t,n,i,max,smax,imax,osum,sum;
	cin>>t;
	for(;t>=1;t--)
	{
		osum=0;
		sum=0;
		max=0;
		cin>>n;
		for(i=0;i<=n-1;i++)
		{
			cin>>h[i].limit;
			if(max<h[i].limit) max=h[i].limit; 
		}
		
		for(i=0;i<=n-1;i++)
		{
			cin>>h[i].score;
			osum+=h[i].score;
			h[i].la=true;
		}

		for(i=max;i>=1;i--)
		{
			imax=-1;
			smax=0;
			for(j=0;j<=n-1;j++)
			{
				if (h[j].la&&h[j].limit>=i&&h[j].score>smax) {smax=h[j].score;imax=j;}
			}
			if (imax!=-1) {sum+=smax;h[imax].la=false;}
		}
		cout<<osum-sum<<endl;
         
	}

}