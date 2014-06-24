#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name;
	double a[7],sum,min,max;
	int i;
	while(cin>>a[0])
	{
		sum=a[0];
		max=a[0];min=a[0];
		for(i=1;i<7;i++)
		{
			cin>>a[i];
			if (max<a[i]) max=a[i];
			else if (min>a[i]) min=a[i];
			sum+=a[i];
		}
		sum-=max+min;
		cin>>name;
		cout<<name<<" ";
		printf("%.2f\n",sum/5);
	}
	return 0;
}