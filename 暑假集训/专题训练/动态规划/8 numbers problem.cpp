#include<iostream>
using namespace std;

int sx,sy;

void swap(int *b,int  *c)
{
	int temp;
	temp=*b;
	*b=*c;
	*c=temp;
}


void action(int a[][3])
{
		char operate;
	cin>>operate;
    switch(operate)
	{
	case 'U':
		{
			if (sx>0) 
			{swap(&a[sx][sy],&a[sx-1][sy]);
			sx--;
			}
			break;
		}
	case 'D':
		{
			if (sx<2) 
			{swap(&a[sx][sy],&a[sx+1][sy]);
			sx++;
			}
			break;
		}
	case 'L':
		{
			if (sy>0) 
			{
				swap(&a[sx][sy],&a[sx][sy-1]);
			sy--;
			}
			break;
		}
    case 'R':
		{
			if (sy<2) 
			{swap(&a[sx][sy],&a[sx][sy+1]);
			sy++;
			}
			break;
		}
	}
}

int main()
{

	int a[3][3];
	int t,i,j,n;
	cin>>t;
	while(t--)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cin>>a[i][j];
				if (a[i][j]==0)
				{
					sx=i;sy=j;
				}
			}
		}
	cin>>n;
	while(n--)
	{
       action(a);
	}
    for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<a[i][j]<<endl;
	}
	cout<<endl;
	}
	return 0;
}