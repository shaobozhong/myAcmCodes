#include<iostream>
using namespace std;


__int64 C(__int64 n,__int64 m)
{
    __int64 i,c=1;
    i=m;
    while(i!=0)
        {c*=n;n--;i--;}
    while(m!=0)
        {c/=m;m--;}
    return c;
} 

int main()
{
	__int64 sum;
	__int64 n,m;
	//freopen("E.in","r",stdin);
	while(scanf("%I64d%I64d",&n,&m)>0&&(n!=0||m!=0))
	{
		if (n==0||m==0) {printf("1\n");continue;}
		sum=C(n+m,m);
		printf("%I64d\n",sum);
	}
	return 0;
}
