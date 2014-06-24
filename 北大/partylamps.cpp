#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;


bool lampState[101];
vector<int> burn,off;
set<string> finalRes;
int N;
int res=0;

void change1()
{
	int i;
	for(i=1;i<=N;++i)
	{
		lampState[i]=!lampState[i];
	}
}
void change2()
{
	int i;
	for(i=2;i<=N;i+=2)
	{
		lampState[i]=!lampState[i];
	}
}
void change3()
{
	int i;
	for(i=1;i<=N;i+=2)
	{
		lampState[i]=!lampState[i];
	}
}


void change4()
{
	int i;
	for(i=1;i<=N;i+=3)
	{
		lampState[i]=!lampState[i];
	}
}

void judgeP()
{
	string str;
	int i,num;
	str.clear();
	for( i=0;i<(int)burn.size();++i)
	{
		num=burn[i];
		//if(num>6) num=(num+1)%7;
		if (!lampState[num]) break;
	}
	if (i<(int)burn.size()) return;
	for( i=0;i<(int)off.size();++i)
	{
		num=off[i];
		//if (num>6) num=(num+1)%7;
		if (lampState[num]) break;
	}
	if (i<(int)off.size()) return;

	for(i=1;i<=N;++i)
	{
		num=i;
		//if (num>6) num=(num+1)%7;
		if (lampState[num]) str+='1';
		else str+='0';
	}
	res+=1;
	finalRes.insert(str);
}

int main()
{
	set<string>::iterator it;
	int times,changeNum;
	int changes;
	int i,j,k,l;
	int num;
	burn.clear();
	off.clear();
	finalRes.clear();
	
	cin>>N>>times;
	for(i=0;i<=N;++i)
	{
		lampState[i]=true;
	}
	while(cin>>num&&num!=-1)
	{
		burn.push_back(num);
	}
	while(cin>>num&&num!=-1)
	{
		off.push_back(num);
	}

	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			for(k=0;k<2;++k)
			{
				for(l=0;l<2;++l)
				{
					if((times<i+j+k+l)||((times-i-j-k-l)%2!=0)) continue;
					if (i==1) change1();
					if (j==1) change2();
					if (k==1) change3();
					if (l==1) change4();
					judgeP();
					if (i==1) change1();
					if (j==1) change2();
					if (k==1) change3();
					if (l==1) change4();
				}
			}
		}

	}

	if (res==0) 
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for(it=finalRes.begin();it!=finalRes.end();++it)
	{
		cout<<(*it)<<endl;
	}
	return 0;
}

