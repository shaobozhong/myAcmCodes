#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool a[1001];

typedef struct 
{
	int num;
	int e;
}elem;
void pick()
{
	int i,j;
	memset(a,true,sizeof(a));
	a[1]=false;
	for(i=2;i<(int)sqrt((double(1000)));++i)
	{
		if (a[i]) 
		{
			for(j=i*i;j<=1000;j+=i)
			{
				a[j]=false;
			}
		}
	}
}

int main()
{
	vector <elem> result;
	elem ttemp;
	int i,temp,n,count;
	
    pick();
	
	while(cin>>n)
	{
		temp=n;
		for(i=2;i<=1000;i++)
		{
            if (a[i]) 
			{
				count=0;
				while(temp%i==0)
				{
                    temp/=i;
					++count;
				}
				if (count!=0)
				{
					ttemp.num=i;
					ttemp.e=count;
					result.push_back(ttemp);
				}
			}
			if (temp==1) break;
		}

		for(i=0;i<(int)result.size()-1;++i)
		{
			cout<<result[i].num<<"^"<<result[i].e<<"*";
		}
           cout<<result[i].num<<"^"<<result[i].e<<endl;

	}
	return 0;
}