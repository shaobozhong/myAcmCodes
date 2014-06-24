#include<iostream>
using namespace std;

int main()
{
	int t;
	int number,temp,max,i,num,begin,end,tbegin,tebegin,k;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		max=-1001;
		cin>>num;
		temp=0;
		begin=1;
		end=1;
		tebegin=1;
		for(i=1;i<=num;i++)
		{
			tbegin=tebegin;
			cin>>number;
			if (temp+number<number) {tbegin=i;tebegin=i;}
			temp=temp+number>number?temp+number:number;
			if (max<temp) {max=temp;begin=tbegin;end=i;}
		}
		cout<<"Case "<<k<<":"<<endl;  
		cout<<max<<" "<<begin<<" "<<end<<endl;
	    if(k!=t) cout<<endl;
	}
	return 0;
}