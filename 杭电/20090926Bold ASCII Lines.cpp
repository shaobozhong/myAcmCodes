#include<iostream>

using namespace std;

int main()
{
	int t,h,w,i,j;
	char map[103][103];
	scanf("%d",&t);
	while(t--)
	{
	
		memset(map[0],'.',sizeof(map[0]));
		scanf("%d%d",&w,&h);
		getchar();
	    memset(map[h+1],'.',sizeof(map[h+1]));
		for(i=1;i<=h;i++)
		{
			map[i][0]='.';
			map[i][w+1]='.';
			for(j=1;j<=w;j++)
			{
				scanf("%c",&map[i][j]);
			}
			getchar();
		}//¶ÁÈë
        for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				if (map[i][j]=='*')
				{
					if (map[i-1][j]!='*'&&map[i-1][j]!='@') map[i-1][j]='@';
					if (map[i+1][j]!='*'&&map[i+1][j]!='@') map[i+1][j]='@';
					if (map[i][j-1]!='*'&&map[i][j-1]!='@') map[i][j-1]='@';
					if (map[i][j+1]!='*'&&map[i][j+1]!='@') map[i][j+1]='@';
				}
			}
		}//Ìæ»»
		for(i=0;i<=h+1;i++)
			{
				for(j=0;j<=w+1;j++)
				{
					if (map[i][j]!='.') putchar('*');
					else putchar('.');
				}
				putchar('\n');
			}
			if (t) puts("---");//Êä³ö
	}
	return 0;
}