#include<iostream>
#include<string>
#include <math.h> 
using namespace std;
const double pi=3.141592653589793;
typedef struct 
{
	string name;
	double lati,longi;
}node;
typedef struct 
{
	string a,b;
	double distance;

}res;

//计算圆心角lat表示纬度,-90<=w<=90,lng表示经度
//返回两点所在大圆劣弧对应圆心角,0<=angle<=pi 
double angle(double lng1,double lat1,double lng2,double lat2){ 
double dlng=fabs(lng1-lng2)*pi/180; 
while (dlng>=pi+pi) 
dlng-=pi+pi; 
if (dlng>pi) 
dlng=pi+pi-dlng; 
lat1*=pi/180,lat2*=pi/180; 
return acos(cos(lat1)*cos(lat2)*cos(dlng)+sin(lat1)*sin(lat2)); 
}

//计算球面距离,r为球半径
inline double sphere_dist(double r,double lng1,double lat1,double lng2,double lat2){ 
return r*angle(lng1,lat1,lng2,lat2); 
}

int main()
{
	node *s;
	res *r;
	s=new node[200];
	r=new res[200];
	int t=1;
	freopen("D.in","r",stdin);
	while(1)
	{	
		cin>>s[t].name;
		if(s[t].name=="#") break;
	    cin>>s[t].lati>>s[t].longi;
        t++;
    }
	t--;
	int m=1;
	int i;
	int x=0,y=0;
	string a,b;
	int f=0;
	while(cin>>a>>b&&(a!="#"||b!="#"))
	{
		f=0;
		x=0;y=0;
		if(a==b)
		{
				r[m].distance=0;
				r[m].a=a;
				r[m].b=a;
				m++;
				continue;
		}
		for(i=1;i<=t;i++)
		{
			if(s[i].name==a)
			{
				r[m].a=s[i].name;
				x=i;
			
			}
			else if(s[i].name==b)
			{
				r[m].b=s[i].name;
				y=i;
			}
			
		}
		if(x==0||y==0)
			{
				f=1;
			}
        if(f!=1)   r[m].distance=sphere_dist(6378,s[x].longi,s[x].lati,s[y].longi,s[y].lati);
		else {
			r[m].distance=-1;
			r[m].a=a;
			r[m].b=b;
		     }
		m++;
		
	}
    m--;
	for(i=1;i<=m;i++)
	{   
		
		cout<<r[i].a<<' '<<'-'<<' '<<r[i].b<<endl;
		if(r[i].distance==-1)
			cout<<"UnKnown"<<endl;
		else
		printf("%.0lf km\n",r[i].distance);
	}


return 0;
}