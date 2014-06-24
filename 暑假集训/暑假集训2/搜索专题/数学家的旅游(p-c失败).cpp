//program golygons;


type
tp=array[-110..110,-110..110] of byte;//地图类型
tr=array[0..22,-210..210] of byte;//用于存放第五条剪枝
dir=array[1..4,1..2] of shortint;//用于存放方向位移
dirtory=array[0..20] of byte;//用于存放路径的方向
step_tp=array[0..20,1..2] of integer;//用于存放路径的坐标
const in_file='golygon.dat';out_file='golygon.out';//输入输出文件
d:dir=((0,1),(0,-1),(1,0),(-1,0));//行走的四个方向的增量
er:array[1..4] of char=('n','s','e','w');//四个方向的名称
var city:tp;	{定义城市}
walk:dirtory;// 每一部选择的方向
step:step_tp;	{每一步的坐标}
refer:tr;//第5条剪枝预处理的结果
in_f,out_f:text;//输入输出
n,h:integer;//最大边的大小 施工点的个数
bb:boolean;//
tot:longint;//路径总数


void  input()
{
	int i,x,y;
	memset(city,0,sizeof(city));
	cin>>n>>h;
	for (i=1;i<=h;++i)
	{
		cin>>x>>y;
		city[x][y]=1;
	}
}

void  mark(int x,int y,int sp,int dir)	{将走过的点作标记}
{
	int i,x1,y1;
	x1=step[sp-1][1];y1=step[sp-1][2];
	for (i=1i<=sp;++i)
	{
		x1=x1+d[dir][1];
		y1=y1+d[dir][2];
		city[x1][y1]=1;
	}
}

void clear(int x,int y,int sp,int dir){将走过的点清标记}
{
	int  i,x1,y1;
	x1=step[sp-1][1];y1=step[sp-1][2];
	for (i:=1;i<=sp;++i)
	{
		x1=x1+d[dir][1];
		y1=y1+d[dir][2];
		if ((x1!=0) || (y1!=0)) city[x1][y1]=0;
	}
}

void t(int sp)	{搜索过程}
{
	int  i,j,x,y;
	if ((step[sp-1][1]=step[sp-1][2]) && (step[sp-1][1]=0))
	{
		if (sp<=n) return;
		for (i=1;i<=sp-1;++i)
			cout<<er[walk[i]];
		++tot;
		return;
	}
	if (sp>n)  return;
	for (i=1;i<= 4;++i)
	{
		if (i!=walk[sp-1])
		{
			bb=false;
			x=step[sp-1][1];
			y=step[sp-1][2];
			walk[sp]=i;
			for (j=1;j<=sp;++j)
			{
				x=x+d[i][1];
				y=y+d[i][2];
				if ((city[x][y]!=0) && ((j!=sp) || (x!=0) || (y!=0))) 
				{
					bb=true;
					break;
				}
			}

			if (!bb)
			{
				step[sp][1]=x;
				step[sp][2]=y;
				if (((i<3)&& (refer[sp+2][y]=1)) || ((i>2) and (refer[sp+2][x]==1)) || (sp+2>=n))
				{
					mark(x,y,sp,i);
					t(sp+1);
					clear(x,y,sp,i)
				}
			}
		}
	}
}

void make(int n)	{第五步的预处理}
{
	int  i,j,k,p;
	memset(refer,0,sizeof(refer));
	for (i=1;i<=n;++i)
	{
		refer[i][i]=1;
		refer[i][-i]=1;
		j=i+2;
		while (j<=n)
		{
			p=((j-2)*(j-1))/ 2;
			for (k=-p ;k<=p;++k)
				if (refer[i][k]==1)
				{
					refer[i][k+j]=1;
					refer[i][k-j]=1;
					refer[i][j-k]:=1;
				}

				j=j+2;
		}
	}
}

int  main()
{
int i,j,x,y;
input();
make(n);
);
tot=0;
step[0][1]=0;
step[0][2]=0;
city[0][0]=1;
if (refer[1][0]==1)
for (i=1;i<=4;++i)
{
x=d[i][1];y=d[i][2];
walk[1]=i;
step[1][1]=x;
step[1][2]=y;
if (((i<3) && (refer[3][y]==1)) || ((i>2) && (refer[3][x]==1)))
{
mark(x,y,1,i);
t(2);
clear(x,y,1,i);
}
}
return 0;
}

