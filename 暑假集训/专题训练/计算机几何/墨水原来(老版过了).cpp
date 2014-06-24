#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct 
{
    double x,y;
    double k;
}Node;

Node a[1000001];

bool cmp(const Node &a,const Node &b)
{
	if (a.k==b.k) return a.x<b.x;
    return a.k<b.k;
}

bool mutiply(const Node &one,const Node &two,const Node &three)
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

double Area(const Node &one,const Node &two)
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
   //freopen("input.in","r",stdin);
    int t,n,i,min;
    cin>>t;
    while(t--)
    {
	    
        count=0;
        sum=0;
        min=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].y;
            if (a[min].x>=a[i].x) 
            {
                if (a[min].x>a[i].x||a[min].y>a[i].y) min=i;
            }
        }
        if (n<3) {cout<<"0.0"<<endl;continue;}
        for(i=0;i<n;i++)
        {
            if (a[i].x!=a[min].x) a[i].k=(double)(a[i].y-a[min].y)/(double)(a[i].x-a[min].x);
            else a[i].k=2100000000+a[min].y-a[i].y;
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
        last=s.size();
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