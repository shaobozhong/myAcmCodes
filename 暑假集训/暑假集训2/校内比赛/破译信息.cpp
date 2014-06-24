#include<iostream>
#include<string>
#include<cmath>
#include "stdlib.h"
using namespace std;
double mat[100][101];
//该方法是高斯消元法解方程
bool jiefangchen(int n,int x_num){//n表示方程数目，x_num表示未知数变量数目，mat的第x_num+1列存储常数bi值。
	int i,j,m;
	for(i=0;i<x_num;i++){//i列
		for(j=i;j<n;j++)if(fabs(mat[j][i])>0.000001)break;//找到第i行第i列为非零
		if(j==n)return false;
		if(j!=i){
			for(int t=0;t<=x_num;t++){//交换两行
				double tmp=mat[i][t];
				mat[i][t]=mat[j][t];
				mat[j][t]=tmp;
			}			  
		}
		double a=mat[i][i];//对角线系数化为1
		for(m=i;m<=x_num;m++){
			mat[i][m]/=a;
		}
		//消元法
		for(m=0;m<n;m++){				
			if(m==i)continue;
			double b;				
			b=mat[m][i];
			for(int n=i;n<=x_num;n++){
				mat[m][n]-=b*mat[i][n];					
			}				
		}			
	}

	return true;
}

bool  checkIm(int n,int x_num){
	int type_num=x_num;
	int week=n;
	int i;
	for(i=type_num;i<week;i++){
		if(fabs(mat[i][type_num])>0.0000001)return true;//检查无解
	}
	for(i=0;i<type_num;i++){
		if(fabs(mat[i][type_num]+0.000001-(int)(mat[i][type_num]+0.000001))>0.00001)return true;//检查无整数解
	}
	for(i=0;i<type_num;i++){
		if(mat[i][type_num]+0.000001 <0 )return true;//检查为负数解
	}
	return false;
}

int main()
{

	int i,j;
	int b[10];
	double k[10];
	string p;
	freopen("1.txt","w",stdout);
	getline(cin,p);
	{
		for(i=0;i<10;++i)
		{
			cin>>b[i];
		}
		for(i=0;i<5;i++)
		{
			for(j=i;j<5+i;j++) mat[i][j]=p[j-i];
			mat[i][9]=b[i];

		}
		for(i=0;i<5;i++)
		{
			for(j=i;j<5+i;j++) mat[i+5][j]=p[j-i+5];
			mat[i+5][9]=b[i+5];
		}
		jiefangchen(10,9);
		for(i=0;i<9;i++)
		{
			k[i]=int(mat[i][9]+0.5);
		}
		while(cin>>b[0])
		{
			for(i=1;i<5;++i)
			{
				cin>>b[i];
			}
			for(i=0;i<5;++i)
			{
				for(j=0;j<5;++j)
				{
					mat[i][j]=k[i+j];
				}
				mat[i][5]=b[i];
			}
			jiefangchen(5,5);
			for(i=0;i<5;++i)
			{
				putchar(int(mat[i][5]+0.5)%127);
				//printf("%c",int(mat[i][5]+0.5));
				//cout<<"fdfd"<<endl;
			}
		}
		putchar('\n');
	}
	return 0;
}

