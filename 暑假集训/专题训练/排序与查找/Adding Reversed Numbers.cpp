#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
	int c,n,alen,blen,i,count,max,k,j,temp,elen,dlen;
	char *sum;
	string a,b,e,d;
	cin>>n;
	for(k=1;k<=n;k++)
	{
		a="";
		b="";
		c=0;
		count=0;
		cin>>e>>d;
		elen=(int)e.size();
		dlen=(int)d.size();
		for(i=elen-1;i>=0;i--)
		{
			if (e[i]!='0') break;
		}
		for(;i>=0;i--)
		{
			a.push_back(e[i]);
		}
        for(i=dlen-1;i>=0;i--)
		{
			if (d[i]!='0') break;
		}
		for(;i>=0;i--)
		{
			b.push_back(d[i]);
		}
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
		if (c!=0) sum[count++]=c+'0';
        for(i=0;i<=count-1;i++)
		if (sum[i]!='0') break;
		for(;i<=count-1;i++)
			cout<<sum[i];
           cout<<endl;
		   free(sum);

	}
	return 0;
}
