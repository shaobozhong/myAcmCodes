 
#include<iostream>
using namespace std;
int N;
typedef struct 
{
	int x,y;
}Node;

int opration(Node *move)
{
	int i,j,total=0,t;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(move[i].x>move[j].x)
			{
				t=move[i].x;move[i].x=move[j].x;move[j].x=t;
				t=move[i].y;move[i].y=move[j].y;move[j].y=t;
			}
		}
	}	
	for(i=0;i<N;i++)
	{
		if(move[i].x!=0)
		{
			total+=10;
			move[i].x=0;
			for(j=0;j<N;j++)
			{
				if(move[j].x!=0 && move[i].y<move[j].x)
				{
					move[j].x=0;move[i].y=move[j].y;
				}
			}
		}
	}	
	return total;
}
//´íÎóËã·¨
/*	for(i=0;i<N-1;i++)
{
for(j=i+1;j<N;j++)
{
if(move[i].y>move[j].x)
{
total+=10;break;
}
}
}

return total;
}
*/

int main()
{
	int T;
	int i,s,t,m;
	Node *move;
	cin>>T;
	while(T--)
	{
		cin>>N;
		move=new Node[N];
		for(i=0;i<N;i++)
		{
			cin>>s>>t;
			if(s<t)
			{
				move[i].x=s;move[i].y=t;
			}
			else
			{
				move[i].x=t;move[i].y=s;
			}
		}
		m=opration(move);
		cout<<m<<endl;
	}
	return 0;
}
