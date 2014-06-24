#include<iostream>
#include<string>
using namespace std;

string redirect(const string  &str)
{
	int i;
	string res;
	for(i=0;i<int(str.size());++i)
	{
		res.insert(res.begin(),str[i]);
	}
	return res;
}

int main()
{
    string a[204],b[204];
	string temp;
	string res;
	bool la;
	int slen;
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		la=false;
		res="";
		for(i=0;i<n;++i)
		{
			cin>>a[i];
			if (a[0].size()>a[i].size()) 
			{
				temp=a[0];
				a[0]=a[i];
				a[i]=temp;
			}
		}

		for(i=1;i<n;++i)
		{
			b[i]=redirect(a[i]);
		}
		slen=int(a[0].size());
		for(i=0;!la&&i<slen;++i)
		{
			for(j=0;!la&&j<=i;++j)
			{
				res=a[0].substr(j,slen-i);
				{
					for(k=1;k<n;++k)
					{
						if (a[k].find(res)==-1 && b[k].find(res)==-1) break;//正反字符串中 都没有找到
					}
					if (k==n) {la=true;break;}
				}
			}
		}
		if (la) cout<<int(res.size())<<endl;
		else puts("0");
	}
	return 0;
}