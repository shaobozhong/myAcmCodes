#include<iostream>
using namespace std;
int ans=0;
void swap(char &a,char &b)
{
	char s;
	s=a;
	a=b;
	b=s;
}

bool f(char list[],int k,int i)
{
	if(i>=k)
	{
		for(int t=k;t<i;t++)
			if(list[t]==list[i]) return false;
		return true;
	}
	return false;
}	
void perm(char list[],int k,int m)
{

	if(k==m)
	{
		ans++;
		for(int i=0;i<=m;i++)
			cout<<list[i];
		cout<<endl;
	}
	else
	{
for(int i=k;i<=m;i++)
			if(f(list,k,i))
			{
 				swap(list[k],list[i]);
				perm(list,k+1,m);
				swap(list[k],list[i]);
			}
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		char *a=new char [n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		perm(a,0,n-1);
		cout<<ans<<endl;
		delete []a;
	}
	return 0;
}
