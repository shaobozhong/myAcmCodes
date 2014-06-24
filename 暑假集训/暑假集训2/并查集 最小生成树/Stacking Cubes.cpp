#include<iostream>
using namespace std;

int map[25][25];
int map1[25][25];

int main()
{
	int n,num;
	int i,j,k;
	int max1,max2;
	bool casenum=false;
	//freopen("1.txt","w",stdout);
	while(scanf("%d",&n),n!=0)
	{
		for(i=0;i<25;++i)
		{
			for(j=0;j<25;++j)
			{
				map[i][j]=0;
			}
		}
		max1=0;
		max2=0;
		if (casenum) printf("\n\n");
		casenum=true;
		for(i=0;i<n;++i)
		{
			j=0;
			while(scanf("%d",&num),num!=0)
			{
				map[i][j++]=num;
				if (max1<num) max1=num;
			}
			if (max2<j) max2=j;
		}

		for(k=0;k<max1;++k)
		{
			for(i=0;i<n;++i)
			{
				map1[k][i]=0;
				for(j=0;j<max2;++j)
				{
					if (map[i][j]!=0)
					{
						map[i][j]-=1;
						map1[k][i]+=1;
					}
				}
			}
		}

		for(i=0;i<max1;++i)
		{
			for(j=0;j<n;++j)
			{
				if (map1[i][j+1]==0) break;
				printf("%d ",map1[i][j]);
			}
			printf("%d",map1[i][j]);
			putchar('\n');
		}
		putchar('\n');
        
		for(k=0;k<max2;++k)
		{
			for(i=0;i<max1;++i)
			{
				map[k][i]=0;
				for(j=0;j<n;++j)
				{
					if (map1[i][j]!=0)
					{
						map1[i][j]-=1;
						map[k][i]+=1;
					}
				}
			}
		}

		for(i=0;i<max2;++i)
		{
			for(j=0;j<max1;++j)
			{
				if (map[i][j+1]==0) break;
				printf("%d ",map[i][j]);
			}
            printf("%d",map[i][j]);
			putchar('\n');
		}
	}
	return 0;
}