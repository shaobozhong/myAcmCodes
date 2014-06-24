#include<iostream>
#include<string>
using namespace std;

string plus_1(const string &a,const string &b)
{
	int c,alen,blen,i,count,max,j,temp;
	string result;
	char *sum;
		c=0;
		count=0;
		alen=(int)a.size();
		blen=(int)b.size();
		if (alen>blen) max=alen+2; else max=blen+2;
		sum=new char[max];
		for(i=alen-1,j=blen-1;i>=0&&j>=0;i--,j--)
		{
			temp=a[i]-'0'+b[j]-'0'+c;
			c=temp/10;
			sum[count++]=temp%10+'0';
		}
		if (i>=0)
		{		
			for(;i>=0;i--)
			{
				temp=a[i]-'0'+c;
				c=temp/10;
				sum[count++]=temp%10+'0';
			}
		}
		else if (j>=0)
		{
			for(;j>=0;j--)
			{
				temp=b[j]-'0'+c;
				c=temp/10;
				sum[count++]=temp%10+'0';
			}
		}	
		if (c)sum[count++]=c+'0';
		for(i=count-1;i>=0;i--)
			result.push_back(sum[i]);
		return result;
}
int main()
{
	int n,i;
	string a,b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
	cout<<"Case "<<i<<":"<<endl;
	cout<<a<<" + "<<b<<" = ";
	cout<<plus_1(a,b);
if (i==n) cout<<endl;
else 
	cout<<endl<<endl;
	}
	return 0;
}

