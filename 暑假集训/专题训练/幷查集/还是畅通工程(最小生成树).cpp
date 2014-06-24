#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector <int>u;
	bool la[101];
	double a[101][101];
	int n,temp,i,rs,re,len,count,j,temp1,temp2;
	double distance,sumdis,min;
	int father[101];
	while(cin>>n,n)
	{
		memset(la,true,sizeof(la));
		sumdis=0;
		count=0;
		distance=0;
		len=n*(n-1)/2;
		for(i=1;i<=n;i++)
			father[i]=i;
		for(i=0;i<len;i++)
		{
			cin>>rs>>re>>distance;
			if (rs>re) {temp=rs;rs=re;re=temp;}
			a[rs][re]=distance;
			a[re][rs]=distance;
		}
		count=1;
		u.push_back(1);
		while(count<n)
		{
			min=2100000000;
			temp1=-1;temp2=-1;
			for(i=0;i<(int)u.size();i++)
			{
				for(j=2;j<=n;j++)
				{
					if (la[j])
						if (min>a[u[i]][j]) {temp1=u[i];temp2=j;min=a[u[i]][j];}  
					
				}
			}
			u.push_back(temp2);
            sumdis+=a[temp1][temp2];
			la[temp2]=false;
			count++;
		}
	cout<<sumdis<<endl;
	u.clear();
}
return 0;
}