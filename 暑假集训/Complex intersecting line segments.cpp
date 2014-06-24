#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const double eps=1e-10;

struct Node
{
    double x, y;
};



//网上找的模板  非规范相交 模板
int CrossMutiply(Node& p1,Node& p2,Node& p3)//叉积
{
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}
int PointMutiply(Node& p1,Node& p2,Node& p3)//点积
{
    return (p2.x-p1.x)*(p3.x-p1.x)+(p2.y-p1.y)*(p3.y-p1.y);
}
bool Segments_Intersect(Node& p1_start,Node& p1_end,Node& p2_start,Node& p2_end)//判断两线段是否相交
{
    int d1=CrossMutiply(p1_start,p1_end,p2_start);
    int d2=CrossMutiply(p1_start,p1_end,p2_end);
    int d3=CrossMutiply(p2_start,p2_end,p1_start);
    int d4=CrossMutiply(p2_start,p2_end,p1_end);
    if((d1*d2<0)&&(d3*d4<0)) return true;
    else if(d1==0&&PointMutiply(p2_start,p1_start,p1_end)<=0) return true;
    else if(d2==0&&PointMutiply(p2_end,p1_start,p1_end)<=0) return true;
    else if(d3==0&&PointMutiply(p1_start,p2_start,p2_end)<=0) return true;
    else if(d4==0&&PointMutiply(p1_end,p2_start,p2_end)<=0) return true;
    else return false;
}


int main()
{
	int c;
	int i,j;
	string str; 
	char sign;
	scanf("%d",&c);
	Node a[4];
	while(c--)
	{


		for(i=0;i<4;++i)
		{
			cin>>str;
			int num;
			sign='+';
			
			j=0;
			if (str[0]=='+' || str[0]=='-') {sign=str[0]; j=1;}
			num=0;
			for(;j<int(str.size());++j)
			{
				
				if (str[j]=='+' || str[j]=='-') break;
				if (str[j]=='i') {if (num==0) num=1;continue;}
				num=num*10+int(str[j]-'0');
			}

			if (sign=='-') num*=-1;
			if (j>=int(str.size())) 
			{ 
				if (str[int(str.size())-1]=='i') 
				{
					a[i].x=0;
					a[i].y=num;
				}
				else 
				{
					a[i].x=num;
					a[i].y=0;
				}
			}
			else
			{
				a[i].x=num;
				sign=str[j];
				num=0;
				for(j=j+1;j<int(str.size());++j)
				{
				if (str[j]=='i') {if (num==0) num=1;continue;}
				num=num*10+int(str[j]-'0');
				}
				if (sign=='-') num*=-1;
				a[i].y=num;
			}
		}

		if (Segments_Intersect(a[0],a[1],a[2],a[3])) puts("intersect");
		else puts("do not intersect");
	}
	return 0;
}


