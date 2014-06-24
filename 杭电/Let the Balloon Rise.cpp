#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<string,int> m;
	int n;
	string str,color;
	color="";

	while(scanf("%d",&n)&&n!=0)
	{
		m.clear();
		while(n--)
		{
			cin>>str;
			   ++m[str];
			   if (color==""||m[str]>m[color])
			   {
				   color=str;
			   }
		}
		cout<<color<<endl;
	}
	return 0;
}