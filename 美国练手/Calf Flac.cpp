/*
    ID : shaoboz2
    PROG : calfflac
    LANG : C++
*/
#include <iostream>
#include <stdio.h>
char a[20001], b[20001];
int n, m, t[20001], left, right, max;
void check(int l, int r)
{
     while (l >= 1 && r <= n)
     {
        if (b[l] == b[r])
        {
           l--; r++;
        }
        else break;
     }
     if (r - l - 1 > max)
     {
        max = r - l - 1;
        left = t[l + 1];
        right = t[r - 1];
     }
}
int main(void)
{
    freopen ("calfflac.in", "r",  stdin);
    freopen ("calfflac.out", "w", stdout);
    char ch;
	n=0;
    while (scanf ("%c", &ch) != EOF)
    {
       n++;
       a[n] = ch;
    }
    for (int i = 1; i <= n; i++)
      if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
         {
            m++;
            if (a[i] >= 97) b[m] = a[i] - 32;
            else b[m] = a[i];
            t[m] = i;
         }
    for (int i = 1; i <= m; i++)
      {
          check(i - 1, i + 1);
          check(i, i + 1);
      }
   printf ("%d\n", max);
   for (int i = left; i <= right; i++)
     printf ("%c", a[i]);
   printf ("\n");
}

