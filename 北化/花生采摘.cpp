#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct 
{
    int num,x,y;
}elem;

bool cmp(const elem &a,const elem &b)
{
	return a.num>b.num;
}

int main()
{
	elem temp;
	vector <elem> v; 
    int n,m,k,i,j,num,t,total;

	while(cin>>m>>n>>k)
	{
		total=0;t=0;
        for(i=1;i<=m;++i)
		{
			for(j=1;j<=n;++j)
			{
				cin>>num;
				if (num)
				{
					temp.num=num;
					temp.x=i;
					temp.y=j;
					v.push_back(temp);
				}
			}
		}
		sort(v.begin(),v.end(),cmp);
		t=v[0].x+1;
		if (t+v[0].x>k) {cout<<"0"<<endl;continue;}
		total+=v[0].num;
		for(i=1;i<v.size();++i)
		{
			t+=abs(v[i].x-v[i-1].x)+abs(v[i].y-v[i-1].y)+1;
			if (t+v[i].x>k) break;
			total+=v[i].num;
		}
		cout<<total<<endl;
	}
	return 0;
}

//题目中花生数相同没有考虑