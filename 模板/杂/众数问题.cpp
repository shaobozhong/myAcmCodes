#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
	int max,maxnum;
	map<int,int>a;
	map<int,int>::iterator back;
	int n,num;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		while(n--)
		{
			scanf("%d",&num);
			back=a.find(num);
			if (back==a.end()) a.insert(make_pair(num,1));
			else 
			{
				back->second++;
				if (max<back->second)
				{
					max=back->second;
					maxnum=num;
				}
				if (max==back->second)
				{
					if (maxnum>num) maxnum=num;
				}
			}
		}
		cout<<maxnum<<endl<<max<<endl;
	}
	return 0;
}