#include<iostream>
using namespace std;


typedef struct  
{
  double x,y;
}Node;
double mutiply(Node a,Node b)
{
	double result;
	result =(a.x*b.y-a.y*b.x)/2;
	return result;
}
int main()
{
	
	Node a[101];
	double sum;
	int n,i;
	while(cin>>n,n)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
		 cin>>a[i].x>>a[i].y;
		}
        for(i=0;i<n-1;i++)
		{
			sum+=mutiply(a[i],a[i+1]);
		}
		sum+=mutiply(a[i],a[0]);
		printf("%.1f\n",sum);
	}
	return 0;
}