#include<iostream>
using namespace std;
int result;
char a[201][101];
int n;
void work_2(int i,int j)
{
	int i_1,j_1,r;
	int temp=1,t;
	i_1=i-1;j_1=j+1;r=j;
	for(i_1;i_1>=0;i_1--)
	{
		t=0;
		for(j=--r;j<=j_1;j++)
		{
			if(a[i_1][j]=='X') return;
			t++;
		}
		temp+=t;
		if(temp>result)result=temp;
		j_1=j;
	}
}



void work_1()
{
	int i,j;
	for(i=n-1;i>=0;i--)
	{
		for(j=i;j<2*n-i-1;j++)
		{
			if(a[i][j]=='O')
				work_2(i,j);
		}
	}

}


int main()
{
	char ch;
	int i,j;
	while(scanf("%d",&n),n!=0)
	{
	    result=0;
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<2*n-i-1;j++)
			{

				scanf("%c",&ch);
				if (ch!=' ')
					a[i][j]=ch;
			}
			getchar();
		}
		work_1();
		printf("%d\n",result);
	
	}
	return 0;
}