#include<iostream>
using namespace std;

#define VCRUISE 400   //飞机的速度
#define AOPT    30    // 飞机正常飞行的高度
#define GPHOPT  2000  //飞机正常飞行时每小时的耗油量
#define GPHEXTRA 10   //飞机高度离开AOPT每1000feet需增加每小时的耗油量
#define CLIMBCOST 50  //表示飞机每上升1000feet需要的耗油量

int areas;
double minareascost;

struct Area
{
	int high,low,distance,gao;
};

Area area[6];
int b[6];
int h[7];


double  calc(int oh,int gao,int i)//计算区域的花费
{
	int cost,dif;
	double speed;
	double time;
	double res;
	res=0;
	if (gao>oh) res=(gao-oh)*CLIMBCOST;
	dif=gao>AOPT ? gao-AOPT:AOPT-gao;
	cost=dif*GPHEXTRA+GPHOPT;
	speed=double(VCRUISE+area[i].low)+double((gao-20))*(area[i].high-area[i].low)/(20.0);
	time=double(area[i].distance)/speed;
	res+=cost*time;
	return res;
}

void h_found()//启发函数
{
	double speed;
	int i;
	h[areas]=0;
	for(i=areas-1;i>=0;--i)
	{
		if (area[i].high>area[i].low) {speed=area[i].high+VCRUISE;}
		else {speed=area[i].low+VCRUISE;}
		h[i]=h[i+1]+int(GPHOPT*double((area[i].distance/speed)));
	}
}

void work(int i,int oh,double areascost)//核心
{
	int gao;
	if (areascost>=minareascost) return;
	if (areascost+h[i]>=minareascost) return;
	if (i>=areas) 
	{
		if(minareascost>areascost) 
		{
			minareascost=areascost;
			for(i=0;i<areas;++i)
			{
				area[i].gao=b[i];
			}
		}
		return ;
	}
	for(gao=20;gao<=40;gao+=1)
	{
		b[i]=gao;
		work(i+1,gao,areascost+calc(oh,gao,i));
	}
}

int main()
{

	int t,i;
	int f;
	cin>>t;
	for(f=1;f<=t;++f)
	{
		minareascost=INT_MAX;
		cin>>areas;
		for(i=0;i<areas;++i)
		{
			cin>>area[i].distance>>area[i].low>>area[i].high;
		}
		h_found();
		work(0,0,0);
		printf("Flight %d : ",f);
		for(i=0;i<areas;++i)
		{
			printf("%d ",area[i].gao);
		}
		printf("%.0f\n",minareascost);
	}
	return 0;
}