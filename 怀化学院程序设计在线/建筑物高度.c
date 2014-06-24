#include<stdio.h>
#include<math.h>
struct building
{
	float x,y,r,h;
};
int main()
{
	struct building a[4];
	float x1,y1,he=0;
	int i;
	for(i=0;i<=3;i++)
		scanf("%f%f%f%f",&a[i].x,&a[i].y,&a[i].r,&a[i].h);
	scanf("%f%f",&x1,&y1);
	for(i=0;i<=3;i++)
	{	
		if (pow((x1-a[i].x),2)+ pow((y1-a[i].y),2)<=pow(a[i].r,2))
		{
			he=a[i].h;
		}
	}
	printf("%.2f\n",he);
	return 0;
}