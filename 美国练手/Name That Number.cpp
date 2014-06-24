/*
ID: shaoboz2
LANG: C++
TASK: namenum
*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const char code[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
char a[13],b[13];
int main()
{
  freopen("namenum.in","r",stdin);
  freopen("namenum.out","w",stdout);
  freopen("dict.txt","r",stderr);
  bool flag=1;
  cin>>a;
  while (fscanf(stderr,"%s",b)!=EOF)
    {
      bool flg=1;
      if (strlen(a)!=strlen(b)) continue;
      for (int i=0;b[i];i++) flg=flg&&(code[b[i]-'A']==a[i]);
      if (flg) flag=0,cout<<b<<endl;
    }
  if (flag) cout<<"NONE"<<endl;
  return 0;
}