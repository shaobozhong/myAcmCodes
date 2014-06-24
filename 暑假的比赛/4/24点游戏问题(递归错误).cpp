#include<iostream>
using namespace std;

int a[4];
bool la[4];

bool dfs(int i,double sum,int count)
{
	int j,k;
	if (i!=-1)
	{
		for(j=0;j<=3;++j)
		{
                    switch(j)
					{
					case 0:sum+=a[i];break;
					case 1:sum-=a[i];break;
					case 2:sum*=a[i];break;
					case 3:sum/=a[i];
					}
if (count==4)
	{
		if (sum==24)  
		{
			return true;
		}
		else
		{
			return false;
		}
	}
			for(k=0;k<=3;k++)
			{
				if (la[k])
				{
					
					la[k]=false;
					if (dfs(k,sum,count+1)) {return true;}
					la[k]=true;
				
					}
				}	
			}
		switch(j)
					{
					case 0:sum-=a[i];break;
					case 1:sum+=a[i];break;
					case 2:sum/=a[i];break;
					case 3:sum*=a[i];
		}
	}
	else 
	{
		for(j=0;j<=3;++j)
		{
			la[j]=false;
			if (dfs(j,0,count+1)) {return true;}
			la[j]=false;
		}
	}
	return false;
}

int main()
{
	while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])!=EOF) 
	{
		memset(la,true,sizeof(la));
		if (dfs(-1,0,0)) puts("YES");
		else puts("NO");
	}
	return 0;
}