# include <iostream>
using namespace std;
char dic[100001][15],*d;
char t[3];
int n;
struct LET
{
    char a;
    int value;
}letter[13];
int cmp(const void *x,const void *y)
{
    return strcmp((char *)x,(char *)y);
}
int cmp3(const void *x,const void *y)
{
    return *(char *)x-*(char *)y;
}
int cmp2(const void *x,const void *y)
{
    return ((LET *)x)->a - ((LET *)y)->a;
}
int find(const void *x,const void *y)
{
    return strcmp( (char *)x, ((char *)y));
}
int solve()
{
    char res[15]={0};
    char *isf;
    int p,i,ret=-1,th,j,k;
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        scanf("%s%d",t,&letter[i].value);
        letter[i].a=t[0];
    }
    qsort(letter,p,sizeof(LET),cmp2);
    for(i=1;i<(1<<p);i++)
    {
        k=th=0;
        for(j=0;j<p;j++)
        {
            if(i&(1<<j)){ res[k++]=letter[j].a;th+=letter[j].value;}
        }
        res[k]=0;
        isf=(char *)bsearch(res,dic+1,n,sizeof(dic[1]),find);
        if(isf && ret<th) ret=th;
    }
    return ret;
}

int main()
{
    int i,m;
    while(scanf("%d",&n)+1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",dic[i]);
            qsort(dic[i],strlen(dic[i]),1,cmp3);
        }
        qsort(dic+1,n,sizeof(dic[1]),cmp);
        scanf("%d",&m);
        while(m--)
        {
            printf("%d\n",solve());
        }
    }
    return 0;
}