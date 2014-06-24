//利用前后两位的差值 来表示 正数的奇数位 和 负数的偶数位
#include<iostream>
#include<string>
using namespace std;

int la;
int a[40];

void rtransform(int n,int r)
{

	la=0;
	int t;
	while(n)
	{
		t=n%r;
		a[la++]=t;
		n/=r;
	}
}

int main()
{
	string n;
	int fn;
	int r,i,weight,pr;
	while(cin>>n,n!="#")
	{
		memset(a,0,sizeof(a));
		cin>>r;
		pr=abs(r);
		weight=1;
		fn=0;
		for(i=int(n.size())-1;i>=0;i--)
		{
			if (n[i]=='-') break;
			fn+=(int(n[i])-48)*weight;
			weight*=10;
		}
		rtransform(fn,pr);
		if (n[0]!='-')
		{
			for(i=0;i<la+2;++i) //正数数 奇数位上的利用他前面的偶数位 变成正的
			{
				if (i%2==0) continue;
				if (a[i]) 
				{
					a[i+1]++;
					if (a[i+1]>=pr) 
					{
						a[i+2]+=a[i+1]/pr;
						a[i+1]%=pr;
					}
					a[i]=pr-a[i];
				}
			}
		}
		else 
		{
			for(i=0;i<la+2;++i)//偶数位上的借用前一位的奇数位变成负值
			{

				if (i%2!=0) continue;
				if (a[i]) 
				{
					a[i+1]++;
					if (a[i+1]>=pr) 
					{
						a[i+2]+=a[i+1]/pr;
						a[i+1]%=pr;
					}
					a[i]=pr-a[i];
				}
			}
		}


		/*for(i=0;i<=la;++i)
		{
		if (a[i]>=r) 
		{
		a[i+1]+=a[i]/pr;
		a[i]%=pr;
		}
		}*/

		for(i=la+3;i>=0;--i)//输出时 忽略前导零
		{
			if (a[i]!=0) break;
		}

		if (i==-1) {puts("0");continue;}
		for(;i>=0;--i)
		{
			if (a[i]<10) cout<<a[i];
			else putchar(a[i]+55);
		}
		cout<<endl;
	}
	return 0;
}