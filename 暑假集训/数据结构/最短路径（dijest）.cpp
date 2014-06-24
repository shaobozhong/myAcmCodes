#include<iostream>
#include<string>
using namespace std;
#define M 100
int map[M][M],dis[M];

int main()
{
	int n;
	char s;
	int slocal,i,j,lmin,min;
	bool la[M];
    string sign;
	cin>>sign;
		n=sign.size();
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>map[i][j];
			}
		}
		cin>>s;
		for(i=0;i<n;i++)
		{
			dis[i]=INT_MAX;
			la[i]=false;
		}
        for(i=0;i<n;i++)
		{
			if (sign[i]==s) {slocal=i;break;}
		}
		dis[slocal]=0;
		while(1)
		{
			lmin=-1;
			min=INT_MAX;
			for(i=0;i<n;i++)
			{
				if (!la[i]&&dis[i]<min) {lmin=i;min=dis[i];} 
			}
			if (lmin==-1) break;
			la[lmin]=true;
			for(i=0;i<n;i++)
			{
				if (map[lmin][i]&&dis[i]>dis[lmin]+map[lmin][i]) dis[i]=dis[lmin]+map[lmin][i];  
			}
		
			
		}
		for(i=0;i<n;i++)
		{
			if (i==slocal) continue;
			cout<<sign[i]<<": ";
			if (dis[i]==INT_MAX) cout<<"0"<<endl;
			else cout<<dis[i]<<endl;
		}
	
	return 0;
}