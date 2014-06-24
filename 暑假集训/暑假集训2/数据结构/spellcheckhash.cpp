#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;


struct node 
{
	string str;
	int loc;
};

struct Length
{
	vector<node> str;
};


bool cmp(const node &a,const node &b)
{
	return a.loc<b.loc;
}
int judge(const string &a,const string &b)
{
	int count1,i,j;
	if (a==b) return 0;
	if (abs(int(a.size()-b.size()))>1) return 2;
	if (a.size()==b.size())
	{count1=0;
	for(i=0;i<int(a.size())&&i<int(b.size());++i)
	{
		if (a[i]!=b[i]) {++count1;if (count1==2) break;continue;}
	}
	return count1;
	}
	if (a.size()>b.size())
	{
		count1=0;
		for(i=0,j=0;i<int(a.size()) && j<int(b.size());++i,++j)
		{
			if (a[i]!=b[j]) 
			{
				++count1;
				if (count1==2) break;
				--j;
				continue;
			}
		}
		if (count1==0 || count1==1) return 1;
	}

	if (a.size()<b.size())
	{
		count1=0;
		for(i=0,j=0;i<int(a.size()) && j<int(b.size());++i,++j)
		{
			if (a[i]!=b[j]) 
			{
				++count1;
				if (count1==2) break;
				--i;
				continue;
			}
		}
		if (count1==0 || count1==1) return 1;
	}
	return 2;
}

int main()
{
	int loc=0;
	node temp;
	string str;
	vector<node> res;
	Length l[15];
	int i;
	//freopen("1.txt","w",stdout);
	while(cin>>temp.str,temp.str!="#")
	{
		temp.loc=loc++;
		l[int(temp.str.size())-1].str.push_back(temp);
	}

	while(cin>>str,str!="#")
	{
		int len;
		len=int(str.size());
		res.clear();
		for(i=0;i<int(l[len-1].str.size());++i)
		{
			if (judge(str,l[len-1].str[i].str)==0) break;
			if (judge(str,l[len-1].str[i].str)==1) res.push_back(l[len-1].str[i]);
		}
		if (i<int(l[len-1].str.size())) {cout<<str<<" is correct"<<endl;continue;}
		if (len-1)
		{
			for(i=0;i<int(l[len-2].str.size());++i)
			{
				if (judge(str,l[len-2].str[i].str)==1) res.push_back(l[len-2].str[i]);
			}
		}
		if (len<15)
		{
			for(i=0;i<int(l[len].str.size());++i)
			{
				if (judge(str,l[len].str[i].str)==1) res.push_back(l[len].str[i]);
			}
		}
		sort(res.begin(),res.end(),cmp);
		cout<<str<<":";
		for(i=0;i<int(res.size());++i)
		{
			cout<<" "<<res[i].str;
		}
		cout<<endl;
	}
	return 0;
}