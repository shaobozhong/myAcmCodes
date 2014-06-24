#include<iostream>
#include<algorithm>
using namespace std;

typedef struct 
{
	int number;
	bool la;
}dui;

bool cmp(const dui &a,const dui &b)
{
	return a.number<b.number;
}

int main()
{
	dui *a;
	int n,k,max,min,temp,i,count,count1,rest;
	//freopen("input.in","r",stdin);
	cin>>n>>k;
	
		max=0;
		min=0;
		a=new dui[2*n];
		for(i=0;i<n;i++)
		{
			cin>>a[i].number;
			a[i].la=true;
		}
		sort(a,a+n,cmp);
		temp=a[n-1].number;
		for(i=n-2;i>=0;i--)
		{
			temp+=a[i].number;
			max+=temp;
		}
		count=0;
		if (k!=1)
		{
			rest=n%(k-1);
		if (rest!=1)
		{
			count++;
			a[n+count-1].number=0;
			a[n+count-1].la=true;
			for(i=0;i<rest;i++)
			{
				a[n+count-1].number+=a[i].number;
				a[i].la=false;
			}
			min+=a[n+count-1].number;
			sort(a,a+n+count,cmp);
		}
		}
		count1=2100000000;
		i=0;
       while(i<n+count-1)
	   {
		   count++;
		   count1=0;
		   a[n+count-1].number=0;
		   a[n+count-1].la=true;
		for(i=0;i<n+count-1&&count1<k;i++)
		{
			if (a[i].la)
			{
			a[n+count-1].number+=a[i].number;
			a[i].la=false;
			count1++;
             }
		}
		if (count1==k)
		{
			min+=a[n+count-1].number;
		    sort(a,a+n+count,cmp);
			continue;
		}
	   }
	   cout<<max<<" "<<min<<endl;



	return 0;
}