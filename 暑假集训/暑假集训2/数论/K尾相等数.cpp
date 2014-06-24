#include<iostream>
using namespace std;
#define Ktail 1000

int main()
{
	int tail[1001];
	int i;
	int k,tm,n;
     cin>>n;
	while(n--)
	{
		cin>>k;
		memset(tail,0,sizeof(tail));
		i=1;
		tm=0;
		while(i<Ktail)
		{
			tm++;
			i*=k;
		}

		if (k>Ktail) {k%=Ktail;tm=1;}//·ÀÖ¹kÌ«´ó
		tail[i%Ktail]=tm;
		i%=Ktail;
		while(1)
		{
			tm++;
			i*=k;
		    i%=Ktail;
			if (tail[i]!=0)
			{
				break;
			}
			tail[i]=tm;
		}
		cout<<tail[i]+tm<<endl;
	}
	return 0;
}