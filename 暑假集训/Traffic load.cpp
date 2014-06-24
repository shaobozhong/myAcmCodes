#include<iostream>
#include<set>
using namespace std;



int main()
{
	set <int> r1;
	set <int> r2;
	int casenum;
	int r,tmp,count1,i;
	bool flag;
	set <int> ::iterator goal;
	scanf("%d",&casenum);
	while(casenum--)
	{
		r1.clear();
		r2.clear();
		scanf("%d",&r);
		for(i=0;i<r;++i)
		{
			scanf("%d",&tmp);
			r1.insert(tmp);
		}

		for(i=0;i<r;++i)
		{
			scanf("%d",&tmp);
			r2.insert(tmp);
		}
        count1=0;
		while(!r1.empty())
		{
			flag=true;
			goal=r1.begin();
			if (r1.count(*goal+500)==0) 
			{
				flag=false;
			}
			else 
			{
				r1.erase(r1.find(*goal+500));
				if (r2.count(*goal+1000)==0) 
				{
					flag=false;
				}
				else 
				{
					r2.erase(r2.find(*goal+1000));
					if (r2.count(*goal+1500)==0) 
					{
						flag=false;
					}
					else 
					{
                       r2.erase(r2.find(*goal+1500));
					}
				}
			}
			if (flag) ++count1;
			r1.erase(r1.begin());
		}
		printf("%d\n",count1);
	}
	return 0;
}
