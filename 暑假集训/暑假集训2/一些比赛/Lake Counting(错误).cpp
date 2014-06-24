#include<iostream>
#include<string>
using namespace std;
int r,c;
string str[101];
bool panduan(int i,int j)
{

	if (i>=r-1||str[i+1][j]!='v')
	{
		if (i<=0||str[i-1][j]!='v')
		{
			if (j<=0||str[i][j-1]!='v')
			{
				if (j>=c-1 || str[i][j+1]!='v')
				{
					if (i>=r-1 ||j<=0 ||str[i+1][j-1]!='v')
					{
						if (i>=r-1||j>=c-1 ||str[i+1][j+1]!='v')
						{
							if (i<=0||j<=0 ||str[i-1][j-1]!='v')
							{
								if (i<=0||j>=c-1||str[i-1][j+1]!='v')
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}

int main()
{

	int i,j,count;
	while(cin>>r>>c)
	{
		count=0;
		for(i=0;i<r;++i)
		{
			cin>>str[i];
		}

		for(i=0;i<r;++i)
		{
			for(j=0;j<c;++j)
			{
				if (str[i][j]=='W')
				{
					if (panduan(i,j)) count++;
					str[i][j]='v';
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}