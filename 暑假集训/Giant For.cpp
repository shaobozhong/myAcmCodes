#include<iostream>
#include<set>
using namespace std;


class node
{
public: 
	int x,y;
private:
	friend bool operator <(const node &a,const node &b)
	{
		if (a.x<b.x) return true;
     	if (a.x==b.x && a.y<b.y) return true;
		return false;
	}

	friend bool operator ==(const node &a,const node &b)
	{
		if (a.x==b.x && a.y==b.y) return true;
	}
};


int main()
{
	set <node> dic;
	set <node> :: iterator it;
	node tmp;

	int n,casenum;
	char str[10];
	int i;
	casenum=0;
	while(scanf("%d",&n),n!=0)
	{
		if (casenum) putchar('\n');
		++casenum;
		dic.clear();
		printf("Case %d:\n",casenum);
		while(n--)
		{
			scanf("%s",str);
			if (strcmp(str,"add")==0)
			{
				scanf("%d%d",&tmp.x,&tmp.y);
				dic.insert(tmp);
			}
			else 
			{
				if (strcmp(str,"remove")==0) 
				{
					scanf("%d%d",&tmp.x,&tmp.y);
					dic.erase(dic.find(tmp));
				}
				else 
				{
					if (strcmp(str,"find")==0)
					{
						bool flag;
						flag=false;
						scanf("%d%d",&tmp.x,&tmp.y);
						if (dic.count(tmp)==0) {dic.insert(tmp);flag=true;}
						for(it=dic.find(tmp);it!=dic.end();++it)
						{
							if (((*it).x>(tmp).x)&&(*it).y>tmp.y) break;
						}
						if (it==dic.end()) {puts("-1");}
						else 
						{
							printf("%d %d\n",(*it).x,(*it).y);
						}
						if (flag) dic.erase(dic.find(tmp));
					}
				}
			}
		}
	}

	return 0;
}

