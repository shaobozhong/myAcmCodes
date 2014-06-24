#include<iostream>
#include<string>
using namespace std;
int r,c;
	string str[101];
void work(int i,int j)
{
	str[i][j]='v';
	if (i>0 && str[i-1][j]=='W') work(i-1,j);
	if (i<r-1 && str[i+1][j]=='W') work(i+1,j);
	if (j>0 && str[i][j-1]=='W') work(i,j-1);
	if (j<c-1 && str[i][j+1]=='W') work(i,j+1);
	if (i>0 &&j>0 &&str[i-1][j-1]=='W') work(i-1,j-1);
	if (i>0&&j<c-1 && str[i-1][j+1]=='W') work(i-1,j+1);
	if (i<r-1 && j>0 &&str[i+1][j-1]=='W') work(i+1,j-1);
	if (i<r-1 && j<c-1 && str[i+1][j+1]=='W') work(i+1,j+1);
}

int main()
{


	int count;
    bool la;
   int i,j;
	while(cin>>r>>c)
	{
		count=0;
		for(i=0;i<r;++i)
		{
			cin>>str[i];
		}
		la=true;

		while(la)
		{
			la=false;
			for(i=0;i<r&&la==false;++i)
			{
				for(j=0;j<c;++j)
				{
					if (str[i][j]=='W') 
					{
						count++;
						work(i,j);
						la=true;
						break;
					}
				}
			}
		}

		cout<<count<<endl;
	}
	return 0;
}