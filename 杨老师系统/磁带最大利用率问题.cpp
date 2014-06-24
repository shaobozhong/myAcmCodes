#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b);

int main()
{
int num,*array,*max,leng,i,j,k,temp,tape;

printf("请输入数据个数\n");
scanf("%d",&num);
array = (int *)malloc(num * sizeof(int));
max = (int *)malloc(num * sizeof(int));

printf("请依次输入数据长度\n");
for(i = 0; i < num; i++)
   scanf("%d",&array[i]);

qsort(array,num,sizeof(int),comp);//排序

printf("请输入磁带长度");
scanf("%d",&tape);

for(temp = tape,leng = i = 0; i < num;i++)//从小到大选取程序段直至总和超过磁带厂
{
   if(array[i] < temp)
   {
    max[leng++] = array[i];
    temp -= array[i];
   }
   else
    break;
}

for(j = leng - 1; j >= 0;j--)//使磁带运用空间尽量最大化
{
   if(max[j] + temp < array[j + 1])
    break;
   for(k = j + 1; k < num; k++)
   {
    if(max[j] + temp < array[k])
     break;
    temp -= (array[k] - max[j]);
    max[j] = array[k];
   }
}

printf("\n利用空间长度%d,执行程序个数%d,分别是\n",tape - temp,leng);
for(i = 0; i < leng; i++)
   printf("%d ",max[i]);
return 0;
}
int comp(const void *a, const void *b)
{
return(*(int *)a - *(int *)b);
}