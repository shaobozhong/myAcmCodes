#include<iostream>
#include<string>
using namespace std;
int pre;

string a[16000];

string plus_1(const string &a,const string &b)
{
	int c,alen,blen,i,count,max,j,temp;
	string result;
	char *sum;
		c=0;
		count=0;
		alen=(int)a.size();
		blen=(int)b.size();
		if (alen>blen) max=alen+5; else max=blen+5;
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

void work(int n)
{
	string temp,s;
	int i,j;
	for(i=pre+1;i<=n;i++)
	{
		a[i]=plus_1(a[i-1],a[i-2]);
		if (a[i].size()>9) 
		{
			for(j=0;j<5;j++)
			{
				temp.push_back(a[i][j]);
			}
			for(j=a[i].size()-4;j<a[i].size();j++)
			{
				temp.push_back(a[i][j]);
			}
			a[i]=temp;
			temp.clear();
		}
	}
	pre=n;
}

void print(string s)
{
	int i;
	if (s.size()<=8) cout<<s<<endl;
	else 
	{
		for(i=0;i<4;i++)
		{
			cout<<s[i];
		}
		cout<<"...";
		for(i=s.size()-4;i<s.size();i++)
		{
			cout<<s[i];
		}
		cout<<endl;
	}
}

int main()
{
    int n;
	a[0]="0";
	a[1]="1";
	a[2]="1";
	pre=2;
	while(scanf("%d",&n)!=EOF)
	{
		if (n>pre) 	
		{
			work(n);
		}
		print(a[n]);
	}

	return 0;
}