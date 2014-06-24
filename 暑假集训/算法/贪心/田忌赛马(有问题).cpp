#include<iostream>
#include<algorithm>
using namespace std;

bool compare(const int &a,const int  &b)
{
	return a>b;
}

int main()
{
	int my[10001],op[10001];
	int n,i,win,opi,opn;
	while(cin>>n,n!=0)
	{
		win=0;
		for(i=0;i<=n-1;i++)
			cin>>my[i];
		for(i=0;i<=n-1;i++)
		{
			cin>>op[i];
		}
		sort(my,my+n,compare);
		sort(op,op+n,compare);
		opi=0;opn=n-1;
		for(i=0;i<=n-1;i++)
		{
			if (opi>opn) break;
			if (my[i]>op[opi]) {win++;opi++;}
			else 
			{
				while(my[n-1]>op[n-1])
				{
					win++;
					n--;
					opn--;
				}
				if (my[n-1]<op[opi]) win--;
				opi++;
				n--;
				i--;
			}
		}
		cout<<win*200<<endl;
	}
	return 0;
}