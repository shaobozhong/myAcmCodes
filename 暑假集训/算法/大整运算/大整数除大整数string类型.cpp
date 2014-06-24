#include<iostream>
#include<string>
using namespace std;
char  t2[210];
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
			  end[l]+=9;
		  end[k-1]--;
		 
		  end[i]+=10;
		  end[i]=end[i]-divisior[j]+'0';
		}
	}
	for(i=0;i<=endlen-1;i++)
	{
		if (end[0]!='0') break;
		end.erase(0,1);
	}
}

void division(string dividend,string divisior)
{
	string end="";
	int endlen,i,count,sorlen=divisior.size(),endlen1;
	memset(t2,'0',sizeof(t2));
	endlen=dividend.size();
	i=0;
	while((end.size()==sorlen&&end<divisior)||end.size()<sorlen)
	{
		end.push_back(dividend[i]);
		i++;
	}
	count=0;
	i--;
	for(;i<=endlen-1;i++)
	{
		endlen1=end.size();
		if ((endlen1==sorlen&&end>=divisior)||endlen1>sorlen)  
		{
			while((endlen1==sorlen&&end>=divisior)||endlen1>sorlen)
			{
			   minu(end,divisior);
			   t2[count]++;
			   endlen1=end.size();
			}
		}
		count++;
		if (i==endlen-1) break;
		end.push_back(dividend[i+1]);
		if(end[0]=='0') end.erase(0,1);
	}
	t2[count]=0;
}

int main()
{
	string divisior,dividend;//除数和被除数的英语单词
	cin>>dividend>>divisior;
	division(dividend,divisior);
	cout<<t2<<endl;
	return 0;
}
