#include<iostream>
#include<set>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;

struct Position{
	int x,y;
	bool operator<(const Position p)const{
		return x<p.x;
	}
	friend ostream& operator<<(ostream &out,Position p);
};


ostream& operator<<(ostream &out,Position p){
	return out<<p.x<<" "<<p.y;

}
int main()
{
	priority_queue<Position> q;
	for (int i=0;i<10;++i)
	{
		Position p;
		p.x=i;
		p.y=i;
		q.push(p);
	}
	
	cout<<q.size()<<endl;
	cout<<q.top().x<<endl;
	q.pop();
	cout<<q.top()<<endl;
	return 0;
}