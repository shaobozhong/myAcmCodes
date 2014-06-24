#include<iostream>
using namespace std;

int main()
{
	int num,x;
	while(cin>>num)
	{
		x=8;
		while(num==0&&x)
		{
			cin>>num;
			x--;
		}
		if (x!=-1) 
		{
			if (x!=0)
			{
				if (num!=1&&num!=-1) cout<<num;
				if (num==-1) cout<<"-";
		        if (x>1) cout<<"x^"<<x;
				if (x==1) cout<<"x";
			}
			else cout<<num;
		x--;
		}
		else cout<<"0";
		while(x+1)
		{
			cin>>num;
			if (num)
			{
				if (num>0) cout<<" + ";
				if (num<0) cout<<" - ";
				num=abs(num);
				if (num!=1&&x!=0)cout<<num;
				if (x==0) cout<<num;
		        if (x>1) cout<<"x^"<<x;
				if (x==1) cout<<"x";
			}
			x--;
		}
		cout<<endl;
	}
	return 0;
}