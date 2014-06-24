#include<iostream>
#include<vector>
using namespace std;

int a[4];
bool la[4];
vector <int> d;

double calc(double a,int fh,double b)
{
	switch(fh)
	{
	case 0:return a+b;
	case 1:return a-b;
	case 2:return a*b;
	case 3:return a/b;
	}
	return 0;
}

bool panduan()
{
    double sum,temp;
	sum=0;//case 1
	sum=calc(d[0],d[1],d[2]);
	temp=calc(d[4],d[5],d[6]);
	sum=calc(sum,d[3],temp);
	if (sum<=24+0.000001&&sum>=24-0.000001) return true;
	sum=0;//case 2
	sum=calc(d[0],d[1],d[2]);
	sum=calc(sum,d[3],d[4]);
	sum=calc(sum,d[5],d[6]);
	if (sum<=24+0.000001&&sum>=24-0.000001) return true;
	sum=0;//case 3
	sum=calc(d[4],d[5],d[6]);
	sum=calc(d[2],d[3],sum);
	sum=calc(d[0],d[1],sum);
	if (sum<=24+0.000001&&sum>=24-0.000001) return true;
	sum=0;//case 4
	sum=calc(d[2],d[3],d[4]);
	sum=calc(d[0],d[1],sum);
	sum=calc(sum,d[5],d[6]);
	if (sum<=24+0.000001&&sum>=24-0.000001) return true;
	sum=0;//case 5
	sum=calc(d[2],d[3],d[4]);
	sum=calc(sum,d[5],d[6]);
	sum=calc(d[0],d[1],sum);
	if (sum<=24+0.000001&&sum>=24-0.000001) return true;
	return false;
}

bool dfs(int count)
{
	int i,j;
	if (count==4)
	{
		if (panduan()) return true;
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
			  if (dfs(count+1)) {return true;}
			  d.pop_back();
			  la[j]=true;
		  }
		}
		d.pop_back();
	}
	return false;
}

int main()
{
int i;
bool result;
  while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])!=EOF)
  {
	  result=false;
	  memset(la,true,sizeof(la));
	  for(i=0;i<=3;i++)
	  {
		  la[i]=false;
          d.push_back(a[i]);
		  if (dfs(1)) {result=true;break;};
	      la[i]=true;
		  d.pop_back();
	  }
	  if (result) puts("YES");
	  else puts("NO");
	  d.clear();
  }

	return 0;
}