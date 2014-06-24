#include<iostream>
#include<string>
using namespace std;

string str="pqrst";
string istr;
bool b[5];
int j;

bool judge()
{
	int i;
	j++;
	if (istr[j]=='K')
	{
		return judge()&judge();
	}
	else if (istr[j]=='A')
	{
		return judge()|judge();
	}
	else if (istr[j]=='C')
	{
		return !judge()|judge();
	}
	else if (istr[j]=='E')
	{
		return judge()==judge();
	}
	else if (istr[j]=='N')
	{
		return !judge();
	}
	else 
	{
		for(i=0;i<int(str.size());++i)
		{
			if (str[i]==istr[j]) return b[i];
		}
	}
	return true;
}

bool work(int i)
{
	if (i==5) 
	{
		j=-1;
		if (!judge()) return false;
		return true;
	}
	b[i]=true;
	if (!work(i+1)) return false;
	b[i]=false;
	if (!work(i+1)) return false;
	return true;
}
int main()
{
	freopen("2.txt","w",stdout);
    while(cin>>istr,istr!="0")
	{
		if (work(0)) cout<<"tautology"<<endl;
		else cout<<"not"<<endl;
	}
	return 0;
}