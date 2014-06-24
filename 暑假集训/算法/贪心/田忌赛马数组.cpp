#include<iostream>
#include<algorithm>
using namespace std;

bool compare(const int &a,const int  &b)
{
	return a>b;
}

int main()
{
	int my[1002],op[1002];
	int n,start,i,j,money,count;
	while(cin>>n,n!=0)
	{
		count=0;
		money=0;
		for(i=0;i<=n-1;i++)
			cin>>my[i];
		for(i=0;i<=n-1;i++)
		{
			cin>>op[i];
		}
		sort(my,my+n,compare);
		sort(op,op+n,compare);
		start=0;
		for(i=0;i<=n-1;i++)
		{
			for(j=start;j<=n-1;j++)
			{
				if (my[i]>op[j])
				{
				    money+=200;
                    count++;
					start=j+1;
					break;
				}
			}
		}
		cout<<money-(n-count)*200<<endl;
	}
	return 0;
}