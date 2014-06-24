#include<iostream>
#include<string>
using namespace std;


string plus_1(const string &a,const string &b)
{
	string result;
	char ttemp[2];
	int alen,blen,i,j;
	int add,temp;
	ttemp[1]='\0';
	alen=a.size();
	blen=b.size();
	add=0;
	for(i=alen-1,j=blen-1;i>=0&&j>=0;i--,j--)
	{
		temp=add+((int)a[i]-48)+((int)b[j]-48);
		add=temp/10;
		ttemp[0]=temp%10+48;
		result.insert(0,ttemp);
	}

	while(i>=0)
	{
		for(;i>=0;i--)
		{
			temp=add+(a[i]-48);
			add=temp/10;
			ttemp[0]=temp%10+48;
			result.insert(0,ttemp);
		}
	}

	while(j>=0)
	{
		for(;j>=0;j--)
		{
			temp=add+(b[j]-48);
			add=temp/10;
			ttemp[0]=temp%10+48;
			result.insert(0,ttemp);
		}
	}
	if (add!=0)
	{ttemp[0]=add%10+48;
	result.insert(0,ttemp);
	}
	return  result;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string a,b,c;
	while(cin>>a>>b)
	{
		cout<<plus_1(a,b)<<endl;
	}
	return 0;
}