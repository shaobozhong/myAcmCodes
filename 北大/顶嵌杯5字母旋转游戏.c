#include<stdio.h>
#include<malloc.h>

int main()
{
	char *map,dir;
	int i,j,m,n,x,y;
	scanf("%d%d",&m,&n);

	dir='r';
	map=(char*)malloc(m*n*sizeof(char));
	for(i=0;i<n*m;i++)
	{
		map[i]=0;
	}
	x=0;y=0;
	for(i=0;i<n*m;i++)
	{
		map[x*n+y]=i%26+65;
		switch(dir)
		{
		case 'r':y++;break;
		case 'l':y--;break;
		case 'u':x--;break;
		case 'd':x++;
		}
		if (y==n||(dir=='r'&&map[x*n+y]!=0)) 
		{
			y--;
			x++;
			dir='d';
		}
		else 
		{
			if (y==-1||(dir=='l'&&map[x*n+y]!=0))
			{
				y++;
				x--;
				dir='u';
			}
			else 
			{
				if (x==m||(dir=='d'&&map[x*n+y]!=0)) 
				{
					x--;
					y--;
					dir='l';
				}

				else 
				{
					if ((x==0&&i>n-1)||(dir=='u'&&map[x*n+y]!=0))
					{
						x++;
						y++;
						dir='r';
					}
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%4c",map[i*n+j]);
		}
		 putchar('\n');
	}

	return 0;
}