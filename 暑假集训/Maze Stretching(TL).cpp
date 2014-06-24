#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<vector>
using namespace std;
int n,m,v,h;//v:´¹Ö±  hË®Æ½
int sx,sy,ex,ey;

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};


class node
{
public :int v,h;
    private:
		
	friend bool operator < (const node & n1,const node &n2)
	{
		if (n1.v==n2.v) return n1.h<n2.h;
		return n1.v<n2.v;
	}
	friend bool operator == (const node & n1,const node &n2)
	{
		return n1.v==n2.v&&n1.h==n2.h;
	}
	
};



class node2 
{
public :
	int x,y,v,h;
private :
	friend bool operator <(const node2 &a,const node2 &b)
	{
		if (a.x==b.x)
		{
			if (a.y==b.y)
			{
				if (a.v==b.v)
				{
					return a.h<b.h;
				}
				return a.v<b.v;
			}
			return a.y<b.y;
		}
		return a.x<b.x;
	}

	friend bool operator ==(const node2 &a,const node2 &b)
	{
		return a.x==b.x && a.y==b.y && a.v==b.v && a.h==b.h;
	}
};


vector<string> map;
	double l;
set<node> vv;
set<node2> vis;

void work(int x,int y,int step,int v,int h)
{
	node tmp;
	node2 tmp1;
	int i;
	if (x<0|| x>=n || y<0||y>=m || h>l || map[x][y]=='#') return;
	tmp1.v=v;
	tmp1.h=h;
	tmp1.x=x;
	tmp1.y=y;


	if (vis.find(tmp1)!=vis.end())  return;

	vis.insert(tmp1);
	if (x==ex && y==ey)
	{
		tmp.v=v;
		tmp.h=h;
		vv.insert(tmp);
		return;
	}

	map[x][y]='#';
	for(i=0;i<4;++i)
	{
		if (i<2)
		{
			work(x+dir[i][0],y+dir[i][1],step+1,v+1,h);
		}
		else 
		{
			work(x+dir[i][0],y+dir[i][1],step+1,v,h+1);
		}
	}
	map[x][y]=' ';
}


int main()
{
	int t;

	int i,j;
	double ans;
	string str;
	set<node>::iterator it,jt;
	cin>>t;
	while(t--)
	{
		vis.clear();
		vv.clear();
		cin>>l>>n;
		map.clear();
		getline(cin,str);
		for(i=0;i<n;++i)
		{
			getline(cin,str);
			map.push_back(str);
		}
		m=int(map[0].size());
		sx=-1;sy=-1;
		ex=-1;ey=-1;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				if (map[i][j]=='S') {sx=i;sy=j;}
				else if (map[i][j]=='E') {ex=i;ey=j;}
				if (sx!=-1 && ex!=-1) break;
			}
			if (sx!=-1 && ex!=-1) break;
		}
		work(sx,sy,0,0,0);
		for(it=vv.begin();it!=vv.end();++it)
		{
			ans=double(l-(*it).h)/(*it).v;
			for(jt=vv.begin();jt!=vv.end();++jt)
		 {
			 if (it==jt) continue;
			 if (ans*(*jt).v+(*jt).h<l) break;
		 }
			if (jt==vv.end()) break;
		}
		printf("%.3lf",ans*100);
		putchar('%');
		putchar('\n');
	}
	return 0;
}

