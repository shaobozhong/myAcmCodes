#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int a[4][5]={{0,0,0,0,0},{6,9,12,0,0},{2,5,8,12,0},{0,3,7,13,4}};

struct Student
{
	int score;
	int state;
	int total;
	char name[30];
	int va[5];
};
int n,m,k;
Student s[55];

bool cmp(const Student &a,const Student &b)
{
	if (a.score==b.score) 
	{
		if (strcmp(a.name,b.name)<0) return true;
	}
	return a.score>b.score;
}

int find1(char name[])
{
	int i;
	for(i=0;i<m;++i)
	{
		if (strcmp(s[i].name,name)==0) return i;
	}
	return -1;
}

int main()
{
	
	
	map <int,int> ma;
	int x[5]={10,7,4,2,1},y[5]={6,4,2,1,0};
	int count1,i,j,num;
	int Nnum,stand,Qnum;
	char ch;
	char name[30];
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		ma.clear();
		for(i=0;i<n;++i)
		{
			scanf("%d",&Qnum);
			getchar();
			ch=getchar();
			stand=int(ch-'A');
			ma[Qnum]=stand;
		}
		for(i=0;i<m;++i)
		{
			s[i].total=0;
			for(j=0;j<5;++j)
			{
				s[i].va[j]=0;
			}
			scanf("%s%d",s[i].name,&s[i].state);
		}

		while(k--)
		{
			scanf("%s%d",name,&num);
			Nnum=find1(name);
			++s[Nnum].total;
			++(s[Nnum].va[ma[num]]);
		}
		
		for(i=0;i<m;++i)
		{
			for(j=0;j<5;++j)
			{
				if (s[i].va[j]<a[s[i].state][j])
				{
					s[i].score-=x[j]*(a[s[i].state][j]-s[i].va[j]);
				}
				else 
				{
					s[i].score+=y[j]*(s[i].va[j]-a[s[i].state][j]);
				}
			}
		}
		sort(s,s+m,cmp);
		for(i=0;i<m;++i)
		{
			printf("%s,%d,%d",s[i].name,s[i].score,s[i].total);
			for(j=0;j<5;++j)
			{
				printf(",%d",s[i].va[j]);
			}
			putchar('\n');
		}
	}
	return 0;
}

