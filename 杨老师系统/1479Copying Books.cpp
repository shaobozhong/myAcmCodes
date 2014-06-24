#include <cstdio>

#include <climits>

#include <cstring>

 

const int MAX = 505;

int book[MAX];

__int64 total[MAX];                        //1~n本书的页数

int k, m;

__int64 f[MAX][MAX];                  //f[i][j] = k 表示前i个人复制前j本书所需最少时间是k

__int64 max;

void Input ()

{

                scanf("%d%d", &m, &k);

                int i;

                for (i=1; i<=m; i++)

                                scanf("%d", &book[i]);

}

 

__int64 Sum (int s, int e)                                               //第s本书到第e本书的总页数

{

                return (total[e] - total[s-1]);

}

 

__int64 Max (__int64 a, __int64 b)

{

                return ( a>b?a:b );

}

 

__int64 Min (int x, int y)                                //前x个人复制前y本书所需的最少时间        x<=y

{

//考虑特殊情况

                if ( f[x][y] != -1 )

                                return f[x][y];

                if ( y == 0 )

                                return ( f[x][y] = 0 );

                if ( x == 0 )

                                return ( f[x][y] = INT_MAX );

 

                int i;

                __int64 temp;

                f[x][y] = INT_MAX;

                for (i=x-1; i<y; i++)

                {

//第x个人复制第i+1到第y本书与前x-1个人复制前i本书的时间较大的时间

                                temp = Max( Min(x-1, i), Sum(i+1, y) );                  

                                if ( temp < f[x][y] )

                                {

                                                f[x][y] = temp;

                                }

                }

                return f[x][y];

}

 

void Output ()

{

                int i, p;

                __int64 temp;

                int slash[MAX];

                max = f[k][m];

                memset(slash, 0, sizeof(slash));

                temp = 0;

                p = k;

                for (i=m; i>0; i--)

                {

                                //让后面的员工尽量复印最多的书籍

                                if ( temp + book[i] > max || i < p )

                                {

                                                slash[i] = 1;

                                                temp = book[i];

                                                p --;

                                }

                                else

                                {

                                                temp += book[i];

                                }

                }

 

                for (i=1; i<=m; i++)

                {

                                printf("%d", book[i]);

                                if ( slash[i] == 1 )

                                                printf(" / ");

                                else if ( i != m )

                                                printf(" ");

                }

                printf("\n");

}

 

void Solve ()

{

                int i, j;

                //预处理书籍页数的和

                total[0] = 0;

                for (i=1; i<=m; i++)

                                total[i] = total[i-1] + book[i];

 

                memset(f, -1, sizeof(f));

                

                Min(k, m);

                

                Output();

}

 

int main ()

{

                int test;

                scanf("%d", &test);

                while ( test-- )

                {

                                Input ();

                                Solve ();

                }

 

                return 0;

}

 

