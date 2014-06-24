#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char map[9][9];
char act_1[10];
char tact;
bool direct[8],tdirect[8];
typedef struct 
{
	int x;
	int y;
}loca;

int calc(loca l,char act,bool *tdirec)
{
	int value;
	int i,j;
	i=l.x;j=l.y;
	value=1;
	memset(tdirect,false,sizeof(tdirect));
	while(i<=7&&j<=7)//下
	{
		++i;
		if (map[i][j]==act)
		{
			if (i-l.x>1)
			{
			value+=i-l.x-1;
			tdirect[0]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//上
	while(i>=0&&j>=0)
	{
		--i;
		if (map[i][j]==act)
		{
			if (l.x-i>1)
			{
			value+=l.x-i-1;
			tdirect[1]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//右
	while(i<=7&&j<=7)
	{
		++j;
		if (map[i][j]==act)
		{
			if (j-l.y>1)
			{
			value+=j-l.y-1;
			tdirect[2]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//左
	while(i>=0&&j>=0)
	{
		--j;
		if (map[i][j]==act)
		{
			if (l.y-j>1)
			{
			value+=l.y-j-1;
			tdirect[3]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//左上
	while(i>=0&&j>=0)
	{
		--i;--j;
		if (map[i][j]==act)
		{
			if (l.x-i>1)
			{
			value+=l.x-i-1;
			tdirect[4]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//右上
	while(i>=0&&j<=7)
	{
		--i;++j;
		if (map[i][j]==act)
		{
			if (l.x-i>1)
			{		
			value+=l.x-i-1;
			tdirect[5]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//左下
	while(i<=7&&j>=0)
	{
		++i;--j;
		if (map[i][j]==act)
		{
			if (i-l.x>1)
			{
			value+=i-l.x-1;
			tdirect[6]=true;
			}
			break;
		}
	}
	i=l.x;j=l.y;//右下
	while(i<=7&&j<=7)
	{
		++i;++j;
		if (map[i][j]==act)
		{
			if (i-l.x>1)
			{
			value+=i-l.x-1;
			tdirect[7]=true;
			}
			break;
		}
	}
	return value;
}

void color(loca l,char act,bool *direct)
{
	int i,j;

	map[l.x][l.y]=act;
	if (direct[0])
	{
		i=l.x;j=l.y;
		while(i<=7&&j<=7)//下
		{
			++i;
			if (map[i][j]==act)
			{
				break;
			}
			map[i][j]=act;
		}
	}
	if (direct[1])
	{
	i=l.x;j=l.y;//上
	while(i>=0&&j>=0)
	{
		--i;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
	if (direct[2])
	{
	i=l.x;j=l.y;//右
	while(i<=7&&j<=7)
	{
		++j;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
	if (direct[3])
	{
	i=l.x;j=l.y;//左
	while(i>=0&&j>=0)
	{
		--j;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
	if (direct[4])
	{
	i=l.x;j=l.y;//左上
	while(i>=0&&j>=0)
	{
		--i;--j;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
	if (direct[5])
	{
	i=l.x;j=l.y;//右上
	while(i>=0&&j<=7)
	{
		--i;++j;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
	if (direct[6])
	{
	i=l.x;j=l.y;//左下
	while(i<=7&&j>=0)
	{
		++i;--j;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
	if (direct[7])
	{
	i=l.x;j=l.y;//右下
	while(i<=7&&j<=7)
	{
		++i;++j;
		if (map[i][j]==act)
		{
			break;
		}
		map[i][j]=act;
	}
	}
}
int main()
{
	vector<loca> e;
	loca temp;
	int white,black;
	int i,j;
	int value,tvalue;
	bool aw,ab;
	vector<loca>::iterator k,lable;
	while(scanf("%s",map[0]))
	{
		if (strcmp(map[0],"EndOfInput")==0) break;
		aw=false;ab=false;
		white=0;black=0;
		for(i=1;i<8;++i)
		{
			scanf("%s",map[i]);
		}
		for(i=0;i<8;++i)
		{
			for(j=0;j<8;++j)
			{
				if (map[i][j]=='w') 
				{
					++white;
				}
				else 
				{
					if (map[i][j]=='b') ++black;
					else 
					{
						if (map[i][j]=='e') {temp.x=i;temp.y=j;e.push_back(temp);}
					}
				}
			}
		}
		scanf("%s",act_1);
		if (strcmp(act_1,"White")==0) tact='w';
		else tact='b';
		while(e.size()!=0)
		{
			if (aw&&ab) break;
			value=1;temp.x=-1;temp.y=-1;
			for(k=e.begin();k!=e.end();++k)
			{
				tvalue=calc(*k,tact,tdirect);
				if (tvalue>=value) 
				{
					value=tvalue;
					lable=k;
					for(j=0;j<=7;++j)
					{
						direct[j]=tdirect[j];
					}
				}
			}
			if (tact=='w'&&value==1) {aw=true;tact='b';continue;}
			else if (tact=='b'&&value==1) {ab=true;tact='w';continue;}
			color(*lable,tact,direct);
			if (tact=='w') {white+=value;black-=value-1;tact='b';}
			else {black+=value;white-=value-1;tact='w';}
			e.erase(lable);
		}
		if (white>black) puts("White");
		else if (white==black) puts("Draw");
		else if (black>white) puts("Black");
		e.clear();
	}
	return 0;
}