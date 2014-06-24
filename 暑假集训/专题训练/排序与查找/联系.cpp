#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct 
{
	char ch[13];
	int num;
}elem;

int main()
{
	bool la[200000];
	elem re[100001];
	int a,b,limited,i,slen;
	string s;
  
  while(cin>>a>>b>>limited)
  {
	  cin>>s;
	  slen=s.size();
	  for(i=1;i<slen-b;;i++)
	  {
		  memset(la,true,sizeof(la));
		  for(j=0;j<slen;j++)
		  {
             
		  }
	  }
  } 
	return 0;
}