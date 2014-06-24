#include<iostream>
using namespace std;

bool map[5][6];
int count1;

void findamount(int x,int y,int s,int d)
{
	if (x<1 || x>4 || y<1 || y>5) return;

	map[x][y]=false;
	if (x==s && d==y) 
	{
		count1++;
		map[x][y]=true;
		if (count1!=0 ) return;
	}
	if ( x+2<=4&&y+1<=5 &&map[x+2][y+1]) findamount(x+2,y+1,s,d);
	if (y>2&&x+2<=4 map[x+2][y-1]) findamount(x+2,y-1,s,d);
	if (x>2 && y+1<=5 map[x-2][y+1])findamount(x-2,y+1,s,d);
	if (x>2 && y>1 map[x-2][y-1]) findamount(x-2,y-1,s,d);
	if (x<=3&&y<=3 map[x+1][y+2])findamount(x+1,y+2,s,d);
	if (x<=3 &&y>2 map[x+1][y-2])findamount(x+1,y-2,s,d);
	if (x>1 &&y>2 map[x-1][y-2])findamount(x-1,y-2,s,d);
	if (x>1&&y<=2 map[x-1][y+2])findamount(x-1,y+2,s,d);
	map[x][y]=true;
}

int main()
{
	int s,d;
	int n;
	//while(cin>>s>>d)
	//cin>>s>>d;
	cin>>n;
	while(n--)
	{
		cin>>s>>d;
		if (s>4 || s<1 || d>5 || d<1) {puts("ERROR");continue;}//题目也讲的太不清楚了
		count1=-1;
		memset(map,true,sizeof(map));
		findamount(s,d,s,d);
		cout<<count1<<endl;
	}
	return 0;
}