#include <stdio.h>

int total,n;
int w[5002],l[5002]; 
int a[5002]; 



void sort(int *l,int *w)
{
	int i,j;
    for(i=0;i<n-1;i++) 

     for(j=0;j<n-i-1;j++)
     {
         if(l[j]>l[j+1])
         {
             int temp=l[j];
             l[j]=l[j+1];
             l[j+1]=temp;
             
             temp=w[j];
             w[j]=w[j+1];
             w[j+1]=temp;
         } 
         if(l[j]==l[j+1]&&w[j]>w[j+1])

         {
             int temp=w[j];
             w[j]=w[j+1];
             w[j+1]=temp;
         } 
     }
} 

void getaline()
{ 
	int i,j,temp;
	
sort(l,w);
    
   
    for(i=1;i<=n;i++)		
a[i]=0;

     total=0;
     
      for(i=0;i<n;i++)
            if(a[i]==0)
            {
                temp=w[i];
                for(j=i+1;j<n;j++)
                    if(a[j]==0&&w[j]>=temp) 
                    {
                        temp=w[j];
                        a[j]=1;

                        
                    } 
                total++; 

            }
        printf("%d\n",total);


}

int main()
{
    int num;

    int i,j;
    scanf("%d",&num);
    for(j=0;j<num;j++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d%d",&l[i],&w[i]);
        getaline();
        
    } 
    return 0;} 
