#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
int x,y;
}point;

point p[50005];
point stack[50005];
int top;

int multi(point a,point b,point c)
{
return (a.x - c.x)*(b.y - c.y) - (a.y - c.y)*(b.x - c.x);
}

long long Dist(point a,point b)
{
return (a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y);
}

int cmp(point a,point b)
{
return (a.y < b.y||(a.y == b.y && a.x<b.x));
}

void Graham(int n)
{
int len,i;
sort(p,p+n,cmp);

stack[0] = p[0];
stack[1] = p[1];

top = 1;
for(i = 2; i < n; i++)
{
while(top>0 && multi(p[i],stack[top],stack[top-1]) > 0)
top--;
top++;
stack[top] = p[i];
}
len = top; stack[++top] = p[n-2];
for(i = n-3; i >=0 ;i--)
{
while(top!=len && multi(p[i],stack[top],stack[top-1]) > 0)
top--;
stack[++top] = p[i];
}
}

int main()
{
int n;
int i;
long long len = 0;
cin>>n;

for(i = 0; i < n; i++)
cin>>p[i].x>>p[i].y;
if(n==2)
cout<<Dist(p[0],p[1])<<endl;
else
{
Graham(n);
for(i = 0; i < top - 1; i++)
{
for(int j = i+1; j < top; j++)
if(Dist(stack[i],stack[j]) > len)
len = Dist(stack[i],stack[j]);
}
cout<<len<<endl;
}return 0;
}