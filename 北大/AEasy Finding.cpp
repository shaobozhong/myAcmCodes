#include<iostream>
#include<vector>
using namespace std;
typedef struct
{
	int len;
	vector<int> num;
}col;
int main()
{
	bool result;
	bool *result_1;
	col *c;
	int n,m,i,j;
	bool a[17][301];
	while(cin>>n>>m)
	{
		result=true;
		c=new col[n];
		result_1=new bool[m];
		memset(result_1,false,sizeof(result_1));
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				for(j=0;j<m;j++)
				{
					cin>>a[i][j];
				}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if (a[j][i]) c[i].num.push_back(j);
			}
		}
		for(i=0;i<m;i++)
		{
			c[i].len=(int)c[i].num.size();
			if (c[i].len==0) {result=false;break;}
			if (c[i].len==n) {result=false;break;}
			if (c[i].len==1) 
			{
				for(j=0;j<(int)c[i].len;j++)
				{
					result_1[i]=true;
				}
			}
		}
        for(i=0;i<m;i++)
		{
            if (result_1[i]!=1)
			{
				for(j=0;j<n;j++)
				{
					if (c[j].len!=1&&a[j][i])
					{
						for(k=0;k<m;k++)
						{
							if (result_1[k]&&a[j][k]) break;
						}
						if (k==m) for(k=0;k<m;k++)
						{
							resutl_1[k]=result_1[k]||a[j][k];
						}
					}
				}
			}
		}
	}
	return 0;
}