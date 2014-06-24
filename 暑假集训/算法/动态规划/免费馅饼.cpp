#include<iostream>
using namespace std;

int a[12][100005];

int main()
{
	int max,n,i,j,loca,time,rmax;
	while(scanf("%d",&n)>0&&n!=0)
	{
		rmax=0;
		max=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
		{
		  scanf("%d%d",&loca,&time);
		  a[loca][time]++;
		  if (max<time) max=time;
		}
		/*for(i=0;i<=max;i++)
		{
			for(j=1;j<=10;j++)
			{
				cout<<a[j][i]<<" ";
			}
			cout<<endl;
		}*/
		for(i=max-1;i>=0;i--)//从倒数第二行开始求各个值
		{
			for(j=0;j<=10;j++)
			{
				if (j!=0)
				{
				rmax=a[j][i+1]>a[j-1][i+1]?a[j][i+1]:a[j-1][i+1];
				if (rmax<a[j+1][i+1]) rmax=a[j+1][i+1];
				a[j][i]+=rmax;
				}
				else 
				{
					rmax=a[j][i+1]>a[j+1][i+1]?a[j][i+1]:a[j+1][i+1];
					a[j][i]+=rmax;
				}
			}
		}
		/*for(i=0;i<=max;i++)
		{
			for(j=1;j<=10;j++)
			{
				cout<<a[j][i]<<" ";
			}
			cout<<endl;
		}*/
		printf("%d\n",a[5][0]);

	}
	return 0;
}

//数字金字塔式解法