#include<iostream>
#include<string>
using namespace std;
string str;
string istr;
bool b[5];
struct node
{
	int count1;
	char sign;
};
int find1(char ch)
{
	int i;
	for(i=0;i<int(str.size());++i)
	{
		if (str[i]==ch) return i;
	}
	return -1;
}

bool calc(bool a,char sign,bool b)
{
	switch(sign)
	{
	case 'A': return a||b;
	case 'K': return a&&b;
	case 'C':return (!a||b);
	case 'E':return a==b;
	}

	return false;
}

bool judge()
{
	bool res[200];
	node sign[200];
	int stail;
	int rtail;
	int loc;
	int i;
	int count1;
	stail=0;
	rtail=0;
	count1=0;
	for(i=0;i<int(istr.size());++i)
	{
		if (istr[i]=='K'||istr[i]=='A'||istr[i]=='N'||istr[i]=='C'||istr[i]=='E')
		{
			sign[stail].sign=istr[i];
			sign[stail++].count1=0;
		}
		else 
		{
			loc=find1(istr[i]);
			res[rtail++]=b[loc];
			sign[stail-1].count1++;
			while(stail>=1&&(sign[stail-1].sign=='N'||(sign[stail-1].count1==2)))//前一个字符是N 或者 前一个字符有了两个参数
			{
				if (sign[stail-1].sign=='N') 	 {res[rtail-1]=!res[rtail-1];--stail;sign[stail-1].count1++;}
				else {res[rtail-2]=calc(res[rtail-2],sign[stail-1].sign,res[rtail-1]);--stail;--rtail;sign[stail-1].count1++;}
			
			}
		}
	}

	return res[0];
}

bool work(int i)
{
	if (i==int(str.size()))
	{
		if (!judge()) return false;
		return true;
	}
	b[i]=true;
	if (!work(i+1)) return false;
	b[i]=false;
	if (!work(i+1)) return false;
	return true;
}

int main()
{
    int i;
	//freopen("2.txt","w",stdout);
	while(cin>>istr,istr!="0")
	{
		str="";
		for(i=0;i<int(istr.size());++i)
		{
			if ((istr[i]=='p'||istr[i]=='q'||istr[i]=='r'||istr[i]=='s'||istr[i]=='t')&& str.find(istr[i])==-1)
			{
				str.insert(str.end(),istr[i]);
			}
		}
		if (work(0)) puts("tautology");
		else puts("not");
	}
	return 0;
}