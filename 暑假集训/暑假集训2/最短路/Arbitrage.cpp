#include<iostream>
#include<string>
using namespace std;
typedef double elem_t;
#define MAXN 50
#define inf 0.0
int n;
string Money[MAXN];
elem_t mat[MAXN][MAXN];
elem_t Maxrate[MAXN][MAXN];


bool floyd_warshall(int n)
{
	int i,j,k;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			Maxrate[i][j]=mat[i][j];

	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
			{
				if (Maxrate[i][k]*Maxrate[k][j]>Maxrate[i][j])
				{
					Maxrate[i][j]=Maxrate[i][k]*Maxrate[k][j];
					if (i==j&& Maxrate[i][j]>1)
					{
						return true; 
					}
				}
			}
			return false;
}



int find1(const string &fstr)
{
	int i;
	for(i=0;i<n;++i)
	{
		if (fstr==Money[i]) return i;
	}
return -1;
}

int main()
{
	int i,j;
	int loc1,loc2;
	int m;
	double rate;
	string money1,money2;
	int casenum;
	casenum=0;
	while(cin>>n,n!=0)
	{
        ++casenum;
		for(i=0;i<n;++i)
		{
			cin>>Money[i];
		}
		cin>>m;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				mat[i][j]=0;
			}
		}
		while(m--)
		{
			cin>>money1>>rate>>money2;
			loc1=find1(money1);
			loc2=find1(money2);
			mat[loc1][loc2]=rate;
		}
		printf("Case %d: ",casenum);
        if (floyd_warshall(n)) puts("Yes");
		else puts("No");
	}
	return 0;
}