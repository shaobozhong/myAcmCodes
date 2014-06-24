#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,i;
	vector<int> v;
	int num;
	int a;
	__int64 sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		while(n--)
		{
			scanf("%d",&num);
			v.push_back(num);
		}
		make_heap(v.begin(),v.end(),cmp);
		while(v.size()!=1)
		{
			a=v.front();
			pop_heap(v.begin(),v.end(),cmp);
			v.pop_back();
			//make_heap(v.begin(),v.end(),cmp);
			a+=v.front();
			pop_heap(v.begin(),v.end(),cmp);
			v.pop_back();
			//make_heap(v.begin(),v.end(),cmp);
			v.push_back(a);
			push_heap(v.begin(),v.end(),cmp);
			sum+=a;
		}
		printf("%I64d\n",sum);
		v.pop_back();
	}
	return 0;
}

