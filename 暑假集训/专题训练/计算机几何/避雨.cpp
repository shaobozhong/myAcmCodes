#include<iostream>
#include<math.h>
using namespace std;

double distance(int sx,int sy,int i,int j)
{
	return sqrt((double)((i-sx)*(i-sx)+(j-sy)*(j-sy)));
}

int main()
{
	char *a;
	double min,temp;
	int n,m,sx,sy,mex,mey,i,j,t;
	cin>>t;
    
	while(t--)
	{
		cin>>n>>m;
        getchar();
		min=2100000000;
		mex=-1;mey=-1;
		a=new char[n*m];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin.get(a[i*m+j]);
				if (a[i*m+j]=='s') {sx=i;sy=j;}
			}
			getchar();
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				temp=distance(sx,sy,i,j);
				if (a[i*m+j]=='d'&&temp<min) {min=temp;mex=i;mey=j;} 
			}
		}
			cout<<"("<<mex<<","<<mey<<")"<<endl;
	}
	return 0;
}