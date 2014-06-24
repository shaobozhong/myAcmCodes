#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int t,n;
	set<string> vis;
	set<string> ::iterator index;
	string  str,str1;
	int i,j;
	int count1;
	scanf("%d",&t);
	while(t--)
	{
		vis.clear();
		count1=0;
		scanf("%d",&n);
		cin>>str;
		vis.insert(str);
		for(i=1;i<n;++i)
		{
			cin>>str;
			str1=str;
			for(j=0;j<int(str.size());++j)
			{
				if (str[j]=='A') str1[j]='T';
				else if (str[j]=='T') str1[j]='A';
				else if (str[j]=='G') str1[j]='C';
				else if (str[j]=='C') str1[j]='G';
			}
			index=vis.find(str1);
				if (index!=vis.end())
				{
					count1++;
					vis.erase(index);
					continue;
				}
				vis.insert(str);
		}
		printf("%d\n",count1);
	}
	return 0;
}
