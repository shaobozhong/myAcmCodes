#include <conio.h>
  #include <stdio.h>
  double average( int arr[ ], int n )
  { int k=0,i; double s;
    s = 0;
    for ( i=0 ;i<n; i++)
  /************found************/
      if (arr[i] % 2 ==1)
	{ s = s + arr[i]; k++;}
    return (s/k) ;
  }
  main()
  {
   int a[12]={10,4,2,7,3,12,5,34,5,9,21,18};
   double s;
   
  /************found************/
   s = average(a,12);
   printf("The result is: %.2f\n", s);
  }
