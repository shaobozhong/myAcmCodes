#include <iostream>
#include <string.h>
#define Max 3000002
using namespace std;
long A[Max];
char B[Max];
long C[Max];
long X,n,x; 
void inset(int a)
{
	if(a>-Max/2&&a< Max/2) B[a+Max/2]=1;
	else C[X++]=a;
}
int Look(int a)
{
	if(a>-Max/2 && a<Max/2)	return B[a+Max/2];
	else
	{
		long i;
		for(i=0;i<X; i++)
			if(C[i] == a) return 1;
		return 0;
	}
}

int main()
{
	long i,j,m;
	int flag;
	while(scanf("%ld%ld",&n,&x)==2)
	{
		memset(B,0,Max);
		memset(C,0,Max*sizeof(long));
		X=0;
		flag=0;
		for(i=0; i<n;i++)scanf("%ld",&A[i]);
		for(i=0;i<n;i++)
		{
			if(Look(A[i]))
			{
				cout<<"YES"<<endl;
				i=n;
				flag=1;
				break;
			}
			else inset(x-A[i]);
		}
		if(flag==0) cout<<"NO"<<endl;
	}
	return 1;
}
