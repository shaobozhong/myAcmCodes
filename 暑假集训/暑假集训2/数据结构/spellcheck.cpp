#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;


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
	int i;
	string str;
	vector<string> dictionary;
	vector<string> res;
	while(cin>>str,str!="#")
	{
		dictionary.push_back(str);
	}

	while(cin>>str,str!="#")
	{
		res.clear();
		for(i=0;i<int(dictionary.size());++i)
		{
			if (judge(str,dictionary[i])==0) break;
			if (judge(str,dictionary[i])==1) res.push_back(dictionary[i]);
		}
		if (i<int(dictionary.size())) cout<<str<<" is correct\n";
		else 
		{
			cout<<str<<":";
			for(i=0;i<int(res.size());++i)
			{
				cout<<" "<<res[i];
			}
			cout<<endl;
		}
	}
	return 0;
}