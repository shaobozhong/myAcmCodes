#include<iostream>
using namespace std;
int a[101][101];


void work(int rs,int cs,int ds)
{
	int i,j;
	int max=0;
	for(i=rs;i<=rs+2;++i)
	{
		for(j=cs;j<=cs+2;++j)
		{
			if(max<a[i][j]) max=a[i][j]; 
		}
	}
    for(i=rs;i<=rs+2;++i)
	{
		for(j=cs;j<=cs+2;++j)
		{
			if (a[i][j]>max-ds) a[i][j]=max-ds;
		}
	}

}
int main()
{
	int sum;
	int i,j;
	int r,c,dep,n,rs,cs,ds;
	while(cin>>r>>c>>dep>>n)
	{
		for(i=0;i<r;++i)
		{
			for(j=0;j<c;++j)
			{
				cin>>a[i][j];
			}
		}
		while(n--)
		{
			cin>>rs>>cs>>ds;
			work(rs-1,cs-1,ds);
		}
        sum=0;
		for(i=0;i<r;++i)
		{
			for(j=0;j<c;++j)
			{
				if (a[i][j]<dep) sum+=dep-a[i][j];
			}
		}

		sum*=72*72;
		cout<<sum<<endl;
	}
	return 0;
}