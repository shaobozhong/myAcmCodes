#include<iostream>
using namespace std;

int main()
{
	int i;
	double length,sum;
	while(cin>>length,length)
	{
		sum=0;
		for(i=1;;i++)
		{
			sum+=1.0/(i+1);
			if (sum>=length) break;
		}
		cout<<i<<" card(s)"<<endl;

	}
	return 0;
}