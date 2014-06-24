/*
ID:shaoboz2
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

bool cmp(const int a,const int b)
{
	return a<b;
}

bool cmpr(const int a,const int b)
{
	return a<b;
}
int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
    vector<int>a;
	vector<int>b;
	int m,s,c,num,sum,i;
	fin>>m>>s>>c;
	if (m>=c) {fout<<c<<endl;return 0;}
	for(i=0;i<c;i++)
	{
		fin>>num;
		a.push_back(num);
	}
	sort(a.begin(),a.end(),cmp);
	sum=a[c-1]-a[0]+1;
	for(i=0;i<c-1;i++)
	{
		b.push_back(a[i+1]-a[i]);
	}

	sort(b.begin(),b.end(),cmpr);
	c-=2;
	while(m>=2&&b[c]!=1)
	{
      sum=sum-b[c]+1;
	  c--;
	  m--;
	}
	fout<<sum<<endl;
	return 0;
}