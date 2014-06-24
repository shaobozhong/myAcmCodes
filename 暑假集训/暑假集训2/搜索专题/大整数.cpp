#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void de0(string &s)//删除无效0
{
	int slen,i;
  slen=int(s.length());
  if (s.find(".")!=-1)
  {
  i=slen-1;
  while(s[i]=='0'||s[i]=='.')
  {
	  if (s[i]=='.') {s.erase(i,1);break;}
	   s.erase(i,1);
	   i--;
  }
  }
  slen=int(s.length());
  while(s[0]=='0'&&s[1]!='.'&&slen!=1)
  {
	  s.erase(0,1);
	  slen=int(s.length());
  }
}

int dex(string &multiplicand,string &multiplicator)//统计小数的位数并去掉小数点
{
   int x1,x2,mcandlen,mtorlen,candloca,torloca;
   mcandlen=int(multiplicand.length());
   mtorlen=int(multiplicator.length());
   candloca=int(multiplicand.find("."));
   torloca=int(multiplicator.find("."));
   if (candloca!=-1) {x1=mcandlen-candloca-1;multiplicand.erase(candloca,1); }else x1=0;
   if (torloca!=-1)  {x2=mtorlen-torloca-1;multiplicator.erase(torloca,1);}else x2=0;
   return x1+x2;
}   


string multiplication( string &multiplicand,string &multiplicator)
{
   int candlen,torlen,i,j,count,candg=0,torg=0,slen;
   __int64  *result,temp,*get_cand,*get_tor;
   string ch;
   string xresult;
   string str;
   int xlen;
   de0(multiplicand);
   de0(multiplicator);
   if (multiplicand=="0"||multiplicator=="0") return "0";
   xlen=dex(multiplicand,multiplicator);
   candlen=int(multiplicand.length());
   torlen=int(multiplicator.length());
   get_cand=new __int64[candlen/9+2];
   get_tor=new __int64[torlen/9+2];
   memset(get_cand,0,sizeof(get_cand));
   memset(get_tor,0,sizeof(get_tor));
    count=1;
	while (int(multiplicand.length())>=9)
	{
		str=multiplicand.substr(int(multiplicand.length())-9);
		multiplicand.erase(int(multiplicand.length())-9);
		get_cand[count]=atoi(str.c_str());
		++count;
	}
	if (!multiplicand.empty())
	{
		str=multiplicand;
		multiplicand.clear();
		get_cand[count]=atoi(str.c_str());
		candg=count;
	}
	if (candg==0) candg=count-1;
	count=1;
	while (int(multiplicator.length())>=9)
	{
		str=multiplicator.substr(int(multiplicator.length())-9);
		multiplicator.erase(int(multiplicator.length())-9);
		get_tor[count]=atoi(str.c_str());
		++count;
	}
	if (!multiplicator.empty())
	{
		str=multiplicator;
		multiplicator.clear();
		get_tor[count]=atoi(str.c_str());
		torg=count;
	}
	if (torg==0) torg=count-1;
    result=new __int64[candg*torg+2];
	for(i=1;i<=candg*torg+1;i++)
		result[i]=0;
    for(i=1;i<=candg;i++)
	{
		for(j=1;j<=torg;j++)
		{
			result[i+j-1]+=get_cand[i]*get_tor[j];
			result[i+j]+=result[i+j-1]/1000000000;
			result[i+j-1]=result[i+j-1]%1000000000;
		}
	}
   i=candg*torg+1;
   str.clear();
  while(result[i]==0) i--;
   temp=result[i];
   while(temp)
   {
	   ch.push_back(char(temp%10+48));
	   str.insert(0,ch);
	   ch.clear();
	   temp/=10;
	   
   }
   i--;
   xresult.append(str);
   str.clear();
   while(i>=1)
   {
   temp=result[i--];
   while(temp)
   {
	   ch.push_back(char(temp%10+48));
	   str.insert(0,ch);
	   ch.clear();
	   temp/=10;
   }
    slen=(int)str.length();
   if (slen<9) 
	 {
		 for(j=1;j<=9-slen;j++)
		 {
			 str.insert(0,"0");
		 }
	 }
	 xresult.append(str);
	 str.clear();
   }
   if (xlen>0)
   {
	   slen=int(xresult.length());
	   xresult.push_back(' ');
   count=0;
   for(i=int(xresult.length()-1);i>=0;i--)
   {
	   xresult[i]=xresult[i-1];
	   count++;
	   if (count==xlen) {xresult[i-1]='.';break;}
	   if (count<xlen&&i==1) {xresult.insert(0,"0");i++;}
   }
   if (i==1) xresult.insert(0,"0");
   }
        
   de0(xresult);
   delete[] get_cand;
   delete[] get_tor;
   return xresult;
}

string plus_1(const string &a,const string &b)
{
	string result;
	char ttemp[2];
	int alen,blen,i,j;
	int add,temp;
	ttemp[1]='\0';
	alen=int(a.size());
	blen=int(b.size());
	add=0;
	for(i=alen-1,j=blen-1;i>=0&&j>=0;i--,j--)
	{
		temp=add+((int)a[i]-48)+((int)b[j]-48);
		add=temp/10;
		ttemp[0]=temp%10+48;
		result.insert(0,ttemp);
	}

	while(i>=0)
	{
		for(;i>=0;i--)
		{
			temp=add+(a[i]-48);
			add=temp/10;
			ttemp[0]=temp%10+48;
			result.insert(0,ttemp);
		}
	}

	while(j>=0)
	{
		for(;j>=0;j--)
		{
			temp=add+(b[j]-48);
			add=temp/10;
			ttemp[0]=temp%10+48;
			result.insert(0,ttemp);
		}
	}
	if (add!=0)
	{ttemp[0]=add%10+48;
	result.insert(0,ttemp);
	}
	return  result;
}

string calc(string p)
{
	string pp,pp1;
	string res;
	string temp;
	pp=p;
	res="3";
	if (res=="") res="0";
	res=multiplication(res,pp);
	pp=p;
	pp1=p;
	temp=multiplication(pp1,pp);
	pp=p;
	pp1=p;
	res=plus_1(res,temp);
	temp=multiplication(temp,pp);
	pp=p;;
	res=plus_1(res,temp);
	return res;
}

bool panduan(const string &a,const string &b)
{
	int i;
	if (int(a.length())<int(b.length())) return false;
    else if (int(a.length())>int(b.length()))  return true;
	for(i=0;i<int(a.size());++i)
	{
		if (a[i]<b[i]) return false;
		else if (a[i]>b[i]) return true;
	}
	return false;
}


int main()
{
	int i;
	char ch;
	string num;
	string p;
	while(cin>>num)
	{
	p=num;
	for(i=0;i<int(num.length());++i)
	{
		p[i]='0';
	}
	for(i=0;i<int(p.length());++i)
	{
		ch='0';
		while(1)
		{
			p[i]=ch;
			if (panduan(calc(p),num)) break;
			ch++;
		}
		p[i]--;
	}
	for(i=0;i<int(p.length());++i)
	{
		if (p[i]!='0') break;
	}
	if (i>=int(p.length())) {puts("0");continue;}
	for(;i<int(p.length());++i)
	{
		putchar(p[i]);
	}
	cout<<endl;
	}
	return 0;
}