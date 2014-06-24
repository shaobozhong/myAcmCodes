#include<iostream>
using namespace std;

char map[1500][1500];
int n,m;



void lable(int i,int j)
{
	char tmp;
	tmp=map[i][j];
	map[i][j]='A';
	switch(tmp)
	{
	case 'A':
		{
			return;
			break;
		}
	case 'B':
		{
			if (i+1<n &&(map[i+1][j]=='C' || map[i+1][j]=='D' || map[i+1][j]=='F') )
			{
				lable(i+1,j);
			}
            if (j-1>=0 &&(map[i][j-1]=='D' || map[i][j-1]=='E' || map[i][j-1]=='F'))
			{
				lable(i,j-1);
			}
			break;
		}
	case 'C':
		{
			if (i-1>=0 && (map[i-1][j]=='B' || map[i-1][j]=='E' || map[i-1][j]=='F'))
			{
				lable(i-1,j);
			}
			if (j-1>=0 &&(map[i][j-1]=='D' || map[i][j-1]=='E' || map[i][j-1]=='F'))
			{
				lable(i,j-1);
			}
			break;
		}
	case 'D':
		{
			if (i-1>=0 && (map[i-1][j]=='B' || map[i-1][j]=='E' || map[i-1][j]=='F'))
			{
				lable(i-1,j);
			}
            if (j+1<m &&(map[i][j+1]=='B' || map[i][j+1]=='C' || map[i][j+1]=='F'))
			{
				lable(i,j+1);
			}
			break;
		}
	case 'E':
		{
			if (i+1<n &&(map[i+1][j]=='C' || map[i+1][j]=='D' || map[i+1][j]=='F') )
			{
				lable(i+1,j);
			}
            if (j+1<m &&(map[i][j+1]=='B' || map[i][j+1]=='C' || map[i][j+1]=='F'))
			{
				lable(i,j+1);
			}
			break;
		}
	case 'F':
		{
            if (i-1>=0 && (map[i-1][j]=='B' || map[i-1][j]=='E' || map[i-1][j]=='F'))
			{
				lable(i-1,j);
			}
			if (j-1>=0 &&(map[i][j-1]=='D' || map[i][j-1]=='E' || map[i][j-1]=='F'))
			{
				lable(i,j-1);
			}
			if (i+1<n &&(map[i+1][j]=='C' || map[i+1][j]=='D' || map[i+1][j]=='F') )
			{
				lable(i+1,j);
			}
            if (j+1<m &&(map[i][j+1]=='B' || map[i][j+1]=='C' || map[i][j+1]=='F'))
			{
				lable(i,j+1);
			}
			break;
		}
	}
}



int main()
{
	int t;

	int i,j;
	int count1;
	scanf("%d",&t);
	while(t--)
	{
		count1=0;
		scanf("%d%d",&n,&m);
		getchar();
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				map[i][j]=getchar();
			}
			getchar();
		}

		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				if (map[i][j]!='A') 
				{
					++count1;
					lable(i,j);
				}
			}
		}
		printf("%d\n",count1);
	}
	return 0;
}