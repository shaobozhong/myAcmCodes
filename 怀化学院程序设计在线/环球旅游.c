#include<stdio.h>
struct city
	{
		int y,l;
	};
int city(int n,int i,struct city a[])
{
    int j,sumy=0,suml=0;
	for(j=1;j<=n;j++)
	{
		if (i>n-1) i=i%n;
		sumy+=a[i].y;
		suml+=a[i].l;
		if (sumy<suml) return 0;
		i++;
      
	}
	return 1;
}

int main()
{
	struct city a[1000];
	
	int n,i;
	while(scanf("%d",&n)>0&&n!=0)
	{
		for(i=0;i<=n-1;i++)
			scanf("%d%d",&a[i].l,&a[i].y);
		for(i=0;i<=n-1;i++)
			if (city(n,i,a)) {printf("%d\n",i);break;}
		if (i>n-1) printf("impossible.\n");
	}
	return 0;
}