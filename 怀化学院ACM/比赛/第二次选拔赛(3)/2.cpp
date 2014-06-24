#include<iostream>
using namespace std;
int pre;

int a[32768];

void work(int n)
{
	int num,total=0;
	num=n/2;
   if (n%2==0)
   {
	   num--;
	   while(num)
	   {
		   total+=2*num;
		   num--;
	   }
   }
   else 
   {
	   total=num--;
	   while(num)
	   {
		   total+=2*num;
		   num--;
	   }
   }
   a[n]=total;
}

int main()
{
	int n;	
	memset(a,0,sizeof(a));
	a[0]=0;
	a[1]=0;
	a[2]=1;

	while(cin>>n)
	{
		if(a[n]||n<=1) cout<<a[n]<<endl;
		else 
		{
			work(n);
			cout<<a[n]<<endl;
		}
	}
	return 0;
}