#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
    double sum,temp;
	int num,j;
	vector<int> a;
	vector<int>::iterator i;
	int n;
	while(cin>>n)
	{
		sum=0;
		temp=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&num);
			a.push_back(num);
		}
		sort(a.begin(),a.end(),cmp);
		for(i=a.begin();i!=a.end();i++)
		{
			temp+=*i;
			sum+=temp;
		}
		printf("%.2lf\n",sum/n);
		a.clear();
	}
	return 0;
}