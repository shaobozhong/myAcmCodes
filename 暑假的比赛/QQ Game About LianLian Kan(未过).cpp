#include<iostream>
#include<string>
using namespace std;
string s[10];

typedef struct 
{
	int x,y;
}loca;
typedef struct 
{
	int u,d,l,r;
}del;

bool panduan(int ax,int ay,int nx,int ny)
{
  del a,n;
  int i,j;
  a.u=0;a.d=0;a.l=0;a.r=0;
    for(i=ax;i>=0;--i)// 上
	{
		if (s[i][ay]!=' ') break;
		++a.u;
	}
	for(i=ax;i<=9;++i)//下
	{
		if (s[i][ay]!=' ') break; 
		++a.d;
	}

	for(i=ay;i>=0;--i)//左
	{
	  if (s[ax][i]!=' ') break;
	  ++a.l;
	}
	
	for(i=ay;i>=0;++i)// 右
	{
	  if (s[ax][i]!=' ') break; 
	  ++a.r;
	}
	


	//后点击的点
	n.u=0;n.d=0;n.l=0;n.r=0;
    for(i=nx;i>=0;--i)// 上
	{
		if (s[i][ny]!=' ') break;
		++n.u;
	}
	
	for(i=nx;i<=9;++i)//下
	{
		if (s[i][ny]!=' ') break;
		++n.d;
	}
	
	for(i=ny;i>=0;--i)//左
	{
	  if (s[nx][i]!=' ') break; 
	  ++n.l;
	}
	
	for(i=ny;i>=0;++i)// 右
	{
	  if (s[nx][i]!=' ') break;
	  ++n.r;
	}
	

	//开始判断
	if (nx==ax&&ny+1>=ay-a.l&&ny-1<=ay+a.r) return true;//列方向上 直接能到
	if (ny==ay&&nx+1>=ax-a.l&&nx-1<=ax+a.r) return true;//行方向上 直接能到
	if (ax+a.d>=nx&&ax-a.u<=nx&&ny+n.r>=ay&&ny-n.l<=ay) return true;//两段线
	if (ay+a.r>=ny&&ay-a.l<=ny&&nx+n.d>ax&&nx-n.u<=ax) return true;
	//三段线
	for(i=ax-a.u;i<=ax+a.d&&i<10;++i)
	{
		if(i>=nx-n.u&&i<=nx+n.d)
		{
			for(j=ay>ny?ny:ay;j<=ay>ny?ay:ny&&j<10;++j)
			{
				if (s[i][j]!=' ') break;
			}
			if (j==ay>ny?ay:ny) return true;
		}
	}

	for(i=ay-a.l;i<=ay+a.r&&i<10;++i)
	{
		if(i>=ny-n.l&&i<=ny+n.r)
		{
			for(j=ax>nx?nx:ax;j<=ax>nx?ax:nx&&j<10;++j)
			{
				if (s[i][j]!=' ') break;
			}
			if (j==ax>nx?ax:nx) return true;
		}
	}	
	return false;
}
int main()
{
	loca already,new_press;
    int t,n,i,j,count;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		for(i=0;i<10;++i)
		{
			getline(cin,s[i]);
			for(j=s[i].size();j<10;++j)
			{
				s[i].push_back(' ');
			}
		}
        scanf("%d",&n);
		already.x=0;already.y=0;
		for(i=1;i<=n;++i)
		{
			if (already.x==0) {scanf("%d%d",&already.x,&already.y);continue;}
			scanf("%d%d",&new_press.x,&new_press.y);
			if (already.x==new_press.x&&already.y==new_press.y) continue;
			if (s[already.x-1][already.y-1]==s[new_press.x-1][new_press.y-1])
			{
			if (panduan(already.x-1,already.y,new_press.x-1,new_press.y)) 
				{
					s[already.x-1][already.y-1]=' ';
					s[new_press.x-1][new_press.y-1]=' ';
					already.x=0;
				}
			//else {already.x=new_press.x;already.y=new_press.y;}
			}
			//else {already.x=new_press.x;already.y=new_press.y;}
		}
		count=0;
        for(i=0;i<=9;++i)
		{
			for(j=0;j<=9;++j)
			{
				if (s[i][j]!=' ') ++count;
			}
		}
		if (count==0) puts("Yes,all patterns are eliminated!");
		else 
		{
			printf("No,%d pattern(s) are left!\n",count);
		}
		getchar();
	}
	return 0;
}