#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	char a[205],b[205];
	int count1,count2,blen;
	bool flag;
	int i,j;
	int casenum;
	string str;
	scanf("%d",&casenum);
	while(casenum--)
	{
		count1=0;
		scanf("%s%s",a,b);
		blen=int(strlen(b));
		for(i=0;i<blen;++i)
		{
			flag=true;
			count2=0;
			for(j=i;j<blen;++j)
			{
				if (a[j]!=b[j]) {flag=false;}
				if (j+1<blen && b[j]!=b[j+1]) break;
			}
			if (flag) {i=j;continue;}
			if (j>=blen)
			{
				count1+=1;
			}
			else 
			{
				count2=1;
				for(j=j+1;j<blen;++j)
				{
					 if (a[j]!=b[j]) ++count2;
					 if (j+1<blen && b[j]!=b[j+1]) break;
				}
				if (j>=blen)
				{
					count1+=count2<2?count2:2;
				}
				else 
				{
				for(j=j+1;j<blen;++j)
				{
					if (a[j]!=b[j]) ++count2;
					if (j+1<blen && b[j]!=b[j+1]) break;
				}
				count1+=count2<2?count2:2;
				}
			}
			i=j;
		}
		printf("%d\n",count1);
	}
	return 0;
}

