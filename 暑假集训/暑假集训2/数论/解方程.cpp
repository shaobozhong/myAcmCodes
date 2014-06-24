#include<iostream>
#include<cmath>
using namespace std;
#define MAX 205
double mat[MAX][MAX];



bool Solve_X(/*double mat[][MAX],*/int n,int Xnum)//求解的函数 mat存储矩阵 n表示方程个数 Xnum表示未知数的个数 最后计算出的结果就是mat【i】【X_num】
{
    int s,i,j;
	for(s=0;s<Xnum;++s)
	{
		for(i=s;i<n;++i)
		{
			if (fabs(mat[i][s])>eps) break;
		}
	    if (i==n) return false;
		if (i!=s) //若是s行s列  不是0
		{
			for(j=0;j<=Xnum;++j)
			{
				double temp=mat[s][j];
				mat[s][j]=mat[i][j];
				mat[i][j]=temp;
			}
		}

		double a=mat[s][s];//将对角线上化为1
		for(i=0;i<=Xnum;++i)
		{
			mat[s][i]/=a;
		}

		for(i=0;i<n;++i)//消元 也就是将所有方程的成 s列变为0  
		{
			if (i==s) continue;
			double b=mat[i][s];
			for(j=s;j<=Xnum;++j)
			{
				mat[i][j]-=mat[s][j]*b;
			}
		}
	}
	return true;
}

int check_Ans(int n,int X_num)
{
	int i;
	for(i=X_num;i<n;++i)//检查是否无解 无解则返回1
	{
		if (abs(mat[i][X_num])>eps) 
		{
            return 1;
		}
	}


	/*for(i=0;i<X_num;++i)//检查是否无穷 无穷则返回2  想错了 只能在程序中判断
	{
		if (mat[i][i]==0) return 2;
	}*/

	for(i=0;i<X_num;++i)//检查是否整数解  非整数解则返回3
	{
		if ((fabs(mat[i][X_num]+eps-(int)(mat[i][X_num]+eps))>0.00001)) //这里为什么变成了-5次方
		{
			return 3;
		}
	}

	for(i=0;i<X_num;++i)//检查是否含负数解  有则返回4
	{
		if (mat[i][X_num]+eps<0) return 4;
	}

	return 0;//满足所有条件 返回0
}

int main()
{

}