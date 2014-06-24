#include<iostream>
#include<math.h>
using namespace std;

typedef struct 
{
	double x,y;
}pot;

typedef struct 
{
	pot start,end;
}segment;

bool judge_segment(const segment &one,const segment &two)// 判断线段是否规范相交
{
	double  shang,xia,zuo,you;	
	//one的两个点
	shang=(two.end.x-two.start.x)*(one.start.y-two.start.y)-(two.end.y-two.start.y)*(one.start.x-two.start.x);
	xia=(two.end.x-two.start.x)*(one.end.y-two.start.y)-(two.end.y-two.start.y)*(one.end.x-two.start.x);

    //two的两个点
	zuo=(one.end.x-one.start.x)*(two.start.y-one.start.y)-(one.end.y-two.start.y)*(two.start.x-one.start.x);
	you=(one.end.x-one.start.x)*(two.end.y-one.start.y)-(one.end.y-one.start.y)*(two.end.x-one.start.x);
	if (shang*xia<0&&zuo*you<0) return true;
	return false;
}

bool judge_Segment(const segment &one,const segment &two)// 判断线段是否相交（包括非规范相交）
{
double  shang,xia,zuo,you;
	//one的两个点
	shang=(two.end.x-two.start.x)*(one.start.y-two.start.y)-(two.end.y-two.start.y)*(one.start.x-two.start.x);
	xia=(two.end.x-two.start.x)*(one.end.y-two.start.y)-(two.end.y-two.start.y)*(one.end.x-two.start.x);

    //two的两个点
	zuo=(one.end.x-one.start.x)*(two.start.y-one.start.y)-(one.end.y-two.start.y)*(two.start.x-one.start.x);
	you=(one.end.x-one.start.x)*(two.end.y-one.start.y)-(one.end.y-one.start.y)*(two.end.x-one.start.x);
	if (shang*xia<0&&zuo*you<0) return true;
	if (shang*xia==0&&zuo*you<0)//考虑有一点在直线上而另一点不在
	{
		if (shang!=0||xia!=0) return true;
	}
	if (shang*xia<0&&zuo*you==0)
	{
		if (zuo!=0||you!=0) return true;
	}
	if (shang*xia==0&&zuo*you==0)
	{
		if (fabs((one.start.x+one.end.x)/2-(two.start.x+two.end.x)/2)<=(fabs(one.start.x-one.end.x)/2+fabs(two.start.x-two.end.x)/2)) return true;
		if (one.start.x==one.end.x&&one.end.x==two.start.x&&two.start.x==two.end.x) 
		{
			if (fabs((one.start.y+one.end.y)/2-(two.start.y+two.end.y)/2)<=(fabs(one.start.y-one.end.y)/2+fabs(two.start.y-two.end.y)/2)) return true;
		}

	}
	return false;
}
int main()
{
	segment s[2];
	int t,i;
	cin>>t;
	while(t--)
	{
		for(i=0;i<2;i++)
		{
			cin>>s[i].start.x>>s[i].start.y>>s[i].end.x>>s[i].end.y;
		}
		if (judge_Segment(s[0],s[1])) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

