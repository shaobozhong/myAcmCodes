#include<iostream>
using namespace std;

int main()
{
	bool e1,e2;
	double p[4],q[4];
	double k1,k2,b1,b2,x,y;
	int t,i;
	cin>>t;
	while(t--)
	{
		e1=false;
		e2=false;
       for(i=0;i<4;i++)
		   cin>>p[i];
	   for(i=0;i<4;i++)
		   cin>>q[i];
	   if ((p[3]-p[1])*(q[2]-q[0])-(q[3]-q[1])*(p[2]-p[0])==0) {cout<<"NO"<<endl;continue;}
	   if (p[2]-p[0]==0) {e1=true;k1=0;b1=p[0];}
	   else {k1=(p[3]-p[1])/(p[2]-p[0]); b1=p[1]-k1*p[0];}

      
	   if (q[2]-q[0]==0) {e2=true;k2=0;b2=q[0];}
	   else {k2=(q[3]-q[1])/(q[2]-q[0]);b2=q[1]-k2*q[0];}
	   
	   if (e1)
	   {
		   y=k2*b1+b2;
		   printf("(%.2f,%.2f)\n",b1,y);
		   continue;
	   }
        if (e2)
	   {
		   y=k1*b2+b1;
		   printf("(%.2f,%.2f)\n",b2,y);
		   continue;
	   }
       
	   x=(b2-b1)/(k1-k2);
	   y=k1*x+b1;
printf("(%.2f,%.2f)\n",x,y);
	}
	return 0;
}