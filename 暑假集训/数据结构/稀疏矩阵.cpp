#include<iostream>
using namespace std;
#define M 100

typedef struct
{
 int i[M],j[M],e[M];
}Node;


int main()
{
	Node s;
	int n,m,x,i,j;

	while(scanf("%d",&n)+1)
	{
		cin>>m;
    s.i[0]=n;s.j[0]=m;s.e[0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>x;
			if (x!=0)
			{
				s.i[s.e[0]]=i;
				s.j[s.e[0]]=j;
				s.e[s.e[0]++]=x;
			}
		}
		cout<<s.i[0]<<" "<<s.j[0]<<" "<<s.e[0]-1<<endl;
		for(i=1;i<=s.e[0]-1;i++)
		cout<<s.i[i]<<" "<<s.j[i]<<" "<<s.e[i]<<endl;
	}
	return 0;
}