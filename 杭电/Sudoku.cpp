#include <stdio.h>

#include <string.h>

 

struct P

{

       int x,y,num;

}point[100];

int map[10][10],count;

bool mr[10][10],mc[10][10],mm[10][10];

 

int dfs(int n);

int find(int x, int y);

 

int main()

{

       int i,j,cases;
	   char ch;
	   char rubbish[10];
       scanf("%d",&cases);
       getchar();
       while(cases--)

       {

              count=0;

              memset(mc,false,sizeof(mc));

              memset(mr,false,sizeof(mr));

              memset(mm,false,sizeof(mm));

              memset(map,0,sizeof(map));

              for(i=1; i<=9; i++)
			  {

                     for(j=1; j<=9; j++)

                     {

						   
                            scanf("%c",&ch);
							if (ch=='?') map[i][j]=0;
							else map[i][j]=(int)ch-48;

                            if(map[i][j]==0)

                            {

                                   point[count].x=i;

                                   point[count].y=j;

                                   point[count].num=0;

                                   count++;

                            }

                            else

                            {

                                   mr[i][map[i][j]]=true;

                                   mc[j][map[i][j]]=true;

                                   mm[find(i,j)][map[i][j]]=true;

                            }

                     }
					 getchar();
			  }
              gets(rubbish);
			  	 //getchar();
			  if (dfs(0))

              {

                     for(i=0; i<count; i++)

                            map[point[i].x][point[i].y]=point[i].num;

                     for(i=1; i<=9; i++)

                     {

                            for(j=1; j<=9; j++)

                            {

                                   printf("%d",map[i][j]);

                            }

                            printf("\n");

                     }

              }
			  else puts("impossible");
    

	   if (cases>0) puts("---");
       }

       return 0;

}

int dfs(int n)

{

       int i,t;

       if(n>=count)

              return 1;

       t=find(point[n].x,point[n].y);

       for(i=1; i<=9; i++)

       {

              if(!mr[point[n].x][i] && !mc[point[n].y][i] && !mm[t][i])

              {

                     mr[point[n].x][i]=true;

                     mc[point[n].y][i]=true;

                     mm[t][i]=true;

                     point[n].num=i;

                     if(dfs(n+1))

                            return 1;

                     mr[point[n].x][i]=false;

                     mc[point[n].y][i]=false;

                     mm[t][i]=false;

                     point[n].num=0;

              }

       }

       return 0;

}

int find(int x, int y)

{

       int r,c;

       r=x%3?(x/3+1):(x/3);

       c=y%3?(y/3+1):(y/3);

       return (r-1)*3+c;

}

