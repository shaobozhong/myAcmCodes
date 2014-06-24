#include<iostream>
using namespace std;

int main()
{
	double p[4],q[4],shang,xia,zuo,you;
	int t,i;
	cin>>t;
	while(t--)
	{
        for(i=0;i<4;i++)
			cin>>p[i];
		for(i=0;i<4;i++)
			cin>>q[i];
		    shang=(q[2]-q[0])*(p[1]-q[1])-(q[3]-q[1])*(p[0]-q[0]);
			xia=(q[2]-q[0])*(p[3]-q[1])-(q[3]-q[1])*(p[2]-q[0]);
			zuo=(p[2]-p[0])*(q[1]-p[1])-(p[3]-p[1])*(q[0]-p[0]);
			you=(p[2]-p[0])*(q[3]-p[1])-(p[3]-p[1])*(q[2]-p[0]);
			if (shang*xia<0&&zuo*you<0) {cout<<"YES"<<endl;continue;}
		else 
		{
			if (shang*xia==0&&zuo*you==0)
			{
				shang=q[0]-p[0];
				xia=q[0]-p[2];
				zuo=q[1]-p[1];
				you=q[1]-p[3];
				if (shang*xia<=0&&zuo*you<0) {cout<<"YES"<<endl;continue;}
				shang=q[2]-p[0];
				xia=q[2]-p[2];
				zuo=q[3]-p[1];
				you=q[3]-p[3];
				if (shang*xia<=0&&zuo*you<0) {cout<<"YES"<<endl;continue;}
			}
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}

//平行时还是有问题
//看网上的代码