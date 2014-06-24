#include<iostream>
#include<algorithm>
using namespace std;
int f[2001][1001];
bool cmp(const int &a,const int &b)
{
	return a<b;
}

int main()
{
	int i,j,temp;
	int a[2001];
	int n,k;
	while(cin>>n>>k)
	{
		for(i=0;i<=n-1;i++)
			cin>>a[i];
		sort(a,a+n,cmp);
		f[2][1]=(a[1]-a[0])*(a[1]-a[0]);
		for(i=3;i<=n;i++)
		{
			for(j=1;j<=i/2&&j<=k;j++)
			{

				if (j>=2)		temp=f[i-2][j-1]+(a[i-1]-a[i-2])*(a[i-1]-a[i-2]);
				else   temp=(a[i-1]-a[i-2])*(a[i-1]-a[i-2]);
				f[i][j]=temp<f[i-1][j]?temp:f[i-1][j];


			}
			f[i][j]=2147483646;
		}
		cout<<f[n][k]<<endl;
	}
	return 0;
}

/*动态方程
一个结点有两个来路  
f[i][j]=min{f[i-1][j],f[i-2][j-1]+(a[i-1]-a[i-2])*(a[i-1]-a[i-2])};
*/