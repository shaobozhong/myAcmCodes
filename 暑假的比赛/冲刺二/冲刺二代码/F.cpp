#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct 
{
	string fname,sname;
	int bage;
}record;

typedef struct 
{
	string name;
	int age;
}MMD;

bool cmp(const MMD &a,const MMD &b)
{
	if (a.age==b.age)
	{
		return a.name<b.name;
	}
	return a.age>b.age;
}

int main()
{
    record temp;
	MMD ttemp;
	vector<record> r;
	vector<MMD> con;
	int t,n,i,j,k;
	scanf("%d",&t);
	getchar();
	for(k=1;k<=t;++k)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			cin>>temp.fname>>temp.sname;
			scanf("%d",&temp.bage);
			getchar();
			r.push_back(temp);
		}
		ttemp.name="Ted";
		ttemp.age=100;
		con.push_back(ttemp);

	
			for(i=0;i<con.size();++i)
			{
				   for(j=0;j<r.size();++j)
				   {
					   if (r[j].fname==con[i].name)
					   {
						   ttemp.name=r[j].sname;
						   ttemp.age=con[i].age-r[j].bage;
						   con.push_back(ttemp);
					   }
				   }
			}
      
       sort(con.begin(),con.end(),cmp);
       printf("DATASET %d\n",k);
	   for(i=1;i<con.size();++i)
	   {
		   cout<<con[i].name<<" "<<con[i].age<<endl;
	   }
	   con.clear();
	   r.clear();
	}
	return 0;
}