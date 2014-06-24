//广度中把步数交给各个节点自己去存储  可以达到更快的速度
#include<iostream>
#include<string>
#include<set>
using namespace std;

bool vis[65];
int dir[8][2]={{1,-2},{1,2},{-1,-2},{-1,2},{2,-1},{2,1},{-2,1},{-2,-1}};

int main()
{
	set<string> oex;//用来存 下一次要扩展的
	set<string> expand;//本次扩展的
	set<string> ::iterator ex;//迭代器  用来循环进行扩展
	string str;
	string s,e;
	int step;
	int i;
	bool la;
	while(cin>>s>>e)
	{
	    oex.clear();
		memset(vis,true,sizeof(vis));
		if (s==e) {cout<<"To get from "<<s<<" to "<<e<<" takes "<<0<<" knight moves."<<endl;continue;}
		oex.insert(s);
		step=0;
	    la=false;
		while(!la&&!oex.empty())
		{
			++step;
			expand=oex;
			oex.clear();
			for(ex=expand.begin();!la&&ex!=expand.end();++ex)
			{
				for(i=0;i<8;++i)
				{
					str=*ex;
					str[0]+=dir[i][0];
					str[1]+=dir[i][1];
					if (str[0]>='a' && str[0]<='h' &&str[1]<='8'&&str[1]>= '1'&&vis[(int(str[0]-'a'))*8+int(str[1]-'0')])
					{
					
						if (str==e)
						{
							la=true;
							break;
						}
						vis[(int(str[0]-'a'))*8+int(str[1]-'0')]=false;
						oex.insert(str);
					}
				}
			}

		}
	     cout<<"To get from "<<s<<" to "<<e<<" takes "<<step<<" knight moves."<<endl;
	}
	return 0;
}