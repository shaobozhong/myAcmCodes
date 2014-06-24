#include<stdio.h>
#include<math.h>
float length(float x1,float y1,float x2,float y2)
{
 return (float)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
	float a,b,c,x1,y1,x2,y2,x3,y3;
    int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
		a=length(x1,y1,x2,y2);
		b=length(x2,y2,x3,y3);
		c=length(x1,y1,x3,y3);
		if (a+b-c>1e-5&&a+c-b>1e-5&&b+c-a>1e-5) printf("%.4f\n",a+b+c);
		else printf("Impossible.\n");
	}
	return 0;
}