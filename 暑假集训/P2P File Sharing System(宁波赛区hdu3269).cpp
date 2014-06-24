//本题是一个典型的模拟题 只要从1到T按照条件  开机中的客户机从开机中的服务器中按照传输速度矩阵的速度下载数据
//并及时的标记是否下载完变成服务器  
//题目大意   给你n台电脑 根据p2p的原理 只要是拥有这个完整的文件的计算机都可以称为服务器 没有该文件的客户机就可以从这台电脑上下载 
//题目 给出 计算机数目 下载时间
// 每台电脑的开机时间段 电脑之间的传输速度  每台客户机的开始下载时间 并且一旦客户机下载完这个文件 就马上变成了服务器可以向其他客户家传送数据  
//要求的是：到t时间 每台电脑拥有这个文件的百分比

//解题思路  模拟即可  
#include<iostream>
using namespace std;
struct Time1//存储每台计算机的开机时间段
{
	int on,off;
};


bool panduan(Time1 t[],int i)//判断一台计算机是否处于开机时间段  是返回true
{
	int j;
	for(j=1;j<=t[0].on;++j)
	{ 
		if (t[j].on<i && t[j].off>=i) return true;
	}
	return false;
}

int main()
{
	int dd[25];//存储 每台计算机的开始下载时间
	int already[25];//存储每台计算机 已经下载了多少本文件的数据
	int map[25][25];// 存储 各计算机之间的传输速度
	bool server[25];// 标识 是否服务器
	int change[25];//每一秒钟的下载之后  存储要变成服务器的客户机的编号
	Time1 tt[25][15];// 存储每台计算机的开机时间段
	int casenum;//样例数目
	int count1;//存储要更新客户机为服务器的数目
	int n,m,T;//计算机数量，下载操作的数目，下载总时间
	int k,s;//最开始服务器数量，文件的大小
	int i,j,l,num,time2,sum;//三个循环变量   计算机编号 存储时间 计算机每秒钟要加的数据大小

	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%d%d",&n,&T);
		scanf("%d%d",&k,&s);
		memset(server,false,sizeof(server));
		memset(already,0,sizeof(already));
		while(k--)
		{
			scanf("%d",&num);
			server[num]=true;
			already[num]=s;
		}
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(j=1;j<=n;++j)
		{
			scanf("%d",&(tt[j][0].on));
			for(i=1;i<=tt[j][0].on;++i)
			{
				scanf("%d%d",&tt[j][i].on,&tt[j][i].off);
			}
		}


		for(i=0;i<=n;++i)
		{
			dd[i]=INT_MAX;
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&time2,&num);
			dd[num]=time2;
		}
	
	
		for(i=1;i<=T;++i)
		{
			count1=0;

			for(j=1;j<=n;++j)
			{

				if (server[j] || !panduan(tt[j],i)) continue;
				if (dd[j]<i) 
				{
					sum=0;
					for(l=1;l<=n;++l)
					{
						if (l==j) continue;
						if (server[l] && panduan(tt[l],i)) sum+=map[j][l];
					}
					already[j]+=sum;
					if (already[j]>=s) change[count1++]=j;
				}
			}

			for(j=0;j<count1;++j)
			{
				server[change[j]]=true;
			}

		}

		for(i=1;i<=n;++i)
		{
			if (server[i]) puts("100%");
			else 
			{
				printf("%d",(already[i]*100)/s);
				putchar('%');
				putchar('\n');
			}
		}
	}
	return 0;
}

//author shaobozhong