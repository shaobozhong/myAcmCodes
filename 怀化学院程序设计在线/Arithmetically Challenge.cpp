#include<iostream>
#include<vector>
#include<set>
using namespace std;

int a[4];
bool la[4];
vector <int> d;
set<int>ans;
bool flag;
int calc(int a,int fh,int b)
{
	switch(fh)
	{
	case 0:return a+b;
	case 1:return a-b;
	case 2:return a*b;
	case 3:if (b&&a%b==0) return a/b; else {flag=false;return 0;}
	}
	return 0;
}

void work()
{

	int sum,temp;
	flag=true;
	sum=0;//case 1
	sum=calc(d[0],d[1],d[2]);
	temp=calc(d[4],d[5],d[6]);
	sum=calc(sum,d[3],temp);
	if (flag) ans.insert(sum);
	sum=0;//case 2
	flag=true;
	sum=calc(d[0],d[1],d[2]);
	sum=calc(sum,d[3],d[4]);
	sum=calc(sum,d[5],d[6]);
	if (flag) ans.insert(sum);
	sum=0;//case 3
	flag=true;
	sum=calc(d[4],d[5],d[6]);
	sum=calc(d[2],d[3],sum);
	sum=calc(d[0],d[1],sum);
	if (flag) ans.insert(sum);
	sum=0;//case 4
	flag=true;
	sum=calc(d[2],d[3],d[4]);
	sum=calc(d[0],d[1],sum);
	sum=calc(sum,d[5],d[6]);
	if (flag) ans.insert(sum);
	sum=0;//case 5
	flag=true;
	sum=calc(d[2],d[3],d[4]);
	sum=calc(sum,d[5],d[6]);
	sum=calc(d[0],d[1],sum);
	if (flag) ans.insert(sum);
}

void dfs(int count)
{
	int i,j;
	if (count==4)
	{
		work();
	}
	for(i=0;i<=3;++i)
	{
		d.push_back(i);
		for(j=0;j<=3;++j)
		{
			if (la[j])
			{
				la[j]=false;
				d.push_back(a[j]);
				dfs(count+1);
				d.pop_back();
				la[j]=true;
			}
		}
		d.pop_back();
	}

}

int main()
{
	int i;
	set<int>::iterator j;
	int num,tmpb,tmpe,begin,end;
	int max1,count1;
	int casenum;
	casenum=0;
	while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]),a[0]!=0||a[1]!=0||a[2]!=0||a[3]!=0)
	{
		++casenum;
		d.clear();
		ans.clear();
		memset(la,true,sizeof(la));
		for(i=0;i<=3;i++)
		{
			la[i]=false;
			d.push_back(a[i]);
			dfs(1);
			la[i]=true;
			d.pop_back();
		}
		j=ans.begin();
		num=*j;
		tmpb=num;
		tmpe=num;
		begin=num;
		end=num;
		max1=1;
		count1=1;
		for(;j!=ans.end();++j)
		{
			if (num+1!=*j) 
			{
				count1=1;
				num=*j;
				tmpb=num;
				tmpe=num;
			}
			else 
			{
				count1++;
				num=*j;
				tmpe=num;
			}
			if (count1>=max1)
			{
				begin=tmpb;
				end=tmpe;
				max1=count1;
			}
		}

		printf("Case %d: %d to %d\n",casenum,begin,end);
	}

	return 0;
} 