#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
	int i;
	vector<int> res;
	scanf("%d",&n);
	while(n--)
	{
		res.clear();
		int num;
		scanf("%d",&num);
		while(num!=1)
		{
			switch(num%2)
			{
			case 0:num/=2;break;
			case 1:res.push_back(num);num=num*3+1;
			}
		}
		if (res.size()==0) {puts("No number can be output !");continue;}
		for(i=0;i<int(res.size())-1;++i)
		{
			printf("%d ",res[i]);
		}
		printf("%d\n",res[i]);
		
	}
	return 0;
}