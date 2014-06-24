#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

typedef struct 
{
    int x,y;
    double k;
}Node;

Node *a;

bool cmp(const Node &a,const Node &b)// 根据斜率和x进行排序
{
	if (a.k==b.k) return a.x<b.x;
    return a.k<b.k;
}

bool mutiply(const Node &one,const Node &two,const Node &three)//差集
{
    double p1x,p1y,p2x,p2y,result;
    p1x=two.x-one.x;
    p1y=two.y-one.y;
    p2x=three.x-one.x;
    p2y=three.y-one.y;
    result=p1x*p2y-p2x*p1y;
    if (result<=0) return true;
    return false;
}

double Area(const Node &one,const Node &two)//计算面积
{
    double p1x,p1y,p2x,p2y,result;
    p1x=one.x-0;
    p1y=one.y-0;
    p2x=two.x-0;
    p2y=two.y-0;
    result=(p1x*p2y-p2x*p1y)/2;
  return result;
}

int main()
{
    double sum;
    int last,count;
    vector <Node>s;
    Node one,two,three;
    int n,i,min,t;
	cin>>t;
    while(t--)
    {
		cin>>n;
        a=new Node[n];
        sum=0;
        min=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y;
            if (a[min].x>=a[i].x) 
            {
                if (a[min].x>a[i].x||a[min].y>a[i].y) min=i;
            }
        }
       if (n<3) {cout<<"0.0"<<endl;continue;}
        for(i=0;i<n;i++)//计算斜率
        {
          a[i].k=(double)(a[i].y-a[min].y)/(double)(a[i].x+1-a[min].x);
        }
        a[min].k=-2100000000;
        sort(a,a+n,cmp);//按斜率和x排序
        s.push_back(a[0]);//开始形成凸包
        s.push_back(a[1]);
        for(i=2;i<n;i++)
        {
            last=s.size();
            two=s[last-1];
            one=s[last-2];
            while(mutiply(one,two,a[i])&&i<n&&s.size()>=2)
            {
                s.pop_back();
                if(s.size()==1) break;
                last=s.size();
                two=s[last-1];
                one=s[last-2];
            } 
            s.push_back(a[i]);
        }//形成了凸包
        last=s.size();//计算面积
        one=s[0];two=s[1];
        for(i=2;i<last;i++)
        {
            sum+=Area(one,two);
            one=two;two=s[i];
        }
        sum+=Area(one,two);
        one=two;
        two=s[0];
        sum+=Area(one,two);
        printf("%.1f\n",sum);    
        s.clear();
    }
    return 0;
}