#include<iostream>
using namespace std;
#define M 100

typedef struct
{
	int fa;
	int left,right;
	int data;
	char ch;
}hafu;
//输出生成的树的数组
void print(hafu *ha,int n)
{
	int i;
	for(i=0;i<=2*n-2;i++)
	{
		cout<<i<<" "<<ha[i].ch<<" "<<ha[i].data<<" "<<ha[i].left<<" "<<ha[i].right<<" "<<ha[i].fa<<endl;
	}
}
//编码
void code(hafu *ha,char *stack,int n)
{
	int i,j,p;
	stack[0]=1;
  for(i=0;i<n;i++)
  {
	  stack[0]=1;
p=i;
while(ha[p].fa!=-1)
	  {
		  if (ha[ha[p].fa].left==p)  stack[((int)(stack[0]++))]='0';
		  else stack[((int)(stack[0]++))]='1';
		  p=ha[p].fa;
	  }
//cout<<ha[i].ch<<" ";
	  for(j=(int)stack[0]-1;j>=1;j--)
		  cout<<stack[j];
	  cout<<endl;
  }
}

int main()
{
	char stack[M];
	hafu ha[M];
	int n,i,j,k,m,temp;
	while(scanf("%d",&n)+1)
	{
	getchar();
	//赋初值
for(i=0;i<=2*n-2;i++)
{
	ha[i].fa=-2;
	ha[i].left=ha[i].right=-1;
}
//读入要编码的结点
for(i=0;i<n;i++)
{
	cin>>ha[i].ch;
	ha[i].fa=-1;
}
for(i=0;i<n;i++)
cin>>ha[i].data;
//哈夫曼树的形成（用数组）
for(i=0;i<n-1;i++)
{
	for(j=0;j<=i+n-1;j++)
		if (ha[j].fa==-1) break;
	for(k=j+1;k<=i+n-1;k++)
		if (ha[k].fa==-1) break;
	for(m=k+1;m<=i+n-1;m++)
	{
		if (ha[j].data>ha[k].data)
		{
			temp=j;j=k;k=temp;
		}
		if (ha[k].data>ha[m].data&&ha[m].fa==-1) k=m;
	}
	if (ha[j].data>ha[k].data)
		{
			temp=j;j=k;k=temp;
		}
	ha[i+n].data=ha[j].data+ha[k].data;
	ha[i+n].left=j;
	ha[i+n].right=k;
	ha[i+n].fa=-1;
	ha[i+n].ch=0;
	ha[k].fa=ha[j].fa=i+n;
}
//print(ha,n);
code(ha,stack,n);
	}
	return 0;
}