/*
ID:shaoboz2
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char s[500],ch;
	int n,max=0,temp=0,i,right,left,ltemp,rtemp;
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	fin>>n;
	fin>>s;
	for(i=0;i<=n-1;i++)
	{
	 rtemp=ltemp=0;
      right=i;
	  ch=s[right];
	  while((s[right]==ch||s[right]=='w')&&rtemp<=n)
	  {
		  
		   rtemp++;
		   right++;
		   if (right>n-1) right=0; 
		   if (ch=='w') ch=s[right];
	  }
      left=i-1; 
	  if (left<0) left=n-1;
	  ch=s[left];
	  while((ch==s[left]||s[left]=='w')&&ltemp<=n)
	  { 
	 
      ltemp++;
	  left--;
	 if (left<0) left=n-1;
	 if (ch=='w') ch=s[left];
	  }
	  if (ltemp+rtemp>max)
	  {
		  max=ltemp+rtemp;
		  if (max>n) max=n;
	  }
	 
	} 
	fout<<max<<endl;
    return 0;
}
