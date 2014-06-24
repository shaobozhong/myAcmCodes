#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef struct 
{
	double area;
	double rounded;
}elem;

typedef struct 
{
   double x,y;
} Point;

int linecross(Point p1,Point p2,Point p3,Point p4,Point *p)
{
   double k;

    k=((p4.x-p3.x)*(p1.y-p3.y)-(p4.y-p3.y)*(p1.x-p3.x))/((p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y));

//k1=((p2.x-p1.x)*(p1.y-p3.y)-(p2.y-p1.y)*(p1.x-p3.x))/((p4.y-p3.y)*(p2.x-p1.x)-(p4.x-p3.x)*(p2.y-p1.y));

   (*p).x=p1.x+k*(p2.x-p1.x);

   (*p).y=p1.y+k*(p2.y-p1.y);

   return 1;//ÓÐ½»µã}

}

double area3(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double a,b,c,p,s;
    a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}

double distance(Point p1,Point p2)
{
	return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

double round(Point p1,Point p2,Point p3)
{
	return (::distance(p1,p2)+::distance(p2,p3)+::distance(p3,p1));
}

bool cmp(const elem a,const elem b)
{
	if (a.area==b.area) return a.rounded>b.rounded;
	return a.area>b.area;
}

int main()
{
	int i;
	elem result[4];
	Point cross;
	Point record[4];
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&record[0].x,&record[0].y,&record[1].x,&record[1].y,&record[2].x,&record[2].y,&record[3].x,&record[3].y)!=EOF)
	{
		if (record[0].x==0&&record[0].y==0&&record[1].x==0&&record[1].y==0&&record[2].x==0&&record[2].y==0&&record[3].x==0&&record[3].y==0) break;
        linecross(record[0],record[2],record[1],record[3],&cross);
        for(i=0;i<4;i++)
		{
			result[i].area=area3(record[i].x,record[i].y,record[(i+1)%4].x,record[(i+1)%4].y,cross.x,cross.y);
			result[i].rounded=round(record[i],record[(i+1)%4],cross);
			result[i].area=(int)(result[i].area*1000+0.5)/1000.0;
			
			result[i].rounded=(int)(result[i].rounded*1000+0.5)/1000.0;
		}
        sort(result,result+4,cmp);
		for(i=0;i<3;i++)
		{
			printf("%.3f ",result[i].area);
			printf("%.3f ",result[i].rounded);
		}
		printf("%.3f ",result[i].area);
		printf("%.3f",result[i].rounded);
	printf("\n");
	}
	return 0;
}