//Program Car;
#include<iostream>
using namespace std;

int up,n1,m1,kills1,max1,m,n,r,c;// n行m列 r个预留车位 c辆除了r个预留车位还要放进的车辆数
int x[101],y[101],a[101];//x，y表示放车的位置  a表示横竖的方式



void solve(int wx,int wy)//放好剩下wx*wy大的空区域
{
	int free,aa,bb,k,r0;
	free=n*m-wx*wy-r;//r辆预设位置的车威胁到 但是没车的地方的数目
	r0=c-free;//填满已经受到威胁的位置
	if (wx*wy<r0) return;//若是剩下的位置不能满足还没有放入的车辆数
    
	if (r0<=0)//如果剩下的车还填不满 被c辆预设位置上的车威胁的位置
	{
		k=wx*wy;
		if (k>max1) max1=k;
		return;
	}

	for (aa=1;aa<=wx;++aa) //穷举aa=[1-wx],bb=[1-wy],求方程最优解 aa*wy+bb*wx-aa*bb>=r0 则成立  课根据这个球出最后的
	{
		if (aa==wx)  bb=0 ;
		else
		{
			bb=(r0-aa*wy)/(wx-aa);//由公式可得
			if (r0<aa*wy)  bb=0 ;//占 aa行就足够了  不用bb列了
			else  if ((r0-aa*wy)%(wx-aa)!=0)  ++bb;//如果占aa行不够 并且还要的车辆数r0-aa*wy不能被除掉已经被aa行占据的方格以外的每一列的方格数数整除 那么增加占得列数 也就是bb不够 因为bb是由公式得来  但是公式中有整除 怕会少1
		}
		if (bb>=0)  
		{
			k=aa*wy+bb*wx-aa*bb;//aa bb 占据的方格数
			k=wx*wy-k;
			if (k>max1) max1=k;
		}
	}

}




void trys(int i,int wx,int wy)//第i次
{
	int j;
	if (i>r) //r个预留车位安排好了
	{
		solve(wx,wy);//解决c辆待放入车的问题
		return;
	}

	for (j=1;j<=i-1;++j) 
	{
		if ((x[j]==x[i])&&(a[j]==0))//竖直的放与前面放好的x相等的
		{
			a[i]=0;
			trys(i+1,wx,wy);
			return;
		}

		if ((y[j]==y[i]) && (a[j]==1) )//横的放y相等的
		{
			a[i]=1;
			trys(i+1,wx,wy);
			return;
		}
	}
	a[i]=0;//竖直的放
	trys(i+1,wx-1,wy);
	a[i]=1;//横的放
	trys(i+1,wx,wy-1);
	a[i]=0;//恢复
}


int main()
{
	int i;
	cin>>n>>m>>r>>c;
	up=n*m-c-r;
	max1=-1;
	for (i=1;i<=r;++i) cin>>x[i]>>y[i];
	trys(1,n,m);
	cout<<max1<<endl;
}

