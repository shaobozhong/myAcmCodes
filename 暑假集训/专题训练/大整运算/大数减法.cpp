#include<iostream>
#include<string>
using namespace std;
void minu(string &end,string divisior)
{
	int i,j,l;
	int k,endlen=end.size(),sorlen=divisior.size();
	for(i=endlen-1,j=sorlen-1;i>=0&&j>=0;i--,j--)
	{
		if(end[i]>=divisior[j]) end[i]=end[i]-divisior[j]+'0';
		else 
		{
		  k=i;
		  while(end[k-1]-1<'0')
		  {
			  k--;
		  } 
		  for(l=k;l<=i-1;l++)
		  {
			  end[l]+=9;
		  }
		  end[k-1]--;
		 
		  end[i]+=10;
		  end[i]=end[i]-divisior[j]+'0';
		}
	}
	for(i=0;i<=endlen-1;i++)
	{
		if (end[0]!='0'||i==endlen-1) break;
		end.erase(0,1);
	}
	for(;i<=endlen-1;i++)
		cout<<end[i];
	cout<<endl;
}

int main()
{
	string end,divisior;
	while(cin>>end>>divisior)
	{
      minu(end,divisior);
	}
	return 0;
}