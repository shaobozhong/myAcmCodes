#include<iostream>
using namespace std;

typedef struct 
{
	int sum;
	int value;
}jump;

int main()
{
	jump t[1002];
	bool la;
	int max,i,j,count,vmax,n,value;
	while(cin>>n,n!=0)
	{
		max=0;
		count=1;
		for(i=1;i<=n;i++)
		{
			la=true;
			cin>>value;
			vmax=0;
			t[count].value=value;
			for(j=1;j<=count-1;j++)
			{
				if (t[j].value<value&&vmax<t[j].sum) 
				{
					t[count].sum=t[j].sum+value;
					vmax=t[j].sum;
					la=false;
				}
			}
			if (la) t[count].sum=value;
			if (max<t[count].sum) max=t[count].sum;
			count++;
		}
		cout<<max<<endl;
	}
	return 0;
}