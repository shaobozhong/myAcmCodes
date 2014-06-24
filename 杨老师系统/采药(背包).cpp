#include<iostream>
using namespace std;

int main()
{
	int res[105][1005];
	int v[105],t[105];
	int ti,m;
	int i,j;
	while(cin>>ti>>m)
	{
		for(i=1;i<=m;++i)
		{
			cin>>t[i]>>v[i];
		}

		for(i=0;i<=ti;++i)
		{
			res[0][i]=0;
		}
		for(i=0;i<=m;++i)
		{
			res[i][0]=0;
		}

		for(i=1;i<=m;++i)
		{
			for(j=1;j<=ti;++j)
			{
				res[i][j]=0;
				if (t[i]<=j)
				{
					res[i][j]=res[i-1][j-t[i]]+v[i];
				}
				if (res[i][j]<res[i-1][j]) res[i][j]=res[i-1][j];
				//if (res[i][j]<res[i][j-1]) res[i][j]=res[i][j-1];
			}
		}
		cout<<res[m][ti]<<endl;
	}
	return 0;
}