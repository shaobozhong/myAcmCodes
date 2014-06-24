#include<iostream>
using namespace std;

typedef struct
{
	int x,y;
	int direct;
}robert;

//x东西
bool action(robert *rb,int num,char ac,int time,int nrb,int A,int B)//根据指令移动
{
	int lx,ly,i,k;
	if(ac=='F')
	{
		lx=rb[num-1].x;
		ly=rb[num-1].y;
		switch(rb[num-1].direct)
		{
		case 0:
			{
				for(k=1;k<=time;k++)
				{
					rb[num-1].y-=1;
					for(i=0;i<=nrb-1;i++)
			  {
				  if (i!=num-1&&rb[i].x==lx&&rb[i].y<=ly&&rb[i].y>=rb[num-1].y) {cout<<"Robot "<<num<<" crashes into robot "<<i+1<<endl;return false;}
			  }
				}
				break;
			}
		case 1:
			{
				for(k=1;k<=time;k++)
				{
					rb[num-1].x-=1;
					for(i=0;i<=nrb-1;i++)
			  {
				  if (i!=num-1&&rb[i].y==ly&&rb[i].x<=lx&&rb[i].x>=rb[num-1].x) {cout<<"Robot "<<num<<" crashes into robot "<<i+1<<endl;return false;}
			  }
				}
				break;
			}
		case 2:
			{
				for(k=1;k<=time;k++)
				{
					rb[num-1].y+=1;
					for(i=0;i<=nrb-1;i++)
			  {
				  if (i!=num-1&&rb[i].x==lx&&rb[i].y>=ly&&rb[i].y<=rb[num-1].y) {cout<<"Robot "<<num<<" crashes into robot "<<i+1<<endl;return false;}
			  }
				}
				break;
			}
		default:
			{
				for(k=1;k<=time;k++)
				{
					rb[num-1].x+=1;
					for(i=0;i<=nrb-1;i++)
			  {
				  if (i!=num-1&&rb[i].y==ly&&rb[i].x>=lx&&rb[i].x<=rb[num-1].x) {cout<<"Robot "<<num<<" crashes into robot "<<i+1<<endl;return false;}
			  }
				}

			}
		}
		if (rb[num-1].x>A||rb[num-1].y>B||rb[num-1].x<1||rb[num-1].y<1) {cout<<"Robot "<<num<<" crashes into the wall"<<endl;return false;}
	}

	else 
	{
		switch(ac)
		{
		case'L':
			{
				rb[num-1].direct=(rb[num-1].direct+4-time%4)%4;
				break;
			}
		case'R':
			{
				rb[num-1].direct=(rb[num-1].direct+time%4)%4;
			}
		}
	}
	return true;
}


int main()
{
	robert *rb;
	int k,A,B,nac,nrb,i,time,num;
	char dir,ac;
	cin>>k;
	for(;k>=1;k--)
	{
		cin>>A>>B;
		cin>>nrb>>nac;
		rb=new robert[nrb+1];
		for(i=0;i<=nrb-1;i++)
		{
			cin>>rb[i].x>>rb[i].y>>dir;
			switch(dir)
			{
			case 'S':rb[i].direct=0;break;
			case 'W':rb[i].direct=1;break;
			case 'N':rb[i].direct=2;break;
			case 'E':rb[i].direct=3;
			}
		}
		for(i=0;i<=nac-1;i++)
		{
			cin>>num>>ac>>time;
			if (!action(rb,num,ac,time,nrb,A,B)) break;
		}
		if (i==nac) cout<<"OK"<<endl;
		i++;
		for(;i<=nac-1;i++)
			cin>>num>>ac>>time;
	}
	return 0;
}