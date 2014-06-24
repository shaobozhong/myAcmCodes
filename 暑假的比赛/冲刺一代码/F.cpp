#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,l;
	freopen("F.in","r",stdin);
	while(scanf("%d",&n),n!=0)
	{
		for(i=1;i<=n;i++)
		{
			for(j=3*n-i+1;j>=1;j--)
				printf(" ");
			cout<<"*";
			for(j=1;j<=2*i-3;j++)
				printf(" ");
			if(i!=1) printf("*");
			printf("\n");
		}
		cout<<"*";
		for(i=1;i<=3*n;i++)
			cout<<" *";//88888
		cout<<endl;
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=n-i+1;j++)
				printf(" ");
			printf("*");
			for(j=1;j<=i*2-3;j++)
				printf(" ");
			if(i!=1) printf("*");
			for(j=1;j<=2*n+(n-i)*2+1;j++)
				printf(" ");
			printf("*");
			for(j=1;j<=i*2-3;j++)
				printf(" ");
			if(i!=1) printf("*");
			cout<<endl;
		}
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=n-i+1;j++)
				printf(" ");
			printf("*");
			for(j=1;j<=i*2-3;j++)
				printf(" ");
			if(i!=1) printf("*");
			for(j=1;j<=2*n+(n-i)*2+1;j++)
				printf(" ");
			printf("*");
			for(j=1;j<=i*2-3;j++)
				printf(" ");
			if(i!=1) printf("*");
			cout<<endl;
		}
		cout<<"*";
		for(i=1;i<=3*n;i++)
			cout<<" *";//88888
		cout<<endl;
		for(i=n;i>=1;i--)
		{
			for(j=3*n-i+1;j>=1;j--)
				printf(" ");
			cout<<"*";
			for(j=1;j<=2*i-3;j++)
				printf(" ");
			if(i!=1) printf("*");
			printf("\n");
		}
	}
	return 0;
}