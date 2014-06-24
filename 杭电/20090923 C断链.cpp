#include<iostream>
using namespace std;

int main()
{
	int line,record[605],i,j,count;
	bool a[50];
	while(cin>>line,line!=0)
	{
		memset(a,false,sizeof(a));
		count=0;
        for(i=1;i<=line;i++)
		{
			for(j=1;j<=6;j++)
			{
				scanf("%d",&record[count++]);
			}
		}
		for(i=0;i<count;i++)
		{
			a[record[i]]=true;
		}
		for(i=1;i<=49;i++)
		{
			if (!a[i]) break;
		}
		if (i<=49) puts("No");
		else puts("Yes");
		
	}
}