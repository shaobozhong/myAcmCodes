#include<stdio.h>
#include<string.h>

typedef struct 
{
	char name[16];
}Name;

int main()
{
    Name child[65];
	int n,count,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&child[i].name);
	}
	scanf("%d,%d",&count,&k);
	for(i=n;i>=2;--i)
		{
            count=(count+k-1)%i;
			if (count==0) count=i;
			printf("%s\n",child[count].name);
			for(j=count;j<i;++j)
			{
				strcpy(child[j].name,child[j+1].name);
			}
		}
	printf("%s\n",child[1].name);

	return 0;
}