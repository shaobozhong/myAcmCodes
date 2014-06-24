#include<iostream>
#include<string>
using namespace std;

int a[25];
int b[25];

int main()
{
	int p;
	int t;
	int n,i,j;
	int sum;
	int rcount,lcount;
	string str;
		cin>>t;
	while(t--)
	{
		sum=0;
		str="";
		cin>>n;
        for(i=1;i<=n;++i)
		{
			//cin>>a[i];
			cin>>p;
			for(j=1;j<=p-sum;++j)
			{
				str.insert(str.end(),'(');
			}
			str.insert(str.end(),')');
			sum=p;
		}
        p=0;
		for(i=1;i<int(str.size());++i)
		{
			if (str[i]==')') 
			{
				++p;
				b[p]=1;
				
				rcount=1;
				lcount=0;
				j=i-1;
				while(rcount!=lcount)
				{
					if (str[j]=='(') ++lcount;
					if (str[j]==')') {++rcount;++b[p];}
					--j;
				}
			}
		}

		for(i=1;i<=n;++i)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}