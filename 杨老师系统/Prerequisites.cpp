#include<iostream>
#include<set>
using namespace std;



int main()
{
	set<int> al;
	int k,m;
	int num;
	int c,r,count1;
	bool res;
	while(scanf("%d",&k),k!=0)
	{
		al.clear();
		res=true;
		scanf("%d",&m);
		while(k--)
		{
			scanf("%d",&num);
			al.insert(num);
		}

		while(m--)
		{
			scanf("%d%d",&c,&r);
			count1=0;
			while(c--)
			{
				scanf("%d",&num);
				if (res)
				{
					if (al.count(num)>0) ++count1;
				}
			}
			if (res) {if (count1<r) res=false; }
		}
		if (res) puts("yes");
		else puts("no");
	}
	return 0;
}

