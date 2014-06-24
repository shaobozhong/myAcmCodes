/*写是写出来了  但是采用的是 穷举的方式 凭借set的和sort的出色发挥 在北大上Ac了  
但是看别人的时间 和内存发现差距很大   其实本题大可不必进行穷举  只要逐一匹配 差一个字符的就是可以的  
其中用长度可以筛掉一批  再就没办法 只能一个个字符来啦！！
不过也蛮有成就感  穷举也能冲过北大的数据   
*/
#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

set<string> dictionary;
vector<string> dic;
vector<string> res;

int find1(const string &str)
{
	int i;
	for(i=0;i<int(dic.size());++i)
	{
		if (dic[i]==str) return i;
	}
	return false;
}

bool cmp(const string &a,const string &b)
{
	return find1(a)<find1(b);
}

int main()
{

	int i,j;
	char ch[2];
	string str;
	string nstr;
	//freopen("2.txt","w",stdout);
	ch[1]='\0';
	while(cin>>str,str!="#")
	{
		dictionary.insert(str);
		dic.push_back(str);
	}

	while(cin>>str,str!="#")
	{
		res.clear();
		if (dictionary.find(str)!=dictionary.end()) 
		{
			cout<<str<<" is correct"<<endl; 
			continue;
		}
		cout<<str<<":";
		for(i=0;i<int(str.size());++i)
		{
			nstr=str;
			nstr.erase(i,1);
			if (dictionary.find(nstr)!=dictionary.end())
			{
				res.push_back(nstr);
			}
		}

		for(i=0;i<int(str.size());++i)
		{
			ch[0]='a';
			for(j=0;j<26;++j)
			{
				ch[0]='a'+j;
				nstr=str;
				nstr[i]=ch[0];
				if (dictionary.find(nstr)!=dictionary.end())
				{
					res.push_back(nstr);
				}
			}
		}

		for(i=0;i<=int(str.size());++i)
		{
			ch[0]='a';
			for(j=0;j<26;++j)
			{
				ch[0]='a'+j;
				nstr=str;
				nstr.insert(i,ch);
				if (dictionary.find(nstr)!=dictionary.end())
				{
					res.push_back(nstr);
				}
			}
		}

		sort(res.begin(),res.end(),cmp);

		for(i=0;i<int(res.size());++i)
		{
			if (!i||res[i]!=res[i-1]) cout<<" "<<res[i];
		}	
		cout<<endl;
	}

	return 0;
}