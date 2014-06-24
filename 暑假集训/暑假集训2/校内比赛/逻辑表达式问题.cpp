#include<iostream>
#include<string>
using namespace std;
string istr;//村存储输入的数据
string str;//存储所有的字母
int n;//变量即字母数

bool b[15];//所有字母即变量的状态

bool weight(char a,char b)
{
	if (b=='(') return false;//括号优先
	if (a=='(') return false;//左括号优先级最低
	if (a=='~') return true;//在前最高
	if (b=='~') return false;//在后则前面的肯定不算 也是高
	if (a=='>'&&b!='>') return false;//优先级最低
	if (b=='>') return true;//优先级最低 所以后面出现则前面就可以算了
	if (a=='|' &&b!='>' && b!='|') return false;//优先级倒数第二
	if (a=='&'&&b!='>' && b!='|'&&b!='&' ) return false;
	return true;
}

int find1(char ch)
{
	int i;
	for(i=0;i<n;++i)
	{
		if (ch==str[i]) return i;
	}
	return -1;
}

bool calc(bool a,char sign,bool b)
{
	switch(sign)
	{
	case '&': return (a&&b);
	case '|':return (a||b);
	case '>':return (!a||b);
	}
	return false;
}

bool judge()
{
	char sign[155];
	bool res[155];
	int stail,rtail,loc;
	stail=0;
	rtail=0;
	int i;
	for(i=0;i<int(istr.size());++i)
	{
		if (istr[i]=='-') continue;
		if (istr[i]=='(')
		{
			sign[stail++]='(';
		}
		else 
		{
			if (istr[i]==')')
			{
				while(sign[stail-1]!='(')
				{
					if (sign[stail-1]=='~')
					{
						res[rtail-1]=!res[rtail-1];
						stail--;
					}
					else 
					{
						res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
						rtail--;
						stail--;
					}
				}
				stail--;
				while(stail>0 && weight(sign[stail-2],sign[stail-1]))
				{
					if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;}
					else 
					{
						res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
						rtail--;
						stail--;
					}
				}
			}
			else 
			{
				if ((istr[i]>='a'&&istr[i]<='z')||(istr[i]>='A'&&istr[i]<='Z')) 
				{
					loc=find1(istr[i]);
					res[rtail++]=b[loc];
				}
				else 
				{
					if (stail>0 && weight(sign[stail-1],istr[i]))
					{
						if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;}
						else 
						{
							res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
							rtail--;
							stail--;
						}
						while(stail>0 && weight(sign[stail-2],sign[stail-1]))
						{
							if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;} //非是单目运算
							else 
							{
								res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
								rtail--;
								stail--;
							}
						}
						sign[stail++]=istr[i];
					}
					else
					{
						sign[stail++]=istr[i];
					}
				}
			}
		}
	}

	while(stail>0)
	{
		if (sign[stail-1]=='~') {res[rtail-1]=!res[rtail-1];stail--;}
		else 
		{
			res[rtail-2]=calc(res[rtail-2],sign[stail-1],res[rtail-1]);
			rtail--;
			stail--;
		}
	}

	return res[0];
}

bool work(int num)
{
	if (num>=n)//所有字母都有了状态
	{
		if (judge()) return true;
		return false;
	}

	b[num]=true;
	if (work(num+1)) return true;
	b[num]=false;
	if (work(num+1)) return true;
	return false;
}


int main()
{
	int i;
	while(cin>>istr)
	{
		str="";
		for(i=0;i<int(istr.size());++i)
		{
			if (str.find(istr[i])==-1) str.insert(str.end(),istr[i]);
		}
		n=int(str.size());
		if (work(0)) puts("y");
		else puts("n");
	}
	return 0;
}