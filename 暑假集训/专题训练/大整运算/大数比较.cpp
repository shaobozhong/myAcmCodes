#include<iostream>
#include<string>
using namespace std;

int cmp(string &s,string &t)
{
	string sz="",sx="",tz="",tx="";
   int sloca,tloca,i,slen,tlen,szlen,tzlen;
   slen=s.size();
   tlen=t.size();
   sloca=s.find(".");
   tloca=t.find(".");
   if (sloca==-1) sloca=slen;
   if (tloca==-1) tloca=tlen;
   for(i=0;i<=sloca-1;i++)
	   sz.push_back(s[i]);
   for(i=0;i<=tloca-1;i++)
	   tz.push_back(t[i]);
   szlen=sz.size();
   tzlen=tz.size();
   if (szlen<tzlen) return -1;  
   else if (szlen==tzlen) {if (sz<tz) return -1;else if (sz>tz) return 1;}
   else return 1;
   if (szlen==tzlen && sz==tz)
   {
	   i=slen-1;
	   while(i>=sloca&&s[i]=='0')
	   {
		   s.erase(i,1);
		   i--;
	   }
	   slen=s.size();
	   i=tlen-1;
	   while(i>=tloca&&t[i]=='0')
	   {
		   t.erase(i,1);
		   i--;
	   }
	   tlen=t.size();
      for(i=sloca+1;i<=slen-1&&i<=tlen-1;i++)
	   {
		   if (s[i]>t[i]) return 1;
		   if (t[i]>s[i]) return -1;
	   }
	   if (i<slen) return 1;
	   if (i<tlen) return -1;
   }
   return 0;
}

int main()
{
	bool sfh=0,tfh=0;
	int result;
	string s,t;
	while(cin>>s>>t)
	{
		if (s[0]=='-') {sfh=1;s.erase(0,1);}
		if (t[0]=='-') {tfh=1;t.erase(0,1);}
		if (s=="0"&&t=="0") {cout<<"0"<<endl;continue;}
		if (sfh&&!tfh) {cout<<"-1"<<endl;continue;} 
		if (tfh&&!sfh) {cout<<"1"<<endl;continue;}
				result=cmp(s,t);
				if (sfh&&tfh) cout<<-1*result<<endl;
				else cout<<result<<endl;
			
	}
	return 0;
}