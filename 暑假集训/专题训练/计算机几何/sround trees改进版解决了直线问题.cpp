#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

typedef struct 
{
    double x,y;
    double k;
}Node;

Node *a;

bool cmp(const Node &a,const Node &b)// 根据斜率和Y进行排序
{
	if (a.k==b.k) return a.x<b.x;
    return a.k<b.k;
}

bool mutiply(const Node &one,const Node &two,const Node &three)//差集
{
    double p1x,p1y,p2x,p2y,result;
    p1x=two.x-one.x;
    p1y=two.y-one.y;
    p2x=three.x-two.x;
    p2y=three.y-two.y;
    result=p1x*p2y-p2x*p1y;
    if (result<=0) return true;
    return false;
}

double dis(const Node &one,const Node &two)//计算距离
{
    return sqrt((one.x-two.x)*(one.x-two.x)+(one.y-two.y)*(one.y-two.y));
}

int main()
{
    double sum;
    int last,count;
    vector <Node>s;
    Node one,two,three;
    
    int n,i,min;
    while(cin>>n,n)
    {
        a=new Node[n];
        count=0;
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
        if (n==1) {cout<<"0.00"<<endl;continue;}
        if (n==2)  {sum=dis(a[0],a[1]);printf("%.2f\n",sum);continue;}
        for(i=0;i<n;i++)
        {
			if (a[i].x==a[min].x) a[i].k=2100000000-a[i].y;
			else a[i].k=(double)(a[i].y-a[min].y)/(a[i].x-a[min].x);//这里若是不用if也可以   但是貌似不是很稳定吧！！遇到斜率不存在的时候就看天啦！！
			
        }
        a[min].k=-2100000000;
        sort(a,a+n,cmp);
        s.push_back(a[0]);
        s.push_back(a[1]);
        s.push_back(a[2]);
        for(i=3;i<n;i++)
        {
            last=s.size();
            three=s[last-1];
            two=s[last-2];
            one=s[last-3];
            while(mutiply(one,two,three)&&i<n&&s.size()>=3)
            {
                s.pop_back();//出栈
                s.pop_back();//出栈
                s.push_back(three);//进栈        这里是把第二个踢掉了
                count++;
                if(s.size()==2) break;
                last=s.size();
                three=s[last-1];
                two=s[last-2];
                one=s[last-3];
            } 
            s.push_back(a[i]);
        }
        last=s.size();
        three=s[last-1];
        two=s[last-2];
        one=s[last-3];
        while(mutiply(one,two,three)&&s.size()>=3)
        {
            s.pop_back();
            s.pop_back();
            s.push_back(three);
            count++;
            if(s.size()==2) break;
            last=s.size();
            three=s[last-1];
            two=s[last-2];
            one=s[last-3];
        } 
       /* one=two;two=three;three=s[0];
        while(mutiply(one,two,three)&&s.size()>=3)
        {
            s.pop_back();
            s.pop_back();
            s.push_back(three);
            count++;
            if(s.size()==2) break;
            last=s.size();
            three=s[last-1];
            two=s[last-2];
            one=s[last-3];
        }*/ 
		if(count==n-2) {sum=dis(s[0],s[1]); printf("%.2f\n",sum);s.clear();continue;}
        last=s.size();
        one=s[0];two=s[1];
        //cout<<s[0].x<<" "<<s[0].y<<endl<<s[1].x<<" "<<s[1].y<<endl;
        for(i=2;i<last;i++)
        {
            //    cout<<s[i].x<<" "<<s[i].y<<endl;
            sum+=dis(one,two);
            one=two;two=s[i];
        }
        sum+=dis(one,two);
        one=two;
        two=s[0];
        sum+=dis(one,two);
        printf("%.2f\n",sum);    
        s.clear();
    }
    return 0;
}   
