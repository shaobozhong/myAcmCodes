#include<iostream>
using namespace std;

int s[105][105],r[105][105],temp[105][105];
int min_1,m,n;
void index(int f)
{   
	int i,j,k,count,la,temp1;
	count=0;
	//恢复初始状态
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			temp[i][j]=s[i][j];
		}
	}

	//交换第一列和第f列
	if (f!=0)
	{
		for(i=0;i<m;i++)
		{
			temp1=temp[i][0];
			temp[i][0]=temp[i][f];
			temp[i][f]=temp1;
		}
		count++;
	}

	//匹配第一列 不能匹配的就翻
	for(i=0;i<m;i++)
	{
		if (temp[i][0]!=r[i][0])
		{
			for(j=0;j<n;j++)
			{
				if (temp[i][j]) temp[i][j]=0;
				else temp[i][j]=1;
			}
			count++;
		}
	}
	//从第二列开始进行匹配 能匹配上的不动不能就到后面找 找不到就说明这样换不行  找的时候能找到正好那列也需要这列的最好
	for(j=1;j<n;j++)
	{
		la=1;
		for(i=0;i<m;i++)
		{
			if (temp[i][j]!=r[i][j]) break;
		}
		if (i>=m) continue;//匹配上了继续往下走
		la=0;
		for(k=j+1;k<n;k++)
		{
			for(i=0;i<m;i++)
			{
				if (temp[i][k]!=r[i][j]) break;
			}
			if (i<m) continue;
			//la=k;
			//break;
			if (!la) la=k;
			for(i=0;i<m;i++)//是否要交换的行也需要这行   不要这种考虑也可以提交正确 这是数据的不全面 
			{
				if (r[i][j]!=temp[i][k]) break;
			}
			if (i<m) continue;
			la=k;
			break;
		}

		if (la==0) break;
		for(i=0;i<m;i++)
		{
			temp1=temp[i][j];
			temp[i][j]=temp[i][k];
			temp[i][k]=temp1;
		}
		count++;
	}
	if (j<n) return;
	if (min_1>count) min_1=count;
}
int main()
{
	int t,i,j,f;
	scanf("%d",&t);
	while(t--)
	{
		min_1=INT_MAX;
		scanf("%d%d",&m,&n);
		if (m<=0||n<=0) {puts("0");continue;}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&s[i][j]);

			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&r[i][j]);
			}
		}
		for(f=0;f<n;f++)
		{
			index(f);//将第f列与第一列进行交换 进行变换
		}

		if (min_1==INT_MAX) puts("-1");
		else printf("%d\n",min_1);
	}
	return 0;
}