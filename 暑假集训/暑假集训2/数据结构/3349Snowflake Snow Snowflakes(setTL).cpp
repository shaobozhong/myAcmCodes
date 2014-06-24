#include<iostream>
#include<string>
#include<set>
using namespace std;

string numtoa(int num)
{
	string res;
	char ch[2];
	int t;
	ch[1]='\0';
	while(num)
	{
		t=num%10;
		ch[0]=char(t+48);
		res.insert(0,ch);
		num/=10;
	}
	return res;
}

int main()
{
	int a[6];
	int min1;
	set<string> vis;
	string str;
	string ch;
	int n,i;
	int loc;
	bool la;
	cin>>n;
		la=false;
		while(!la&&n--)
		{
			
			scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
			min1=a[0];
			loc=0;
			for(i=1;i<6;++i)
			{
				if (min1>a[i]) {min1=a[i];loc=i;}
			}
			str="";
			for(i=1;i<=6;++i)
			{
				ch=numtoa(a[loc]);
				loc+=1;
				if (loc>=6) loc%=6;
				str+=ch;
			}
			if (vis.find(str)!=vis.end()) 
			{
				puts("Twin snowflakes found.");
				la=true;
				break;
			}
			vis.insert(str);
			str="";
			for(i=1;i<=6;++i)
			{
				ch=numtoa(a[loc]);
				loc-=1;
				if (loc<0) loc=5;
				str+=ch;
			}
			if (vis.find(str)!=vis.end()) 
			{
				la=true;
				puts("Twin snowflakes found.");
				break;
			}
		}

		if (!la) puts("No two snowflakes are alike.");
	
}