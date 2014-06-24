#include<iostream>
#include<time.h>
using namespace std;


typedef struct 
{
	long long num;
	int yc;
}ham;

void build(ham *a)
{
	
	int i,j,tj,count;
	long long  temp,min;
	count=0;
	a[0].num=1;
	a[0].yc=2;
	for(i=1;i<=5841;i++)
	{
		min=2000000001;
		tj=0;
		for(j=count;j<=i-1;j++)
		{
			temp=a[j].num*a[j].yc;
			while (temp<=a[i-1].num) 
			{
				switch(a[j].yc)
				{
				case 2:a[j].yc=3;break;
				case 3:a[j].yc=5;break;
				case 5:a[j].yc=7;break;
				case 7:count++;
				}
				temp=a[j].num*a[j].yc;
			}
			if(temp<min) 
			{
				min=temp;
				tj=j;

			}
		}
		switch(a[tj].yc)
		{
		case 2:a[tj].yc=3;break;
		case 3:a[tj].yc=5;break;
		case 5:a[tj].yc=7;break;
		case 7:count++;
		}
		a[i].num=min;
		a[i].yc=2;
	}
}

int main()
{
	int n;
	//clock_t t1,t2;
	ham a[6000];
	//t1=clock();
	build(a);
	//t2=clock();
	while(cin>>n,n!=0)
	{
		cout<<"The ";
		switch(n%10)
		{
		case 1:
			{
				if (n%100!=11) cout<<n<<"st humble number is ";
			   else  
				   cout<<n<<"th humble number is ";
				   break;
			}
		case 2:
			{
				if (n%100!=12) cout<<n<<"nd humble number is ";
				else cout<<n<<"th humble number is ";
				break;
			}
		case 3:
			{
				if (n%100!=13) cout<<n<<"rd humble number is ";
			   else cout<<n<<"th humble number is ";
			break;
			}
		default :cout<<n<<"th humble number is ";
		}
		cout<<a[n-1].num<<'.'<<endl;
	}
	
	//cout<<t2-t1<<endl;
	return 0;
}

//yc 表示要乘的数 cont表示要从哪里搜索 tj表示要标记的下标