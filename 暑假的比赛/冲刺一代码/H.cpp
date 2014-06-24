#include<stdio.h>
#include<string>
#include<map>
using namespace std;

const int MAXE = 19910;
const int MAXP = 210;
const int MAXSTR = 20;

bool city[MAXP][MAXP];
int pLen;
char ps,pe;

struct STR
{
char s[MAXSTR];
};

struct edge
{
char x;
char y;
int weight;
};//x must lest then y

struct point
{
char x;
char y;
};

bool operator <(const STR &a,const STR &b)
{
if(strcmp(a.s,b.s)<0)
   return true;
return false;
}

bool operator <(const point &a,const point &b)
{
if(a.x < b.x)
   return true;
else
   if(a.x > b.x)
    return false;
   else
    if(a.y < b.y)
     return true;
    else
     return false;
}

map<STR ,char> Str_Int;
map<point, int> Pnt_Wet;

edge e[MAXE];
int eLen;

int bcj[MAXP];

int Ancestor(int i)
{
while(bcj[i] != i)
   i = bcj[i];
return i;
}

void Connect(int a,int b)
{
if(bcj[a] == 0)
   bcj[a] = a;
if(bcj[b] == 0)
   bcj[b] = Ancestor(a);
else
   bcj[Ancestor(b)] = Ancestor(a);
}

void QuickSort(int left = 0,int right = eLen - 1)
{
int i = left, j = right;
edge tmp = e[i];
while(i < j)
{
   while(i < j && e[j].weight < tmp.weight)
    j--;
   if(i < j)
   {
    e[i] = e[j];
    i++;
   }
   else
    break;
   while(i < j && e[i].weight >= tmp.weight)
    i++;
   if(i < j)
   {
    e[j] = e[i];
    j--;
   }
}
e[i] = tmp;
if( i-1 > left ) QuickSort(left,i-1);
if( i+1 < right) QuickSort(i+1,right);
}

bool dp[MAXP];

int weight;

void Input()
{
memset(bcj,0,sizeof(bcj));
memset(city,0,sizeof(city));
memset(dp,0,sizeof(dp));
Str_Int.clear();
Pnt_Wet.clear();
point p;
char tmp;
STR a,b;
int i;
char index = 1;
for( i = 0; i < eLen; i++ )
{
   scanf("%s%s%d",a.s,b.s,&e[i].weight);
   if(Str_Int.find(a) != Str_Int.end())
   {
    ps = Str_Int[a];
   }
   else
   {
    ps = index;
    index++;
    Str_Int[a] = ps;
   }
   if(Str_Int.find(b) != Str_Int.end())
   {
    pe = Str_Int[b];
   }
   else
   {
    pe = index;
    index++;
    Str_Int[b] = pe;
   }
   if(ps > pe)
   {
    tmp = ps;
    ps = pe;
    pe = tmp;
   }
   e[i].x = ps;
   e[i].y = pe;
   p.x = ps;
   p.y = pe;
   Pnt_Wet[p] = e[i].weight;
}
scanf("%s%s",a.s,b.s);
ps = Str_Int[a];
pe = Str_Int[b];
weight = 0xfffffff;
}

void Kruskal()
{
int count = 1, i;
for( i = 0; i < eLen; i++ )
   if(Ancestor(e[i].x) != Ancestor(e[i].y) || bcj[e[i].x] == 0 || bcj[e[i].y] == 0 )
   {
    Connect(e[i].x,e[i].y);
    city[e[i].x][e[i].y] = true;
    city[e[i].y][e[i].x] = true;
    count++;
    if(count >= pLen)
     break;
   }
}


bool DFS(char c = ps)
{
point tmp;
int w;
char i;
if(c == pe)
   return true;
dp[c] = true;
for( i = 1;i <= pLen; i++)
   if(city[c][i] && !dp[i])
    if(DFS(i))
    {
    
     if(i < c)
     {
      tmp.x = i;
      tmp.y = c;
     }
     else
     {
      tmp.x = c;
      tmp.y = i;
     }
     w = Pnt_Wet[tmp];
     if(weight > w)
      weight = w;
     break;
    }
dp[c] = false;
if( i <= pLen )
   return true;
return false;
}

int text = 1;

void Output()
{
printf("Scenario #%d\n",text);
printf("%d tons\n",weight);
printf("\n");
text++;
}

int main()
{
// freopen("in.txt","r",stdin);
while(scanf("%d%d",&pLen,&eLen)!=EOF,pLen!=0 && eLen !=0)
{
   Input();
   QuickSort();
   Kruskal();
   DFS();
   Output();
}
return 0;
}

