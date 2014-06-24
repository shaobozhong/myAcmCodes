#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int ans[200000],k;

void getans(int n,int a,int b,int c,int d)
{
	if(n==1)
	{
		ans[k++]=a;
		return;
	}
	if(n==4)
	{
		getans(n-1,a+b,c,d,0);
		getans(n-1,a-b,c,d,0);
		getans(n-1,a*b,c,d,0);
		if(b && abs(a)%abs(b)==0)
			getans(n-1,a/b,c,d,0);
		getans(n-1,a,b+c,d,0);
		getans(n-1,a,b-c,d,0);
		getans(n-1,a,b*c,d,0);
		if(c && abs(b)%abs(c)==0)
			getans(n-1,a,b/c,d,0);
		getans(n-1,a,b,c+d,0);
		getans(n-1,a,b,c-d,0);
		getans(n-1,a,b,c*d,0);
		if(d && abs(c)%abs(d)==0)
			getans(n-1,a,b,c/d,0);
	}
	if(n==3)
	{
		getans(n-1,a+b,c,0,0);
		getans(n-1,a-b,c,0,0);
		getans(n-1,a*b,c,0,0);
		if(b && abs(a)%abs(b)==0)
			getans(n-1,a/b,c,0,0);
		getans(n-1,a,b+c,0,0);
		getans(n-1,a,b-c,0,0);
		getans(n-1,a,b*c,0,0);
		if(c && abs(b)%abs(c)==0)
			getans(n-1,a,b/c,0,0);
	}
	if(n==2)
	{
		getans(n-1,a+b,0,0,0);
		getans(n-1,a-b,0,0,0);
		getans(n-1,a*b,0,0,0);
		if(b && abs(a)%abs(b)==0)
			getans(n-1,a/b,0,0,0);
	}
	
}

void work(int a,int b,int c,int d)
{
	k=0;
	getans(4,a,b,c,d);
	getans(4,a,b,d,c);
	getans(4,a,c,b,d);
	getans(4,a,c,d,b);
	getans(4,a,d,c,b);
	getans(4,a,d,b,c);
	getans(4,b,a,c,d);
	getans(4,b,a,d,c);
	getans(4,b,c,a,d);
	getans(4,b,c,d,a);
	getans(4,b,d,c,a);
	getans(4,b,d,a,c);
	getans(4,c,b,a,d);
	getans(4,c,b,d,a);
	getans(4,c,a,b,d);
	getans(4,c,a,d,b);
	getans(4,c,d,a,b);
	getans(4,c,d,b,a);
	getans(4,d,b,c,a);
	getans(4,d,b,a,c);
	getans(4,d,c,b,a);
	getans(4,d,c,a,b);
	getans(4,d,a,c,b);
	getans(4,d,a,b,c);
}

void print()
{
	int temp1,temp2,Max=1,i,j,loc1,loc2,t=1;
	temp1=ans[0];temp2=ans[0];
	loc1=temp1;loc2=temp2;
	for(i=1;i<k-1;i++)
	{
		if(ans[i]==temp2)
			continue;
		if((ans[i]-temp2)==1)
		{
			temp2=ans[i];
			t++;
		}
		else
		{
			if(t>=Max)
			{
				Max=t;
				loc1=temp1;
				loc2=temp2;
			}
			t=1;
			temp1=ans[i];
			temp2=ans[i];
		}
	}
	if((ans[k-1]-temp2)==1)
	{
		temp2=ans[k-1];
		t++;
	}
	else
	{
		if(t>=Max)
		{
			loc1=temp1;
			loc2=temp2;
		}
	}
	printf("%d to %d\n",loc1,loc2);
}

int main()
{
	freopen("cin.in","r",stdin);
	int a,b,c,d,ss=0,i;
	while(scanf("%d %d %d %d",&a,&b,&c,&d))
	{
		if(!a && !b && !c && !d)
			break;
		ss++;
		work(a,b,c,d);
		sort(ans,ans+k);
		printf("Case %d: ",ss);
		print();
	}
	return 0;
}