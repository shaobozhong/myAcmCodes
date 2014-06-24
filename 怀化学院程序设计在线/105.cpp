#include<iostream>
#include<math.h>
using namespace std;


int main()
{
   int n,num,i,total,temp;
   cin>>n;
   for(;n>=1;n--)
   {
	   cin>>num;
	   if (num==1) cout<<"2"<<endl;
	   else if (num==2) cout<<"1"<<endl;
	   else 
	   {
		   total=1;
		   temp=num-1;
		   for(i=2;i<=(int)sqrt(double(temp));i++)
		   {
			   if (temp%i==0) total+=2;
		   }
		   cout<<total*2<<endl;
	   }
   }
	return 0;
}