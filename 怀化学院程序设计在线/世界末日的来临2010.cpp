#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	char a[205],b[205];
	int f[205];
	int blen,count1;
	int i,j;
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		count1=0;
		scanf("%s%s",a,b);
		blen=int(strlen(b));
		for(i=0;i<blen;++i)
		{
			f[i]=i+1;
		}
		for(i=0;i<blen;++i)
		{
			if (a[i]!=b[i])
			{
				if (i>0)
				{
					if (f[i]>f[i-1]+1) f[i]=f[i-1]+1;
				}
			}
			else 
			{
				if (i>0)
				{
					if (f[i]>f[i-1]) f[i]=f[i-1];
				}
				else 
				{
					f[i]=0;
				}
			}
			count1=0;
			for(j=i+1;j<blen;++j)
			{
				if (b[j]!=b[i] && b[j]!=b[j-1]) ++count1;
				
				if (i>0)
				{
					if (f[j]>f[i-1]+count1+1) f[j]=f[i-1]+count1+1;
				}
				else 
				{
					if (f[j]>count1+1) f[j]=count1+1;
				}
			}
		}
		printf("%d\n",f[blen-1]);
	}
	return 0;
}

