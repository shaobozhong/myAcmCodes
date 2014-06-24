//program surface;

#include<iostream>
#include<cmath>
using namespace std;

const double pi=acos(-1.0);
// a[0]为长方体尺寸，a[1],a[2]为两点的坐标
int a[3][4];
//两点的最短距离
double min1;

void init()//数据输入
{
	int i,j;
	for(i=0;i<=2;++i)
	{
		for(j=1;j<=3;++j)
		{
			cin>>a[i][j];
		}
	}
}

//两点共面的情况 
void one_surface(int x1,int z1,int x2,int z2)// 共面的时候统统假设y是相等的
{
	double t;
	t=sqrt(double((x1-x2)*(x1-x2)+(z1-z2)*(z1-z2)));//计算平面上两点间的距离
	min1=t;
}

//两点对面的情况
void opposite_surface(int x1,int z1,int x2,int z2,int l,int h,int w)
{
	double t1,t2;
	int a,b;
	a=abs(x1-x2);//假设图中x方向的差
	if ((z1+z2)<(h-z1)+(h-z2)) b=z1+z2+w;//展开后的三角形的一条边与x方向垂直
	else b=(h-z1)+(h-z2)+w;
    t1=sqrt(double(a*a+b*b));
	
	
	a=abs(z1-z2);//假设图中z方向的差
	if (x1+x2<(l-x1)+(l-x2)) b=x1+x2+w;//展开后的三角形的一条边与z方向垂直
	else b=(l-x1)+(l-x2)+w;
    t2=sqrt(double(a*a+b*b));


	if (t1<t2) min1=t1;//取最小值
	else min1=t2;
}


//两点邻面的情况
void near_surface(int x1,int z1,int x2,int y2,int l,int h)
{
	//1点坐标（x1,0,z1） 2点坐标 (x2,y2,h);
	//假设图中1点 已知 x和z  y为
	double t;
	double g1,g2;
	int a,b;
	a=abs(x1-x2);
	b=(h-z1)+y2;
	min1=sqrt(double(a*a+b*b));

    //以下是判断可否不直接展开相邻的两个面而是 通过一个中间面进行展开
	g1=atan(double(x1)/(h-z1));
	g2=atan(double(x2)/y2);
	if (g1+g2<=pi/2) //pi是圆周率
	{
		a=x1+y2;
		b=(h-z1)+x2;
		t=sqrt(double(a*a+b*b));
		if (t<min1) min1=t;
	}

	g1=atan(double(l-x1)/(h-z1));
	g2=atan(double(l-x2)/y2);
	if (g1+g2<=pi/2) 
	{
		a=(l-x1)+y2;
		b=(h-z1)+(l-x2);
		t=sqrt(double(a*a+b*b));
		if (t<min1) min1=t;
	}
}

//计算最短距离
void run()
{
	int p[3][4];
	int q[8];//
	int pq;
	bool solve;
	int i,j,k;


	for(i=1;i<=2;++i)
	{
		for(j=1;j<=3;++j)
		{
			if (a[i][j]==0) p[i][j]=0;// i点在j方向上坐标为0
			else
			{
				if (a[i][j]==a[0][j]) p[i][j]=2;//i点在j方向坐标与边长相等
				else p[i][j]=1;//i在j方向的大小任意
			}
		}
	}

	solve=false;
	for(j=1;j<=3;++j)
		//判断是否共面
		if (!solve) 
		{
			if (p[1][j]==p[2][j]&& p[1][j]!=1)//判断1点和2点在j方向上有相等的坐标 即共面
			{
				solve=true;// 标记已找到对应的情况
				pq=0;//q的下标
				for(i=1;i<=3;++i)
					if (i!=j) //j方向上的坐标设为0  q[1] ,[2] 代表 点 1 除j方向上的两个坐标 q[3], [4] 代表点2 除j方向上的两个坐标
					{
						q[pq+1]=a[1][i];
						q[pq+3]=a[2][i];
						++pq;
					}
				one_surface(q[1],q[2],q[3],q[4]);
			}
		}


	for(j=1;j<=3;++j)
		//判断是否对面
		if (!solve)
		{
			if (abs(p[1][j]-p[2][j])==2) //在某一个方向上一个为0 一个坐标为边长则代表对面
			{
				solve=true;// 标记已找到对应的情况
				pq=0;//q的下标
				for(i=1;i<=3;++i)
					if (i!=j)//除j方向上 其他方向和对应的边长  q[1],[2]代表点1  q[3],[4]代表点2 q[5],[6]存储两个边长
					{
						q[pq+1]=a[1][i];
						q[pq+3]=a[2][i];
						q[pq+5]=a[0][i];
						pq++;
					}
					q[7]=a[0][j];// j方向上的边长   假设图中的w
					opposite_surface(q[1],q[2],q[3],q[4],q[5],q[6],q[7]);
			}
		}
		i=1;
		while(i<=3)
		{
			//判断是否邻面
			if ((p[1][i]==0 || p[1][i]==2) && !solve) //p[1][i]==0||p[1][i]==2 表示1点在面上  这个条件根据题意其实并不需要 
		    {
			 j=1;
			 while(j<=3)//看是哪两个面相邻
			 {
				 if (i!=j && (p[2][j]==0 || p[2][j]==2)&&!solve)//判断2点 在j方向是0  或者是等于边长 即与1 异面就在这一边
				 {
					 solve=true;//标记已经找到对应的情况
                      
					 if (p[1][i]==p[2][j])//如果两个不同的方向 同时有相同的状态  （任意、 坐标为0 或是 坐标为边长） 则改变j方向上的状态
					 {
						 a[1][j]=a[0][j]-a[1][j];//1点在j方向上的坐标= j方向上的边长减去 1点的坐标  
						 a[2][j]=a[0][j]-a[2][j];//2点在j方向上的坐标= j方向上的边长减去 2点的坐标
						 p[1][j]=2-p[1][j];// 1点在j方向的状态改为 相对的  1->1  2->0  0->2
						 p[2][j]=2-p[2][j]; //2点也一样
					 }//最终目标是否 都变成  2点j方向上是2  1点i方向是是0


					 if (p[1][i]==2) //如果1点在i方向上坐标为边长即状态为2  交换1点和2点的坐标
					 {
						// i j 交换值 
						 pq=i;
						 i=j;
						 j=pq;
                         //交换1 2 点的的坐标和状态
						 for(k=1;k<=3;++k)
						 {
							 pq=p[1][k];
							 p[1][k]=p[2][k];
							 p[2][k]=pq;
							 pq=a[1][k];
							 a[1][k]=a[2][k];
							 a[2][k]=pq;
						 }
					 }


					 k=1;
					 while(k==i || k==j) ++k; //k表示除了i和j的另一个方向
					 q[1]=a[1][k];
					 q[3]=a[2][k];
					 q[2]=a[1][j];
					 q[4]=a[2][i];
					 q[5]=a[0][k];
					 q[6]=a[0][j];

					// q[1],[2]  由k j方向表示点1  i方向为0  q[3]，[4]由k i方向表示点2 j方向上为边长   //所以不记i方向上的边长
					 near_surface(q[1],q[2],q[3],q[4],q[5],q[6]);
				 }
				 ++j;
			 }
		 }
			++i;
		}
}
//输出最短距离
void done()
{
	printf("%.2lf\n",min1);
}


int main()
{
    init();
	run();
	done();
	return 0;
}