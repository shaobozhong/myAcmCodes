#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Score
{
	vector <int> score;  
};

struct node
{
	char str[100];
};
int letter[26];
Score score[26];
node str[100001];
int ss;

bool cmp(const node &a,const node &b)
{
	//return a.size()<b.size();
	return strlen(a.str)<strlen(b.str);
}

bool  work(int i,/*const string &str*/ char str[])
{
	bool res=false;
	//if (i==int (str.size())) return true;
	if (i==int (strlen(str))) return true;
	int save;
	int tmp=int(str[i])-97;
	if (letter[tmp]>0)
	{
		ss+=score[tmp].score.front();
		save=score[tmp].score.front();
		pop_heap(score[tmp].score.begin(),score[tmp].score.end());
		score[tmp].score.pop_back();
		make_heap(score[tmp].score.begin(),score[tmp].score.end());
		--letter[tmp];
		res=(work(i+1,str));
        ++letter[tmp];
		score[tmp].score.push_back(save);
		make_heap(score[tmp].score.begin(),score[tmp].score.end());
	}
	return res;
}

int main()
{
	int i;
	char ch;
	int sc;
    int max1;
	int l;
    //freopen("∆¥¥’Œ Ã‚.in","r",stdin);
	//freopen("1.txt","w",stdout);
	scanf("%d",&l);
	for(i=0;i<l;++i)
	{
		scanf("%s",str[i].str);
	}
	sort(str,str+l,cmp);

	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		max1=0;
		scanf("%d",&m);
		for(i=0;i<26;++i)
		{
			letter[i]=0;
			score[i].score.clear();
		}
		for(i=0;i<m;++i)
		{
			getchar();
			int tmp;
			scanf("%c%d",&ch,&sc);
			tmp=int(ch)-97;
			++letter[tmp];
			score[tmp].score.push_back(sc);
			make_heap(score[tmp].score.begin(),score[tmp].score.end());
		}
		for(i=0;i<l;++i)
		{
			//if (int(str[i].size())>m) break;
			if (int(strlen(str[i].str))>m)  break;
			ss=0;
			if (work(0,str[i].str))
			{
			    if (max1<ss) max1=ss;
				
			}
		}
		printf("%d\n",max1);
	}
	return 0;
}