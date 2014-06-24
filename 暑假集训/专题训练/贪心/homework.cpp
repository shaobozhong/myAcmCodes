#include<iostream>
#include<algorithm>
using namespace std;

typedef struct 
{
	double rate,score;
	int time;
}day;

bool cmp(const day &a,const day &b)
{
	return a.rate>b.rate; 
}

int main()
{
	day a[21];
	int n,lastday,i;
	double sum;
	while(cin>>n>>lastday,n||lastday)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i].time>>a[i].score;
			a[i].rate=a[i].score/a[i].time;
		}
    sort(a,a+n,cmp);
	for(i=0;i<n;i++)
	{
		if (a[i].time<=lastday) {sum+=a[i].score;lastday-=a[i].time;}
		else {sum+=lastday*a[i].score/a[i].time;break;}
	}
	printf("%.2f\n",sum);

	}
	return 0;
}