#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
	int x,y,z;
}box;

bool cmp(const box &a,const box &b)
{
	if (a.x==b.x&&a.y==b.y)
	{
		return a.z>b.z;
	}
	if (a.x==b.x) return a.y>b.y;
	return a.x>b.x;
}

int main()
{
	box a[200];
	int x,y,z,count,i,j,n,rcount,temp,result[200];
	int total,test=0,mresult,max;
	while(cin>>n,n!=0)
	{
		test++;
		total=0;
		count=0;
		for(i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			a[count].x=x;
			a[count].y=y;
			a[count++].z=z;
			a[count].x=x;
			a[count].y=z;
			a[count++].z=y;
			a[count].x=y;
			a[count].y=x;
			a[count++].z=z;
			a[count].x=y;
			a[count].y=z;
			a[count++].z=x;
			a[count].x=z;
			a[count].y=x;
			a[count++].z=y;
			a[count].x=z;
			a[count].y=y;
			a[count++].z=x;
		}
		sort(a,a+6*n,cmp);
		result[0]=a[count-1].z;
		rcount=1;
		mresult=a[count-1].z;
		for(i=count-2;i>=0;i--)
		{
			max=a[i].z;
			for(j=0;j<=rcount-1;j++)
			{
				if (a[count-1-j].x<a[i].x&&a[count-1-j].y<a[i].y)
				{
				temp=result[j]+a[i].z;
				if (temp>max) max=temp;
				}
            }
			result[rcount++]=max;
			if (mresult<max) mresult=max;
		}
		cout<<"Case "<<test<<": maximum height = "<<mresult<<endl;

	}
	return 0;
}

//与超级跳跳跳有异曲同工之妙