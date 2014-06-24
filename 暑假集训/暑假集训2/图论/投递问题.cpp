/*
算法要点：
1、有上必有下
2、小心 任务之间的中空楼层    也是需要上去才能完成任务的
3、其实不用每次贪最上面的那一层 有上一定要先上 不能先去 完成下的任务  

整个题目的算法：
先统计出每一层 要上下的次数   然后根据任务  选择远的任务先完成（个人认为可以不这样） 
题目这样优先远的答案就是唯一的 但是要是不优先的话  就会有另一种答案

*/
//program deliver
#include<iostream>
using namespace std;

const int floors =10;// 总的楼层数

int uptable[floors+1];//上楼的数组
int downtable[floors+1];//下楼的数组
int Eup[floors+1];//
int Edown[floors+1];// 
int k,m;//k表示有多少个包裹
int package[51][3];//存储包裹的投递任务
int floor;//当前的层数
void createtable()//构造问题转化的图
{
	int i,j;
	memset(uptable,0,sizeof(uptable));//初始化上楼的数组
	memset(downtable,0,sizeof(downtable));//初始化下楼的数组
	for(i=1;i<=k;++i)
	{
		if (package[i][1]==package[i][2]) continue;//不用动
		if (package[i][1]<package[i][2]) 
		{//如果要上楼 统计uptable的次数
			for(j=package[i][1];j<package[i][2];++j)
			{
				++(uptable[j]);
			}
		}
		else 
		{
			for (j=package[i][2];j<package[i][1];++j)//如果要下楼 统计downtable的次数
			{
				++(downtable[j]);
			}
		}
	}
    
	for(i=0;i<floors+1;++i)
	{
		Eup[i]=uptable[i];Edown[i]=downtable[i];
	}
	
	for(i=1;i<=floors;++i)//下楼和上楼的次数需要相同，因此uptable[i]和downtable[i]都需要取可能的最大值 上了就要下 下了就要上
    if (uptable[i]>downtable[i]) downtable[i]=uptable[i];
	else uptable[i]=downtable[i];
	
	for (i=floors-1;i>=1;--i) //  没有上下货物任务的真空地带 但是其上还有任务
	{
		if (uptable[i]==0 && uptable[i+1]!=0) //检查有没有楼层是不需要搬货物而走上去的
		{
			uptable[i]=1;downtable[i]=1;
		}
	}
	m=0;
	for (i=1;i<=floors;++i)
	{
		m+=uptable[i];//统计一共要往上走的总层数
	}
	cout<<m<<endl;
}

void output(int x,int y,int z)
{
	printf("%d %d %d\n",x,y,z);//输出 从x层到y层    携带包裹编号
}

bool upstair()//上一层楼
{
	int i;
	bool bb;
	int p;
	if (uptable[floor]==0) return false;//不需要往上走
	//判断是否能够上楼
	bb=true;
	p=0;
	for(i=1;i<=k;++i)//检查所有在floor层的需要往上搬的货物，找出目标地所在的层次最高的货物，记为货物p
		if (package[i][1]==floor && package[i][1]<package[i][2]) 
		{
			if (p==0) p=i;
			else if (package[p][2]<package[i][2]) p=i;
			bb=false;
		}

		if (bb) //如果floor层没有货物需要往上搬，则看floor层上面还有没有货物来决定需不需要往上走
		{
			if (Eup[floor]==uptable[floor]) return false;//主要就是uptable没有因为上方的任务而改变（此地带为真空带的情况） 上面也没有比上要多的 下的任务要执行 
			else//不搬货物往上走一层 
			{
				output(floor,floor+1,0);
			}
		}
		else 
		{
			++package[p][1];//货物被搬上了一层，更新其所在的层数
			output(floor,floor+1,p);//搬货物p往上走一层 
			Eup[floor]=Eup[floor]-1;//完成了一个向上的任务的一次向上 Eup是原始的任务要求 每层楼的向上移动次数
		}
		uptable[floor]=uptable[floor]-1;//需要往上走的层数减1
		floor+=1;
	return true;//成功往上走一层
}

bool downstair()//下一层楼
{
	int i;
	bool bb;
	int p;
	if (floor==1) return false;//判断是否能下楼
	bb=true;
	p=0;
	//检查所有在floor层的需要往下搬的货物，找出目标地所在层次最低的货物，记为货物p
	for(i=1;i<=k;++i)
	{
		if (package[i][1]==floor && package[i][1]>package[i][2])
		{
			bb=false;
			if (p==0) p=i;
			else if (package[p][2]>package[i][2]) p=i;
		}
	}

	if (bb) //如果floor层没有需要往下搬的货物，则看floor层下面还有没有货物来决定需不需要往下走
	{
		if (Edown[floor-1]==downtable[floor-1]) return false;
		else 
		{
			output(floor,floor-1,0);
		}
	}
	else 
	{
		Edown[floor-1]=Edown[floor-1]-1;
		package[p][1]=package[p][1]-1;//货物被搬下了一层更新其所在的层数
		output(floor,floor-1,p);//搬货物p往下走一层
	}

	downtable[floor-1]=downtable[floor-1]-1;//需要往下走的层数减1 
	floor=floor-1;//所在层减1  到了下一层
	return true;
}



void process()
{
	floor=1;//从第一层开始
	do
	{
		if (!upstair()) //能上就上上楼
			if (!downstair()) //不能上就 能下楼就下楼
				if (floor!=1)//不能上不能下 但是不在第一层 就是出现了错误
				{
					puts("Error!");
					return;
				}
				else break;//在第一层 说明所有的任务已经完成了
	}while(1);
}

int main()
{
	int i;
   cin>>k;
   for(i=1;i<=k;++i) cin>>package[i][1]>>package[i][2];
   createtable();//构造图
   process();//  主要过程
}