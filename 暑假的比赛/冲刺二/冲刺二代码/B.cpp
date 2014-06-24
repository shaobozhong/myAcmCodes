#include<iostream>
#include<cstring>
using namespace std;
int f[200004][101],w[2002],c[200];
int n,t,m,k;
int Max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
	int g,i,j;
	scanf("%d",&g);
	while(g--)
	{
		scanf("%d%d",&n,&m);
		j=1;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&c[j],&w[j],&t);
			for(k=2;k<=t;k++)
			{
				j++;
				c[j]=c[j-1];
				w[j]=w[j-1];
			}
		}
		memset(f,0,sizeof(f));
		m=j;
		for(i = 1; i <= n; i++)    
		{    
			for(j = 1; j <= m; j++)    
			{    
				k = j - w[i];    
				if(k > 0)    
				{    
					f[i][j] = Max(f[i - 1][j], f[i - 1][j - w[i]] + c[i]);    
				}    
				else   
				{    
					f[i][j] = f[i - 1][j];    
				}    
			}    
		}    
		for(i = 1; i <= n; i++)    
		{    
			/*for(j = 0; j <= m; j++)  
				printf("%d ",f[i][j]);
			cout<<endl;*/
			cout<<c[i]<<endl;
		}
	}
				return 0;
}

