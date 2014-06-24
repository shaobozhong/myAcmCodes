#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

bool cmp(char a,char b)
{
	return a>b;
}

bool vis[12];
double a[6];
string str;
char b[6];
double n;
bool work(int i)
{
	int j;

	if (i==5) 
	{
		if (a[0]-pow(a[1],2)+pow(a[2],3)-pow(a[3],4)+pow(a[4],5)==n) return true;
		else return false;
	}
	for(j=0;j<int(str.size());++j)
	{
		if (vis[j])
		{   
			vis[j]=false;
			b[i]=str[j];
			a[i]=double(str[j])-64;
			if (work(i+1)) return true;
			vis[j]=true;
		}
	}
	return false;
}

int main()
{


	while(cin>>n>>str,n!=0||str!="END")
	{
		memset(vis,true,sizeof(vis));
		sort(str.begin(),str.end(),cmp);
		b[5]='\0';
		if (work(0)) cout<<b<<endl;
		else puts("no solution");
	}
	return 0;
}