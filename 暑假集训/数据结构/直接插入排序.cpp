#include<iostream>
using namespace std;
 int *num,sta,m;

void work()
 {
	 int i,j,temp,sta;
        cin>>m;
		num=new int[m];
		for(i=0;i<m;i++)
		{
			cin>>num[i];
		}
		cin>>sta;
		for(i=1;i<m;i++)
		{
			j=i;
			while(j>=1)
			{
				if (num[j]>=num[j-1]) break;
					temp=num[j];
					num[j]=num[j-1];
					num[j-1]=temp;
					j--;
			}
			if (i==sta) return;
		}
 }
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{		
		work();
		for(i=0;i<m;i++)
		{
			cout<<num[i]<<" ";
		}
		if (m>0) cout<<endl;
	}
	return 0;
}