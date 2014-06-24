#include<iostream>
#include<string>
using namespace std;
char map[11][11];
bool canMatch(int r1,int c1,int r2,int c2)
{
     if(map[r1][c1] != map[r2][c2])
     {
          return false;
     }
     if(abs(r1 - r2) +  abs(c1 - c2) == 1) 
     {
          return true;
     }
     int r1min,r1max,c1min,c1max;
     int r2min,r2max,c2min,c2max;
     int rmin,rmax,cmin,cmax;
     for(r1min = r1 - 1;r1min > 0 && map[r1min][c1] == ' ';r1min --);
     r1min ++;
     for(r1max = r1 + 1;r1max <= 10 && map[r1max][c1] == ' ';r1max ++);
     r1max --;
     for(r2min = r2 - 1;r2min > 0 && map[r2min][c2] == ' ';r2min --);
     r2min ++;
     for(r2max = r2 + 1;r2max <= 10 && map[r2max][c2] == ' ';r2max ++);
     r2max --;
     
     rmin = max(r1min,r2min);
     rmax = min(r1max,r2max);
     cmin = min(c1,c2);
     cmax = max(c1,c2);
     for(int i = rmin;i <= rmax;i ++)
     {
         for(int j = cmin + 1;;j ++)
         {
              if(j >= cmax)
              {
                 return true;
              }
              if(map[i][j] != ' ')
              {
                 break;
              }
         }
     }
     for(c1min = c1 - 1;c1min > 0 && map[r1][c1min] == ' ';c1min --);
     c1min ++;
     for(c1max = c1 + 1;c1max <= 10 && map[r1][c1max] == ' ';c1max ++);
     c1max --;
     for(c2min = c2 - 1;c2min > 0 && map[r2][c2min] == ' ';c2min --);
     c2min ++;
     for(c2max = c2 + 1;c2max <= 10 && map[r2][c2max] == ' ';c2max ++);
     c2max --;     
     rmin = min(r1,r2);
     rmax = max(r1,r2);
     cmin = max(c1min,c2min);
     cmax = min(c1max,c2max);
     for(int j = cmin;j <= cmax;j ++)
     {
         for(int i = rmin + 1;;i ++)
         {
                 if(i >= rmax)
                 {
                      return true;
                 }
                 if(map[i][j] != ' ')
                 {
                      break;
                 }
         }
     }
     return false;
}
void eliminatePatterns()
{
     int num,r1 = 0,c1 = 0,r2,c2;
     scanf("%d",&num);
     while(num --)
     {
         if(r1 == 0 && c1 == 0)
         {
             scanf("%d %d",&r1,&c1);
         }
         else
         {
             scanf("%d %d",&r2,&c2);
             if(canMatch(r1,c1,r2,c2)) 
             {
                 map[r1][c1] = map[r2][c2] = ' ';
                 r1 = c1 = 0;
             }
             else
             {
                 r1 = r2;
                 c1 = c2;
             }
         }
     }
}
void output()
{
     int ans=0;
     for(int i = 1;i <= 10;i ++)
        for(int j = 1;j <= 10;j ++)
           if(map[i][j]!=' ')
               ans++;
     if(ans==0)
         puts("Yes,all patterns are eliminated!");
     else 
         printf("No,%d pattern(s) are left!\n",ans);

}

int main()
{
    int n,i,j;
    string x;
    cin>>n;
    while(n--)
    {
        getchar();
        for(i=1;i<=10;i++)
        {            
            getline(cin,x);
            for(j=0;j<=9;j++)
            {
                map[i][j+1]=x[j];
            }
        }
        eliminatePatterns();
        output();
    }
    return 0;
}  
