#include <string.h> 
#include<iostream>
using namespace std;
#define inf 1000000000 
#define _clr(x) memset(x,-1,sizeof(int)*MAXN) 
#define MAXN 101

struct point 
{
	int x,y;
};



int kuhn_munkras(int m,int n,int mat[][MAXN],int*  match1,int* match2)
{ 
 int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k; 
 for (i=0;i<m;i++){ 
  for (l1[i]=-inf,j=0;j<n;j++) 
   l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i]; 
          if( l1[i] == -inf )return 1;// 无法匹配！  
     } 
 for (i=0;i<n;l2[i++]=0); 
 for (_clr(match1),_clr(match2),i=0;i<m;i++){ 
  for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++) 
   for (k=s[p],j=0;j<n&&match1[i]<0;j++) 
    if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){ 
     s[++q]=match2[j],t[j]=k; 
     if (s[q]<0) 
      for (p=j;p>=0;j=p) 
      
 match2[j]=k=t[j],p=match1[k],match1[k]=j; 
    } 
  if (match1[i]<0){ 
   for (i--,p=inf,k=0;k<=q;k++) 
    for (j=0;j<n;j++) 
     if 
(t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p) 
      p=l1[s[k]]+l2[j]-mat[s[k]][j]; 
   for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++); 
   for (k=0;k<=q;l1[s[k++]]-=p); 
  } 
 } 


 for (i=0;i<m;i++) 
     {// if处理无匹配的情况！！ 
          if( match1[i] < 0 ) return 1; 
          if( mat[i][match1[i]] >= inf ) return 1; 
          ret+=mat[i][match1[i]]; 
     } 
 return ret; 
} 

int main()
{
	/*
	初始化：for( i=0 ; i < MAXN ; ++i ) 
	for( j=0 ; j < MAXN ; ++j ) mat[i][j] = -inf; 
	| 对于存在的边：mat[i][j] = val ; // 注意，不能有负值
	*/
	point H[MAXN],M[MAXN];
	int mat[MAXN][MAXN];
	int match1[MAXN],match2[MAXN];
	int n,m;
	int i,j;
	char ch;
	int hcount,mcount;
	int ans;
	while(scanf("%d%d",&n,&m),n!=0||m!=0)
	{
		hcount=0;
		mcount=0;

		for(i=0;i<n;++i)
		{
			getchar();
			for(j=0;j<m;++j)
			{
				ch=getchar();
				if (ch=='H')
				{
					H[hcount].x=i;
					H[hcount++].y=j;
				}
				else if (ch=='m')
				{
					M[mcount].x=i;
					M[mcount++].y=j;
				}
			}
		}
        for( i=0 ; i <mcount ; ++i ) 
	    for( j=0 ; j < mcount ; ++j )
			mat[i][j] =-1*(abs(H[i].x-M[j].x)+abs(H[i].y-M[j].y));
		    ans=kuhn_munkras(mcount,mcount,mat,match1,match2);
			printf("%d\n",-1*ans);
	}
	return 0;
}