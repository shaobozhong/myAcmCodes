#include<iostream>
using namespace std;

int main()
{
	int p,e,i,d,test=0;
	while(cin>>p>>e>>i>>d)
	{
		test++;
		if (p==e&&e==i&&i==d&&d==-1) break;
        while(p!=e||e!=i||i<=d)
		{
			if (p<=e&&p<=i) p+=23;
			else if (p>=e&&i>=e) e+=28;
			else if (p>=i&&e>=i) i+=33;
		}
		cout<<"Case "<<test<<": the next triple peak occurs in "<<i-d<<" days."<<endl;
	}
	return 0;
}