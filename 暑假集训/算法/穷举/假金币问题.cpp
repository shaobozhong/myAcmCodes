#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int main()
{
	bool lable[1002]={false};
	int a[1002];
	char ch;
	int n,k,i,m,num,ju,cheat,count,j;
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>m;
		for(j=1;j<=2*m;j++)
		{
			cin>>num;
			a[j]=num;
		}
		cin>>ch;
		if (ch=='<'||ch=='>')
		{
			for(j=1;j<=n;j++)
			{
				for(ju=1;ju<=2*m;ju++)
					if (j==a[ju]) break;
				if (ju>2*m) lable[j]=true;
			}
		}
		else 
		{
			for(j=1;j<=2*m;j++)
			{
				lable[a[j]]=true;
			}
		}
	}

	count=0;
	for(i=1;i<=n;i++)
	{
		if (lable[i]==false) 
		{
			cheat=i;
			count++;
		}
	}
	if (count==1) cout<<cheat<<endl;
	else cout<<"NO"<<endl;
	return 0;
}