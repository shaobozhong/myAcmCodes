#include<iostream>
#include<vector>
#include <math.h> 
#include<stdio.h>
using namespace std;
#define infinity 1000006
#define max_vertexes 105 

double dis;
typedef struct 
{
	float lat,lng;
}jwd;

vector <jwd> jw;


const double pi=acos((double)-1);
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



void prim(double G[][101],int vcount,int father[])
{
    int i,j,k;
	double lowcost[max_vertexes];
    int closeset[max_vertexes];
	int used[max_vertexes];
	dis=0;
    for (i=0;i<vcount;i++)
        {
        lowcost[i]=G[0][i];
        closeset[i]=0; 
        used[i]=0;
        father[i]=-1; 
        }
    used[0]=1; 
    for (i=1;i<vcount;i++)
        {
        j=0;
        while (used[j]) j++;
        for (k=0;k<vcount;k++)
            if ((!used[k])&&(lowcost[k]<lowcost[j])) j=k;
		dis+=lowcost[j];
        father[j]=closeset[j]; 
        used[j]=1;
        for (k=0;k<vcount;k++)
            if (!used[k]&&(G[j][k]<lowcost[k]))
                { lowcost[k]=G[j][k];
                closeset[k]=j; }
        }
}



int main()
{
	int father[105];
	double a[101][101];
	jwd temp;
	int t,C,i,j;
    double  D,r,L;
		scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%d",&D,&L,&C);
		r=D/2;
        for(i=1;i<=C;i++)
		{
			scanf("%f%f",&temp.lat,&temp.lng);
			jw.push_back(temp);
		}
		for(i=0;i<(int)jw.size();i++)
		{
			for(j=0;j<(int)jw.size();j++)
			{
				if (i==j) {a[i][j]=1000001;}
				else 
				{
					a[i][j]=sphere_dist(r,jw[i].lng,jw[i].lat,jw[j].lng,jw[j].lat);
				}
			}
		}
		prim(a,jw.size(),father);
		if (dis>L) puts("IS NOT POSSIBLE");
		else puts("IS POSSIBLE");
		jw.clear();
	}
	return 0;
}