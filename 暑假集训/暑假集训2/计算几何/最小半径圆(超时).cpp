/*
算法的理论支持：minCircle(空集)=空集。 A=a；  minCircle(A) 圆心为a  半径为0   
最小圆 可由边界上最多3各点确定 有可能两个就能确定了
显然存在 存在点集B  若是minCircle(B)==minCircle(A) |B|<=3 若是a不属于B则  minCircle(A-a) ==minCircle(A) 即与a没关系
若是 a属于B则 minCircle(A-a)!=minCircle(A) 即没有a最小圆就会发生改变  最小圆是由B决定的  
*/
#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
#define MAX 1005 

typedef struct TPoint
{
	double x,y;
}TTriangle[3],TList[MAX];

struct TCircle
{
	double r;
	TPoint centre;
};

// typedef TTriangle TTriangle;

int casenum,n=0;//样例数 和点的个数

TList a;  //点的序列

TCircle c; //保存结果



double distance1(TPoint p1,TPoint p2)//计算两点距离
{
	return sqrt(double((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

double triangleArea(TTriangle t)//计算圆的内接三角形面积
{
	return abs(t[0].x*t[1].y+t[1].x*t[2].y+t[2].x*t[0].y-t[1].x*t[0].y
		-t[2].x*t[1].y-t[0].x*t[2].y)/2;
}




TCircle circumcircleOfTriangle(TTriangle t)//求外接圆
{
	TCircle tmp;
	double a,b,c,c1,c2;
	double xA,yA,xB,yB,xC,yC;
	a=distance1(t[0],t[1]);
	b=distance1(t[1],t[2]);
	c=distance1(t[2],t[0]);
	tmp.r=a*b*c/triangleArea(t)/4;
	xA=t[0].x;yA=t[0].y;
	xB=t[1].x;yB=t[1].y;
	xC=t[2].x;yC=t[2].y;
	c1=(xA*xA+yA*yA-xB*xB-yB*yB)/2;
	c2=(xA*xA+yA*yA-xC*xC-yC*yC)/2;
	tmp.centre.x=(c1*(yA-yC)-c2*(yA-yB))/
		((xA-xB)*(yA-yC)-(yA-yC)*(xA-xB));
return tmp;
}



void init()//输入数据
{
	int i;
	cin>>n;
	for(i=0;i<MAX;i++)//初始化a数组
	{
		a[i].x=a[i].y=0;
	}
	for(i=1;i<=n;i++)//输入点的坐标
		cin>>a[i].x>>a[i].y;
}




TCircle MinCircle2(int tce,TTriangle ce)
{
	TCircle tmp;
	tmp.centre.x=tmp.centre.y=0;//临时圆的圆心和半径初始化为0
	tmp.r=0;
	switch(tce)
	{
	case 0:tmp.r=-2;break;//没有点的情况 将半径置为-2
	case 1:tmp.centre=ce[0];break;//一个点可以确定圆心
	case 2://两个点 一这两个点的线段为直径
		tmp.r=distance1(ce[0],ce[1])/2;
		tmp.centre.x=(ce[0].x+ce[1].x)/2;
		tmp.centre.y=(ce[0].y+ce[1].y)/2;
		break;
	case 3://三个点的情况  求三角形的外接圆
		tmp=circumcircleOfTriangle(ce);
	}
	return tmp;//返回确定的圆
}



void MinCircle(int t,int tce,TTriangle ce)//整个递归过程分三层  每一层确定一个点   然后不断的更新
{
	int i,j;
	TPoint tmp;
	c=MinCircle2(tce,ce);//更新最小圆
	if(tce==3)  return ;//B集合中最多三个点
	for(i=1;i<=t;i++)
	{
		if(distance1(a[i],c.centre)>c.r)//如果第i个点不在最小圆之内 说明前面选的那个点不行 重新选 上一层的不管
		{
			ce[tce]=a[i];//这个点 放到tce位置上 tce是从0开始的  所以加上新加入的这个点B集中由tce+1个点
			MinCircle(i-1,tce+1,ce);//求将a[i]放入B集合中的前 前i个顶点最小圆
			// 将a[i]和a[1] 进行交换  但是并不是什么为了编程方便  而是一种剪枝的策略  通过将最有可能选为外接圆顶点的放在前面减少求外接圆的次数
			tmp=a[i];
			for(j=i;j>=2;j--)
				a[j]=a[j-1];
			a[1]=tmp;
		}
	}
}






void run()
{
	TTriangle ce;//定义ce数组 存储确定圆的三个点
	MinCircle(n,0,ce);//调用函数求最小圆
	//输出结果
	printf("%.2lf ",c.centre.x);
	printf("%.2lf ",c.centre.y);
	printf("%.2lf\n",c.r);
}


int main()
{
	cin>>casenum;
	while(casenum--)
	{
		init();//输入数据
		run();
	}
	return 0;
}