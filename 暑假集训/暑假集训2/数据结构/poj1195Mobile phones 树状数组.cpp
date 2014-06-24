#include<iostream>
using namespace std;

	int c[1025][1025];

int lowbit(int x)
{
	return x&(x^(x-1));
}

void change(int s)
{
	int x,y,num,i,j;
	scanf("%d%d%d",&x,&y,&num);
	x+=1;
	y+=1;
	for(i=x;i<=s;i+=lowbit(i))
	{
		for(j=y;j<=s;j+=lowbit(j))
		{
			c[i][j]+=num;
		}
	}
}

int getsum(int x,int y)
{
	int res;
	int i,j;
	res=0;
	for(i=x;i>0;i-=lowbit(i))
	{
		for(j=y;j>0;j-=lowbit(j))
		{
			res+=c[i][j];
		}
	}
	return res;
}
void calcsum()
{
	int sum;
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	sum=getsum(x2+1,y2+1);
	sum-=getsum(x1,y2+1);
	sum-=getsum(x2+1,y1);
	sum+=getsum(x1,y1);
	printf("%d\n",sum);
}

int main()
{
	int state;
	int s;
    int i,j;

	while(scanf("%d",&state),state!=3)
	{
		switch(state)
		{
		case 0:
			{
				scanf("%d",&s);
				s+=1;
	            memset(c,0,sizeof(c));
				break;
			}
		case 1:change(s);break;
		case 2:calcsum();
		}
	}

	return 0;
}