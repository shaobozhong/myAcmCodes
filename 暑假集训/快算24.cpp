#include <iostream>
using namespace std;
double g(double x,double y,int z)
{
     switch(z)
 {
 case 0:return x+y;
 case 1:return x-y;
 case 2:return x*y;
 case 3:return x/y;
 }
 return 0;
}

char f(int i)
{
switch(i)
{
 case 0:return '+';
 case 1:return '-';
 case 2:return '*';
 case 3:return '/';
}
}

int h(int a)
{
if(a>=1) return 1;
else return 2;
}

int main()
{
int i,j,k;
double a,b,c,d;
double x1,x2,x3,x4;
cin>>a>>b>>c>>d;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
for(k=0;k<4;k++)
{
    if(g(g(g(a,b,i),c,j),d,k)==24) 
{
if(h(j)>h(i)) cout<<"(";
if(h(k)>h(j)) cout<<"(";
cout<<a<<f(i)<<b;
if(h(j)>h(i)) cout<<")";
cout<<f(j)<<c;
if(h(k)>h(j)) cout<<")";
cout<<d<<endl;goto aa;
}
if(g(g(a,b,i),g(c,d,k),j)==24) 
{
if(h(j)>h(i)) cout<<"(";
cout<<a<<f(i)<<b;
                        if(h(j)>h(i)) cout<<")";
                        cout<<f(j);
if(h(j)>=h(k)) cout<<"(";
cout<<c<<f(k)<<d<<endl;
            goto aa;
}
if(g(g(a,g(b,c,j),i),d,k)==24) 
{
if(h(k)>h(i)) cout<<"(";
cout<<a<<f(i);
                        if(h(i)>=h(j)) cout<<"(";
cout<<b<<f(j)<<c;
                         if(h(i)>=h(j)) cout<<")";
 if(h(k)>h(i)) cout<<")";
 cout<<f(k)<<d<<endl; 
goto aa;
}
if(g(g(a,b,i),g(c,d,k),j)==24) 
{
if(h(j)>=h(k)&&h(j)>h(i)) continue;
cout<<a<<f(i)<<b<<f(j);
if(h(j)>=h(k)) cout<<"(";
cout<<c<<f(k)<<d;
if(h(j)>=h(k)) cout<<"(";
cout<<endl;
goto aa;
}
if(g(a,g(g(b,c,j),d,k),i)==24) 
{
    cout<<a<<f(i);
if(h(i)>=h(k)) cout<<"(";
if(h(k)>h(j)) cout<<"(";
cout<<b<<f(j)<<c;
if(h(k)>h(j)) cout<<")";
cout<<f(k)<<d;
if(h(i)>=h(k)) cout<<")";
cout<<endl;
goto aa;

}
if(g(a,g(b,g(c,d,k),j),i)==24)
{ 
cout<<a<<f(i);
if(h(i)>=h(j)) cout<<"(";
cout<<b<<f(j);
if(h(j)>=h(k)) cout<<"(";
cout<<c<<f(k)<<d;
if(h(i)>=h(j)) cout<<")";
if(h(j)>=h(k)) cout<<")";
cout<<endl;
goto aa;
}
}
aa:;
   return 0;
}
