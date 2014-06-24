#include<iostream>
#include<set>
#include<limits>
using namespace std;

int G[1001][1001],D[1001][1001];

void Floyd_Washall(int n)
{
    int i,j,k;
    for (i=0;i<=n;i++)
        for (j=0;j<=n;j++)
            { D[i][j]=G[i][j];
            }
    for (i=0;i<=n;i++) { D[i][i]=0; }
    for (k=0;k<=n;k++)
        for (i=0;i<=n;i++)
            for (j=0;j<=n;j++)
                if (D[i][j]>D[i][k]+D[k][j])
                    { D[i][j]=D[i][k]+D[k][j];
                    }
}


int main()
{
	int a,b,dis,i,max,min,t,s,d,j;
	set<int> start,end;
	set<int>::iterator k,l;
	//freopen("1.txt","w",stdout);
	while(scanf("%d%d%d",&t,&s,&d)!=EOF)
	{
		max=0;
		min=INT_MAX;
		for(i=0;i<=1000;++i)
		{
			for(j=0;j<=1000;++j)
			{
				G[i][j]=9999999;
			}
		}
		for(i=1;i<=t;++i)
		{
			scanf("%d%d%d",&a,&b,&dis);
			if (dis<G[a][b])
			{
			G[a][b]=dis;
			G[b][a]=dis;
			}
			if (max<a) max=a;
			if (max<b) max=b;
		}
        Floyd_Washall(max);
		for(i=1;i<=s;++i)
		{
			scanf("%d",&a);
			start.insert(a);
		}
		for(i=1;i<=d;++i)
		{
			scanf("%d",&a);
			end.insert(a);
		}
		for(k=start.begin();k!=start.end();++k)
		{
			for(l=end.begin();l!=end.end();++l)
			{
				if (min>D[*k][*l]) min=D[*k][*l];
			}
		}
		printf("%d\n",min);
		start.clear();
		end.clear();
	}
	return 0;
}
