#include<iostream>
#include<string>
#include<set>
#include <vector>
using namespace std;
struct gather
{
	string  data;
	set<string> ga;
	bool la;
};

vector<gather> ga;
bool _find(const string &str)
{
	int i;
	set<string> ::iterator j;
   for (i=0;i<(int)ga.size();++i)
   {
	   if (str==ga[i].data) break;
   }
   if (i<(int)ga.size()) 
   {
        for (j=ga[i].ga.begin();j!=ga[i].ga.end();++j)
        {
			if (str==*j) return false;
        }
   }
	return true;
}

int main()
{
	bool la;
	int i,j,k;
	gather gatemp;
	
	string temp;
	string str;
    vector<string> _left;
	set<string> ::iterator l,m;
	while (getline(cin,str))//输入
	{
		temp=str.substr(0,6);
		_left.push_back(temp);
		for(i=0;i<(int)ga.size();++i)
		{
			if (ga[i].data==temp) break;
		}
		if (i<(int)ga.size())
		{
			for(j=6;j<(int)str.size();++j)
			{
				if (str[j]=='R') {temp=str.substr(j,6);ga[i].ga.insert(temp);j+=6;}
			}
		}
		else
		{
		gatemp.data=temp;
		 for(j=6;j<(int)str.size();++j)
		{
			if (str[j]=='R') {temp=str.substr(j,6);gatemp.ga.insert(temp);j+=6;}
		 }
		 ga.push_back(gatemp);
		}
	}
		for(i=0;i<(int)ga.size();++i)//标记是否需要再查
		{
			ga[i].la=true;
		}
		for(i=0;i<(int)ga.size();++i)//把子问题提取到主干
		{
			la=false;
			for (m=ga[i].ga.begin();m!=ga[i].ga.end();++m)
			{
				if (ga[i].data!=*m) 
				for(k=0;k<(int)ga.size();++k)
				{
					if (*m==ga[k].data&&ga[k].la) 
					{
						for (l=ga[k].ga.begin();l!=ga[k].ga.end();++l)
						{
							ga[i].ga.insert(*l);
						}
					    la=true;
						ga[k].la=false;
					}
				}
			}
			if (la) {--i;}
			else
			{
				for(j=0;j<(int)ga.size();++j)
				{
					ga[j].la=true;
				}
			}
		}
	for (i=0;i<(int)_left.size();++i)
	{
		cout<<_left[i]<<" ";
		if (_find(_left[i])) puts("ok");
		else puts("circular");
	}
	return 0;
}