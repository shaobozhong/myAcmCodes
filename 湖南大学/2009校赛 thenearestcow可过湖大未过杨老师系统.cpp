#include<iostream>
using namespace std;

int a[1000005];
int main()
{
	double sum;
    int n,i,j,k,temp;
	//freopen("1.in","r",stdin);
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if ((i<n-1&&a[i]<a[i+1])||(i>=1&&a[i]<a[i-1])) {sum+=1;continue;}
            for(j=i-1;j>=0;j--)
			{
				if (a[j]>a[i]) break;
			}
			
				for(k=i+1;k<n;k++)
				{
					if (a[k]>a[i]) break;
				}
			temp=n;
			if (j>=0&&i-j<temp)
			{
				temp=i-j;
			}
			if (k<n&&k-i<temp)
			{
				temp=k-i;
			}
			sum+=temp;
			
		}
		printf("%.2f\n",sum/=n);
	}
	return 0;
}