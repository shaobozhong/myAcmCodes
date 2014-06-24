/*
以地球为起点进行广度扩展，找到一个算一个 并且比较  就可以得到结果
*/
#include<iostream>
#include<string>
#include<set>
using namespace std;

bool map[28][28];

struct Plant//存储行星的信息 包括 标识 商品价格  价值的保有率
{
	char name;
	double value;
	string path;
};

Plant p[27];
	int n;
int position(char ch)
{
	int i;
	for(i=1;i<=n;++i)
	{
		if (p[i].name==ch) return i;
	}
	return -1;
}

int main()
{
	set<int> oex;
	set<int> expand;
	set<int>::iterator ex;
	double max1,temp;
	double rate;

	int i,j;
	int la;//存储下标
	char res;
	while(cin>>n)
	{
		for(i=0;i<=n;++i)
		{
			for(j=0;j<=n;++j)
			{
				map[i][j]=false;
			}
		}


		for(i=1;i<=n;++i)
		{
			cin>>p[i].name>>p[i].value>>p[i].path;
		}

		for(i=1;i<=n;++i)
		{
			for(j=0;int(j<int(p[i].path.size()));++j)
			{
				if (p[i].path[j]=='*') {map[0][i]=true;map[i][0]=true;}
				else 
				{
					la=position(p[i].path[j]);
					map[i][la]=true;
					map[la][i]=true;
				}
			}
		}
		oex.insert(0);
		max1=0;
		rate=1;
		while(1)
		{
			expand=oex;
			oex.clear();
			for(ex=expand.begin();ex!=expand.end();++ex)
			{

				for(i=1;i<=n;++i)
				{

					if (map[*ex][i])
					{
						for(j=1;j<=n;++j)
						{
							map[j][i]=false;
						}
						oex.insert(i);
						temp=p[i].value*rate;
						if (max1<temp ||(max1==temp && res>p[i].name)) 
						{
							max1=temp;
							res=p[i].name;
						}
					}

				}
			}
			if (oex.empty()) break;
			rate*=0.95;
		}
		cout<<res<<endl;
	}
	return 0;
}