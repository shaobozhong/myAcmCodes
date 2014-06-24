#include<iostream>

using namespace std;

int main()
{
	double sum,score[21],daymax;
	int lastday,day[21],n,max,i,j,dayla;
	while(cin>>n>>lastday,n||lastday)
	{
		sum=0;
		max=0;
		for(i=0;i<n;i++)
		{
			cin>>day[i]>>score[i];
			if (max<day[i]) max=day[i];
		}
		for(i=max;i>=1;i--)
		{
			daymax=-1;
			dayla=-1;
			for(j=0;j<n;j++)
			{
				if (day[j]>=i&&score[j]>daymax) {daymax=score[j];dayla=j;}
			}
			if (dayla!=-1) {sum+=daymax;score[dayla]=-1;}
		}
		printf("%.2f\n",sum);
	}
	return 0;
}