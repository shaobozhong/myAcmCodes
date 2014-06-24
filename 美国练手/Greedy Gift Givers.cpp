#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


typedef struct
{
	char name[20];
	int money;
	int omoney;
}Gift;

int find(Gift *per,char name[],int n)
{
	int i;
	for(i=0;i<=n-1;i++)
		if (strcmp(per[i].name,name)==0) return i;
	return 0;
}
void calc( Gift *per,int loc,int n)
{
  int i,smoney,num;
  int loca;
  char reciever[20];
  cin>>smoney>>num;
  if (num!=0) per[loc].money+=smoney%num;
  per[loc].omoney=smoney;
  for(i=1;i<=num;i++)
  {
	  cin>>reciever;
	  loca=find(per,reciever,n);
	  per[loca].money+=smoney/num;
  }
}
int main() {
	int n,i,loc;
	char name[20];
	Gift *per;
	while(cin >> n)
	{
	per =new Gift[n];
	for(i=0;i<=n-1;i++)
	{
		cin>>per[i].name;
		per[i].money=0;
	}
	for(i=0;i<=n-1;i++)
	{
		cin>>name;
		loc=find(per,name,n);
		calc(per,loc,n);
	}
    for(i=0;i<=n-1;i++)
	{
		cout<<per[i].name<<" "<<per[i].money-per[i].omoney<<endl;
	}
	}
	return 0;
}