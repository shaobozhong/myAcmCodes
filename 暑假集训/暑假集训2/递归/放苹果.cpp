#include<iostream>
using namespace std;

int Apple(int m,int n)
{
	if (m==1||n==1) return 1;
	if (m<n) return Apple(m,m);
	if (n==m) return 1+Apple(m,n-1);
	if (m>n) return Apple(m-n,n)+Apple(m,n-1);//根据盘子可以分为 装 n个盘子 和不装n个盘子   
	return 0;
}

int main()
{
	int t;
	int m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		cout<<Apple(m,n)<<endl;
	}
	return 0;
}