#include<iostream>
using namespace std;
bool R[16000001];

int main()
{
	int max1;
	int a,c,m,r0;
	int pre,current;
	int temp,i,j;
	int maxnum;
	cin>>a>>c>>m>>r0;
	{
        memset(R,false,sizeof(R));
		maxnum=r0;
		max1=0;
		pre=r0;
		R[r0]=true;
		while(1)
		{
			current=(a*pre+c)%m;
			if (R[current]) break;
			if (maxnum<current) maxnum=current;
			R[current]=true;
			pre=current;
		}

		max1=0;
		for(i=0;i<=maxnum;++i)
		{
			if (R[i]) break;
		}

			for(j=i+1;j<=maxnum;++j)
			{
				if (R[j]) 
				{
					temp=j-i;
					if (max1<temp)
					{
						max1=temp;
					
					}
					i=j;
				}
			}

		cout<<max1<<endl;

	}
	return 0;
}
