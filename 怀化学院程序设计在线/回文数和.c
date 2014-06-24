#include<stdio.h>
int main()
{
	int x,y,i,s,s1,t,sum=0,w;
	scanf("%d%d",&x,&y);
	for(i=x;i<=y;i++)
	{

		if (i%3==0)
		{
			s1=0;
			w=1000;
			while(i<w)
			{
				w/=10;
			}
			s=i;
			while(s!=0)
			{
				t=s%10;
				s1+=t*w;
				w/=10;
				s/=10;
            }
			if (s1==i) sum+=i;
		}
	}
	printf("%d\n",sum);
	return 0;
}