// http://acm.timus.ru/problem.aspx?space=1&num=1011
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int cityzen;
	double p,q;
	double a,b;
	while(cin>>p>>q)
	{
		cityzen=1;
		while(1)
		{
			a=cityzen*p*0.01;
			b=cityzen*q*0.01;
			if (abs(floor(b)-b)>0.000001 && (floor(b)>floor(a))) break;
			cityzen++;
		}
		cout<<cityzen<<endl;
	}
	return 0;
}