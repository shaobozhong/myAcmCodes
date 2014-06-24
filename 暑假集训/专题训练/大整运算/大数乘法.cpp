#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void de0(string &s)//删除无效0
{
	int slen,i;
  slen=s.length();
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
  slen=s.length();
  while(s[0]=='0'&&s[1]!='.'&&slen!=1)
  {
	  s.erase(0,1);
	  slen=s.length();
  }
}

int dex(string &multiplicand,string &multiplicator)//统计小数的位数并去掉小数点
{
   int x1,x2,mcandlen,mtorlen,candloca,torloca;
   mcandlen=multiplicand.length();
   mtorlen=multiplicator.length();
   candloca=multiplicand.find(".");
   torloca=multiplicator.find(".");
   if (candloca!=-1) {x1=mcandlen-candloca-1;multiplicand.erase(candloca,1); }else x1=0;
   if (torloca!=-1)  {x2=mtorlen-torloca-1;multiplicator.erase(torloca,1);}else x2=0;
   return x1+x2;
}   


string multiplication( string &multiplicand,string &multiplicator)
{
   int *get_cand,*get_tor,*result,candlen,torlen,i,j,count,temp,candg=0,torg=0,slen;
   string ch;
   string xresult;
   string str;
   int xlen;
   de0(multiplicand);
   de0(multiplicator);
   if (multiplicand=="0"||multiplicator=="0") return "0";
   xlen=dex(multiplicand,multiplicator);
   candlen=multiplicand.length();
   torlen=multiplicator.length();
   get_cand=new int[candlen+2];
   get_tor=new int[torlen+2];
   memset(get_cand,0,sizeof(get_cand));
   memset(get_tor,0,sizeof(get_tor));
    count=1;
	while (multiplicand.length()>=4)
	{
		str=multiplicand.substr(multiplicand.length()-4);
		multiplicand.erase(multiplicand.length()-4);
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
	while (multiplicator.length()>=4)
	{
		str=multiplicator.substr(multiplicator.length()-4);
		multiplicator.erase(multiplicator.length()-4);
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
    result=new int[candg*torg+2];
	for(i=1;i<=candg*torg+1;i++)
		result[i]=0;
    for(i=1;i<=candg;i++)
	{
		for(j=1;j<=torg;j++)
		{
			result[i+j-1]+=get_cand[i]*get_tor[j];
			result[i+j]+=result[i+j-1]/10000;
			result[i+j-1]=result[i+j-1]%10000;
		}
	}
   i=candg*torg+1;
   str.clear();
  while(result[i]==0) i--;
   temp=result[i];
   while(temp)
   {
	   ch.push_back(temp%10+48);
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
	   ch.push_back(temp%10+48);
	   str.insert(0,ch);
	   ch.clear();
	   temp/=10;
   }
    slen=(int)str.length();
   if (slen<4) 
	 {
		 for(j=1;j<=4-slen;j++)
		 {
			 str.insert(0,"0");
		 }
	 }
	 xresult.append(str);
	 str.clear();
   }
   if (xlen>0)
   {
	   slen=xresult.length();
	   xresult.push_back(' ');
   count=0;
   for(i=xresult.length()-1;i>=0;i--)
   {
	   xresult[i]=xresult[i-1];
	   count++;
	   if (count==xlen) {xresult[i-1]='.';break;}
	   if (count<xlen&&i==1) {xresult.insert(0,"0");i++;}
   }
   if (i==1) xresult.insert(0,"0");
   }
        
   de0(xresult);
   return xresult;
}
int main()
{
	string s,t;
	while(cin>>s>>t)
    cout<<multiplication(s,t)<<endl;
	return 0;
}