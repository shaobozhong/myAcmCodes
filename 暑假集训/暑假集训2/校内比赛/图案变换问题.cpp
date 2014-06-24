//根据90度的  递推就可以了 实现旋转不要依次判断  直接在一个函数里面递推的可能是有的  不过我没能实现
#include<iostream>
using namespace std;

char map1[102][102];
char map2[102][102];
int n;

bool idt()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[i][j]) return false;
		}
	}
	return true;
}

bool rot90()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[j][n-i+1]) return false;
		}
	}
	return true;
}

bool rot180()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[n-i+1][n-j+1]) return false;
		}
	}
	return true;
}

bool rot270()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[n-j+1][i]) return false;
		}
	}
	return true;
}

bool vr()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[n-i+1][j]) return false;
		}
	}
	return true;
}

bool vr_rot90()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[j][i]) return false;
		}
	}
	return true;
}

bool vr_rot180()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[i][n-j+1]) return false;
		}
	}
	return true;
}

bool vr_rot270()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if (map1[i][j]!=map2[n-j+1][n-i+1]) return false;
		}
	}
	return true;
}

int main()
{
	
	int i,j;
	int k;
	int casenum;
	casenum=0;
	while(cin>>n)
	{
		casenum++;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				cin>>map1[i][j];
			}
			for(j=1;j<=n;++j)
			{
				cin>>map2[i][j];
			}
		}
		

		if (idt()) printf("%d idt\n",casenum);
		else if (rot90()) printf("%d rot90\n",casenum);
		else if (rot180()) printf("%d rot180\n",casenum);
		else if (rot270()) printf("%d rot270\n",casenum);
		else if (vr()) printf("%d vr\n",casenum);
		else if (vr_rot90()) printf("%d vr-rot90\n",casenum);
		else if (vr_rot180()) printf("%d vr-rot180\n",casenum);
		else if (vr_rot270()) printf("%d vr-rot270\n",casenum);
		else printf("%d imp\n",casenum);

	}
	return 0;
}