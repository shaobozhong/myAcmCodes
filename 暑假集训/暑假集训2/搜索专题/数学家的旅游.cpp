#include<iostream>
using namespace std;

bool map[221][221];//该位置上是否走过
int direc[10000];// 第i步的方向
int tot;//总共的路径种数
int maxn;// 最大边长

bool judge(int step ,int x,int y)//判断当前还有无可能到达
{
	int i;
	int sum;
	sum=0;
	for(i=step;i<=maxn;i+=2)//假设每一次 都是隔一次的都走同一方向能达到同一方向的最大值
	{
		sum+=i;
	}
	if (x-110>sum || 110-x >sum || y-110>sum || 110-y>sum) 
	{
		sum=0;
		for(i=step+1;i<=maxn;i+=2)
		{
			sum+=i;
		}
		if (x-110>sum || 110-x >sum || y-110>sum || 110-y>sum) return false;
	};
	return true;
}
bool panduan(int x,int y,int step)//判断是否满足移动的条件
{
	int i;
	if (direc[step]==direc[step-1]) return false;//两次移动同方向则返回假
	switch(direc[step])
	{
	case 1:
		for(i=y+1;i<=y+step;++i)//判断是否经过已经走过的点
		{
			if (!map[x][i]) break;
		}
		if (i<=y+step) return false; 
		break;
	case 2:
		for(i=x+1;i<=x+step;++i)
		{
			if (!map[i][y]) break;
		}
		if (i<=x+step) return false; 
		break;
	case 3:for(i=y-1;i>=y-step;--i)
		   {
			   if (!map[x][i]) break;
		   }
		   if (i>=y-step) return false; 
		   break;
	case 4:
		for(i=x-1;i>=x-step;--i)
		{
			if (!map[i][y]) break;
		}
		if (i>=x-step) return false; 
		break;
	}

	return true;
}

void attach(int x,int y,int step)// 将走过的点进行标记和解除标记  （分开写可以少一些判断可能速度会快一些）
{
	int i;
	switch(direc[step])
	{
	case 1:
		for(i=y+1;i<=y+step;++i)
		{
			if (map[x][i]) map[x][i]=false;
			else map[x][i]=true;
		}
		break;
	case 2:
		for(i=x+1;i<=x+step;++i)
		{
			if (map[i][y])		map[i][y]=false;
			else map[i][y]=true;
		}
		break;
	case 3:for(i=y-1;i>=y-step;--i)
		   {
			   if (map[x][i]) 	map[x][i]=false;
			   else map[x][i]=true;
		   }
		   break;
	case 4:
		for(i=x-1;i>=x-step;--i)
		{
			if (map[i][y])	map[i][y]=false;
			else map[i][y]=true;
		}
		break;
	}
}

void work(int x,int y,int step)
{
	int i;
	if (step>maxn+1) return;//不能超过最大边长
	if (step!=1&&x==110&&y==110)
	{
		if (step<maxn+1) return;
		for(i=1;i<step;++i)
		{
			switch(direc[i])
			{
			case 1:putchar('n');break;
			case 2:putchar('e');break;
			case 3:putchar('s');break;
			case 4:putchar('w');break;
			}
		}
		putchar('\n');
		tot++;
		return;
	}

	if (!judge(step,x,y)) return;
	direc[step]=1;
	if (y<221-step&&panduan(x,y,step))     //n
	{   

		attach(x,y,step);
		work(x,y+step,step+1);
		attach(x,y,step);
	}

	direc[step]=3;
	if (y>=step&&panduan(x,y,step))     //s
	{
		attach(x,y,step);
		work(x,y-step,step+1);
		attach(x,y,step);
	}
	direc[step]=2;
	if (x<221-step&&panduan(x,y,step))     //e
	{
		attach(x,y,step);
		work(x+step,y,step+1);
		attach(x,y,step);
	}

	direc[step]=4;
	if (x>=step&&panduan(x,y,step))     //w
	{
		attach(x,y,step);//标记走过的边
		work(x-step,y,step+1);
		attach(x,y,step);//解除标记
	}


}

int main()
{

	int x,y,n;
	//while(cin>>maxn)
	cin>>maxn;
	{
		tot=0;
		memset(map,true,sizeof(map));
		cin>>n;
		while(n--)
		{
			cin>>x>>y;
			map[x+110][y+110]=false;
		}
		work(110,110,1);
		printf("Found %d golygon(s).\n",tot);
	}
	return 0;
}