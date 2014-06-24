#include<iostream>
using namespace std;

int *num,m;

void shell_insert(int add)
{
	int i,j,temp;
	for(i=add;i<m;i++)
	{
		j=i;
		while(j>=add)
		{
			if (num[j]>=num[j-add]) break;
			temp=num[j];
			num[j]=num[j-add];
			num[j-add]=temp;
			j-=add;
		}

	}
}

int main()
{
	int t,i,n,add;
	cin>>t;
	while(t--)
	{
		cin>>m;
		num=new int[m];
		for(i=0;i<m;i++)
		{
			cin>>num[i];
		}
		cin>>n;
		while(n--)
		{
			cin>>add;
			shell_insert(add);
			for(i=0;i<m;i++)
			{
				cout<<num[i]<<" ";
			}
			if (m>0)cout<<endl;

		}
	}
	return 0;
}