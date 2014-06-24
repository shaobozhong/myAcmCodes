/*
ID:shaoboz2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>

using namespace std;

typedef struct node  
{
  int price,stock;
}farmers;

int compare(const farmers &a,const farmers &b)
{
	return a.price<b.price;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	int n,m,i,money=0,sum=0;
	farmers t[5005];
	fin>>n>>m;
	t[m].price=0;
	for(i=0;i<=m-1;i++)
	{
		fin>>t[i].price>>t[i].stock;
	}
	
	sort(t,t+m,compare);
	for(i=0;i<=m-1;i++)
	{
		sum+=t[i].stock;
		money+=t[i].price*t[i].stock;
		if (sum>=n) break; 
	}
	fout<<(money-t[i].price*(sum-n))<<endl;
    return 0;
}

