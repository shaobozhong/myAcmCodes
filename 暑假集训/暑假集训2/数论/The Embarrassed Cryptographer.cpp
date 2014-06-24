#include<iostream>
#include<string>
using namespace std;
#define MAX 1000005

bool p[MAX];
int a[105];
int pr[MAX];
int len;
	int k;

void shai()
{
	int i,j;
	memset(p,true,sizeof(p));
	p[0]=false;
	p[1]=false;
	for(i=2;i*i<MAX;++i)
	{
		if (p[i])
		{
			for(j=i*i;j<MAX;j+=i)
			{
                 p[j]=false;
			}
		}
	}
}

bool mod(int n)
{
	int remain;
	int i;
	remain=0;
	for(i=0;i<k;++i)
	{
		remain=(remain*1000+a[i])%n;
	}
	if (remain) return false;
	return true;
}
int main()
{

    string knum;
	long long l;
    int i;
	bool la;
	shai();
	k=0;
	for(i=2;i<MAX;++i)
	{
		if (p[i]) pr[k++]=i;
	}

	while(cin>>knum>>l,knum!="0"||l!=0)
	{
		len=int(knum.size());
		switch(len%3)
		{
		case 1:a[0]=knum[0]-'0';break;
		case 2:a[0]=(knum[0]-'0')*10+knum[1]-'0';break;
		default:a[0]=0;
		}
		k=1;
		for(i=len%3;i<len;i+=3)
		{
			a[k++]=int(knum[i]-'0')*100+int(knum[i+1]-'0')*10+int(knum[i+2]-'0');
		}

        la=false;
		for(i=0;pr[i]<l;++i)
		{
			if (mod(pr[i])) {la=true; break;}
		}

		if (la)
		{
			printf("BAD %d\n",pr[i]);
		}
		else 
		{
			puts("GOOD");
		}
	}
	return 0;
}