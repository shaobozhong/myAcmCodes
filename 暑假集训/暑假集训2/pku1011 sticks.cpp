#include<iostream>
#include<algorithm>
using namespace std;
int n,l[65];

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int i;
    while(scanf("%d",&n),n!=0)
	{
       for(i=0;i<n;++i)
	   {
		   scanf("%d",&l[i]);
	   }
       sort(l,l+n,cmp);
	   dfs();
	}
	return 0;
}