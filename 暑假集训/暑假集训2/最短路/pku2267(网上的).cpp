#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
const int MAXN=101;
const int INF=1<<30;

struct node
{
int v,s,len;
};
int n;
map<string,int> id;
vector<node > mat[MAXN];
int dis[MAXN][2];

int dijkstra(int s,int t) 
{
int v[MAXN],i,j,k,mn[2];
for (i=1;i<=n;i++)
{
   dis[i][0]=INF;
   dis[i][1]=INF;
   v[i]=0;
}
dis[s][0]=0;
dis[s][1]=0;
for(j=0;j<n;j++)
{
   mn[0]=mn[1]=INF;
   for(k=-1,i=1;i<=n;i++)
    if(!v[i]&&((dis[i][0]<mn[0])||(dis[i][0]==mn[0]&&dis[i][1]<mn[1])))
    {
     k=i;
     mn[0]=dis[i][0];
     mn[1]=dis[i][1];
    }
   if(k==-1||k==t)break;
   v[k]=1;
   for(i=0;i<mat[k].size();i++)
   {
    int u=mat[k][i].v;
    int st=mat[k][i].s;
    int len=mat[k][i].len;
    int tmp;
    if(st<dis[k][1])tmp=1; //需要休息一天并喝血 
    else tmp=0;//不需要 
    if(!v[u]&&((dis[k][0]+tmp<dis[u][0])||(dis[k][0]+tmp==dis[u][0]&&st+len<dis[u][1])))
    {
     dis[u][0]=dis[k][0]+tmp;
     dis[u][1]=st+len;
    }
   }
}
if(dis[t][0]==INF)
   return -1;
else
   return dis[t][0];
}
int main()
{
int ncase,m,cnt;
scanf("%d",&ncase);
for(int t=1;t<=ncase;t++)
{
   cnt=0;
   id.clear();
   for(int i=0;i<MAXN;i++)
    mat[i].clear();
   scanf("%d",&m);
   char str1[35],str2[35];
   string sstr,tstr;
   int s,len;
   for(int i=0;i<m;i++)
   {
    scanf("%s %s %d %d",str1,str2,&s,&len);
    sstr=str1;
    tstr=str2;
    if(id[sstr]==0)id[sstr]=++cnt;
    if(id[tstr]==0)id[tstr]=++cnt;
    if(s<=6)s+=24;
    s-=18;
    if(s<0||s>12||s+len>12)continue;
    node tmp={id[tstr],s,len};
    mat[id[sstr]].push_back(tmp);
   }

   n=cnt;
   cin>>sstr>>tstr;
   printf("Test Case %d.\n",t);
   if(id[sstr]==0||id[tstr]==0)
    printf("There is no route Vladimir can take.\n");
   else
   {
    int ans=dijkstra(id[sstr],id[tstr]);
    if(ans==-1)
     printf("There is no route Vladimir can take.\n");
    else
     printf("Vladimir needs %d litre(s) of blood.\n", ans); 
   }
} 
}
