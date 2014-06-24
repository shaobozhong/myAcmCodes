//针对有环的  如 1 2 2 3 3 1 4 5 会出现错误
#include<iostream>
#include<set>
using namespace std;

int main()
{
	int a,b;
	int side;
	set<int> vis;
	while(scanf("%d%d",&a,&b),a!=-1||b!=-1)
	{
		 if(a==0 && b==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }

		side=0;
		++side;
		vis.clear();
	    vis.insert(a);
		vis.insert(b);
		while(scanf("%d%d",&a,&b),a!=0||b!=0)
		{
			++side;
			vis.insert(a);
			vis.insert(b);
		}
		if (side==int(vis.size())-1) puts("Yes");
		else puts("No");
	}
	return 0;
}