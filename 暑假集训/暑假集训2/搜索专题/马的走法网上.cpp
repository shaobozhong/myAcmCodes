#include<iostream>
using namespace std;

int   count1 ;
int chess[5][6] ;
int tp[2][8] = { {-2 ,-2 , -1 , -1 , 1 ,1 ,2 , 2 },
                  {1 , -1,    2,   -2 , 2, -2,1, -1 } } ;
int sx , sy ;

void Find_w(int p1 ,int p2 )
{
         int pi ,pj ;
         int i ;
         for(i =0; i< 8 ;i++)
         {
                 pi = p1 + tp[0][i] ;
                 pj = p2 + tp[1][i] ;
                 if( pi >= 1&& pj >= 1 && pi <= 4 && pj <= 5 && chess[pi][pj] == 0)
                 {
                        chess[pi][pj] = 1 ;
                        Find_w(pi ,pj ) ;
                        chess[pi][pj] = 0 ;
                 }
                 else if(pi == sx && pj == sy )
                         count1 ++ ;
         }
}

int main(int argc, char* argv[])
{
         while(scanf("%d %d" ,&sx ,&sy ) )
         {
                 if(sx >= 5 || sy >= 6)
                 {
                         printf("ERROR!!!!\n");
                         continue ;
                         }
                 memset(chess , 0 ,sizeof(chess) );
                 count1 = 0 ;
                 chess[sx][sy] = 1 ;
                 Find_w(sx, sy ) ;
                 printf("%d\n",count1 ) ;
         }
         return 0;
}
