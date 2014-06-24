#include <iostream>
using namespace std;
int num1[122];
int num2[122];
int main ()
{
    int n;
	int i,j,k;
    while ( scanf("%d",&n)!=EOF )
    {
           for (i = 0 ; i <= n; ++ i )
           {
                 num1[i] = 1;
                 num2[i] = 0; 
           }
           for (i = 2; i <= n; ++ i )
           {
                 for ( j = 0;j <= n; ++ j )
                 {
                       for (  k = 0; k + j <= n; k += i ) 
                       {
                             num2[j + k] += num1[j]; 
                       }
                 } 
                 for (  j = 0; j <= n; ++ j )
                 {
                       num1[j] = num2[j];
                       num2[j] = 0;
                 }
           }
           cout << num1[n] << endl;
    }
    return 0; 
}