#include<iostream>
using namespace std;

#define infinity INT_MAX
#define max_vertexes 105

int G[max_vertexes][max_vertexes];

int  prim(int vcount)
{
	int father[max_vertexes];
	int sum=0;
    int i,j,k;
    int lowcost[max_vertexes],closeset[max_vertexes],used[max_vertexes];
    for (i=0;i<vcount;i++)
        {
        lowcost[i]=G[0][i];
        closeset[i]=0; 
        used[i]=0;
        father[i]=-1; 
        }
    used[0]=1; 
    for (i=1;i<vcount;i++)
        {
        j=0;
        while (used[j]) j++;
        for (k=0;k<vcount;k++)
			if ((!used[k])&&(lowcost[k]<lowcost[j])) {j=k;}
        father[j]=closeset[j]; 
		sum+=lowcost[j];
        used[j]=1;
        for (k=0;k<vcount;k++)
            if (!used[k]&&(G[j][k]<lowcost[k]))
                { lowcost[k]=G[j][k];
                closeset[k]=j; }
        }
	return sum;
}

int  main()
{
	int n,m;
	int a,b,dis;
	int i,j;
	while(scanf("%d",&n),n!=0)
	{
		m=n*(n-1)/2;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				G[i][j]=INT_MAX;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&dis);
			G[a-1][b-1]=dis;
			G[b-1][a-1]=dis;
		}
		printf("%d\n",prim(n));
	}
	return 0;
}
 



