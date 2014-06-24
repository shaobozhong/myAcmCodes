#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;


#define MAXN 4000
#define MAXE 20000

struct Edge{
    int u,v;
    int next;
}edge[MAXE];
int net[MAXN],visit[MAXN],pre[MAXN];
int nv,ne,index,r,c;
void add_edge(const int& u, const int& v)
{
    edge[index].next = net[u];
    net[u] = index;
    edge[index].v = v;
    edge[index].u = u;
    ++index;
}
int dfs(const int& u)
{
    int i,v;
    for(i = net[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if(!visit[v])
        {
            visit[v] = 1;
            if(-1 == pre[v] || dfs(pre[v]))
            {
                pre[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i,time,tmp1,tmp2,ans;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d%d",&r,&c);
        index = ans = 0;
        memset(net,-1,sizeof(net));
        memset(pre,-1,sizeof(pre));
        for(i = 1;i <= c; ++i)
        {
            scanf("%d%d",&tmp1,&tmp2);
            add_edge(tmp1,i);
            add_edge(tmp2,i);
            add_edge(i+r,tmp1);
        }
        if(c<r)
            ans = -1;
        else
            for(i = 1;i <= r; ++i)
            {
                memset(visit,0,sizeof(visit));
                if(dfs(i))
                    ++ans;
            }
        if(ans < r)
            printf("NO\n");
        else
        {
            for(i = 1;i <= c; ++i)
            {
                if(i != 1) printf(" ");
                if(pre[i] != -1)
                    printf("%d",pre[i]);
                else
                    printf("%d",edge[net[i+r]].v);
            }
            printf("\n");
        }
    }
    return 0;
}
