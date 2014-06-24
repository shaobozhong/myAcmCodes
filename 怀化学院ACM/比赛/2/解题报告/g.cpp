#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=5000000;
bool ss[MAXN+1];
void getss()//筛选法求素数
{
	memset(ss,true,sizeof(ss));
	int to=sqrt(MAXN),i,j;
	for(i=2,ss[1]=false;i<=to;i++)
	{
		if(ss[i])
		    for(j=i*i;j<=MAXN;j+=i) ss[j]=false;
	}
}
int main()
{
	int T,n;
	getss();
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		ss[n]?puts("YES"):puts("NO");
	}
	return 0;
}