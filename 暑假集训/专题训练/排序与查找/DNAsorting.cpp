#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct 
{
	char s[51];
	int num;
}Node;

bool cmp(const Node a,const Node b)
{
	return a.num<b.num;
}
int main()
{
	char ch;
	Node a[100];
	int length,n,i,count,j,tcount,k;
	while(cin>>length>>n)
    {
		for(i=0;i<n;i++)
		{
			cin>>a[i].s;
		}
		for(i=0;i<n;i++)
		{
			count=0;
		
			for(j=0;j<length;j++)
			{
				tcount=0;
               	ch=a[i].s[j];
				for(k=j+1;k<length;k++)
					if (ch>a[i].s[k]) tcount++;
				count+=tcount;
			}
			a[i].num=count;
		}
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			cout<<a[i].s<<endl;
		}
	}
	return 0;
}