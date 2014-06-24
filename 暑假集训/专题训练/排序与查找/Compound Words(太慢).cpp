#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[120000],str,result[120000];
typedef struct
{
	int sloca,length;
}con;

bool cmp(const string &a,const string &b)
{
	return a.length()>b.length();
}
bool cmpr(const string &a,const string &b)
{
	return a<b;
}
int main()
{

	con sloca;
	bool la;
	int count=0,i,j,k,zcount=0;
	while(cin>>s[count])
	{
		count++;
	}
    sort(s,s+count,cmp);
	for(i=0;i<count;i++)
	{
		if (s[i].length()>1)
		{
			la=true;
			for(j=i+1;j<count;j++)
			{
				if (s[i].length()>s[j].length())
				{
					str=s[i];
					if (str.find(s[j])!=-1) 
					{
						sloca.length=s[j].length();
						sloca.sloca=str.find(s[j]);
						for(k=j+1;k<count;k++)
						{
							if (s[k].length()==s[i].length()-sloca.length&&s[i].find(s[k])!=-1)
							{
								
								
									if (sloca.sloca==s[k].length()||s[i].find(s[k])==sloca.length)
									{
										result[zcount++]=s[i];
										la=false;
										break;
									}
								
							}
						}

					}
					if (!la) break;
				}
			}
		}
	}
	sort(result,result+zcount,cmpr);
	for(i=0;i<zcount;i++)
		cout<<result[i]<<endl;
	return 0;
}