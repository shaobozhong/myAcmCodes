#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;


typedef struct 
{
	int count;
	set<string> ji;
}Elem;



bool cmp(const Elem &a,const Elem &b)
{
	int i;
	set<string>::iterator  ite,jte;
	//ite=a.ji.begin();
	if (a.count&&a.count==b.count)
	{
		return a.ji<b.ji;

	}
	return a.count>b.count;
}

int main()
{
	bool la;
	set<string> ::iterator ite;
	string str;
	Elem a[105];
	int all,n,i,j,k,l,m;
	//freopen("1.txt","w",stdout);
	//while(scanf("%d",&all)+1)
	scanf("%d",&all);
	{
		for(i=0;i<all;i++)
		{
			la=false;
			scanf("%d",&n);
			for(j=0;j<n;j++)
			{
				cin>>str;
				if (la) a[k].ji.insert(str);
				else
				{
					for(k=0;k<i;k++)
					{
						if (a[k].count&&a[k].ji.find(str)!=a[k].ji.end())
						{
							break;
						}
					}
					if (k>=i)   a[i].ji.insert(str);
					else 
					{
						for(ite=a[i].ji.begin();ite!=a[i].ji.end();ite++)
						{
							a[k].ji.insert(*ite);
						}
						a[i].count=0;
						la=true;
					}
				}
			}
			if (la) 
			{
				for(l=0;l<i;l++)
				{
					if (l!=k&&a[l].count)
					{
						for(ite=a[l].ji.begin();ite!=a[l].ji.end();ite++)
						{
							if (a[k].ji.find(*ite)!=a[k].ji.end()) break;
						}
						if (ite!=a[l].ji.end()) 
						{
							for(ite=a[l].ji.begin();ite!=a[l].ji.end();ite++)
							{
								a[k].ji.insert(*ite);
							}
							a[l].count=0;
						
						}
					}
				}
					a[k].count=a[k].ji.size();
			}
			else a[i].count=a[i].ji.size();
		}
		sort(a,a+all,cmp);
		for(i=0;i<all;i++)
		{
			if (a[i].count) 
			{
				str.clear();
				for(ite=a[i].ji.begin();ite!=a[i].ji.end();ite++)
				{
					if (ite!=a[i].ji.begin()) str.append(" ");
					str.append(*ite);
				}
				cout<<str;
				putchar('\n');
			}
		}
		for(i=0;i<all;i++)
		{
			a[i].ji.clear();
		}
	}
	return 0;
}
