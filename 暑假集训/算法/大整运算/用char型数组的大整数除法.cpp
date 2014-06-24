#include<iostream>
#include<cstring>
using namespace std;
char  t2[210];
void minu(char *end,char *divisior)
{
	int i,j,l,len;
	int k,endlen=(int)strlen(end),sorlen=(int)strlen(divisior);
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
			  end[k]+=9;
		  end[k-1]--;
		  end[i]+=10;
		  end[i]=end[i]-divisior[j]+'0';
		}
	}
	len=endlen;
	for(i=0;i<=len-1;i++)
	{
		if (end[0]!='0') break;
		endlen=strlen(end);
		for(j=0;j<=endlen;j++)
		{
           end[j]=end[j+1];
		}
		end[endlen-1]=0;
	}
}

void division(char dividend[],char divisior[])
{
	char end[105]="";
	int endlen,i,count,sorlen=(int)strlen(divisior),endlen1;
	memset(t2,'0',sizeof(t2));
	endlen=(int)strlen(dividend);
	i=0;
	while(((int)strlen(end)==sorlen&&strcmp(end,divisior)<0)||(int)strlen(end)<sorlen)
	{
		end[i]=dividend[i];
		i++;
	}
	end[i]=0;
	count=0;
	i--;
	for(;i<=endlen-1;i++)
	{
		endlen1=(int)strlen(end);
		if ((strcmp(end,divisior)>=0&&endlen1==sorlen)||endlen1>sorlen)  
		{
			while((strcmp(end,divisior)>=0&&endlen1==sorlen)||endlen1>sorlen)
			{
			   minu(end,divisior);
			   t2[count]++;
			   endlen1=(int)strlen(end);
			}
		}
		count++;
		if (i==endlen-1) break;
		end[endlen1]=dividend[i+1];
		end[endlen1+1]=0;
		if(end[0]=='0') end[0]=0;
	}
	t2[count]=0;
}

int main()
{
	char divisior[105],dividend[210];//除数和被除数的英语单词
	cin>>dividend>>divisior;
	division(dividend,divisior);
	cout<<t2<<endl;
	return 0;
}