#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;


double map[55][201];
int week;

struct Work
{
	string job;
	double worktime;
};


int place(const string &str)
{
	int i,res,w;
	w=1;
	res=0;
	for (i=(int)str.size()-1;i>=0;--i)
	{
		if (str[i]=='b') break;
		res+=w*((int)str[i]-48);
	}
	return res;
}

double calcr(int j)
{
}

int main()
{
	Work temp;
	int n,i,j;
	double D,d[202];
	set<string> vis;
	while (scanf("%d",&n)!=EOF)
	{
		vis.clear();
		for (i=0;i<55;++i)
		{
			for (j=0;j<201;++j)
			{
				map[i][j]=0;
			}
		}
		week=1;
        for (i=1;i<=n;++i)
        {
			cin>>temp.job>>temp.worktime;
			if (temp.job==".") {map[week++][0]=temp.worktime; continue;}
            vis.insert(temp.job);
			map[week][place(temp.job)]=temp.worktime;
        }
		if (vis.size()>week) {puts("Incomplete data");continue;}
		D=calcr(0);
		if (D<=0.00001)  {puts("Incomplete data");continue;}
		for (i=1;i<=week;++i)
		{
			for (j=1;j<=week;++j)
			{

			}
			d[i]=calcr(i);
		}
	}

	return 0;
}