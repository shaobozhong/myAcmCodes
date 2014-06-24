#include<iostream>
#include<cstring>
using namespace std;
typedef struct 
{
	char num[210];
}elem;
	elem a[101];
	char result[210];
	char dividend[210];

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
		for(j=0;j<=endlen-2;j++)
		{
           end[j]=end[j+1];
		}
		end[endlen-1]=0;
	}
}

void division(char dividend[],char divisior[],char *t2)
{
	char end[105]="";
	int endlen,i,count,sorlen=(int)strlen(divisior),endlen1;
	for(i=0;i<=209;i++)
		t2[i]='0';
	//memset(t2,'0',sizeof(t2));
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
void excute(char  *s,char *t,char *t2,int n)
{
	char divisior[4];
	int slen,tlen,count,loca,temp,i,j,weight;
        memset(result,'0',sizeof(result));
		slen=(int)strlen(s);
		tlen=(int)strlen(t);
		count=0;
		for(i=tlen-1;i>=0;i--)
		{
			loca=count++;
			for(j=slen-1;j>=0;j--)
			{
				temp=(s[j]-'0')*(t[i]-'0');
				temp+=result[loca]-'0';
                result[loca++]=temp%10+'0';
				result[loca]+=temp/10;
			}
		}
		if  (result[loca]=='0') loca--;
		count=0;
		for(i=loca;i>=0;i--)
		{
			dividend[count++]=result[i];
		}
		dividend[count]=0;
		temp=n+1;
		weight=100;
		while(temp/weight==0)
	{
		weight/=10;
	}
		j=0;
	while(weight)
	{
       	divisior[j]=temp/weight+'0';
		temp-=(int)(divisior[j++]-'0')*weight;
		weight/=10;
	}
	divisior[j]=0;
	division(dividend,divisior,t2);
}

void work(int i)
{
	char sign[4];
	int temp=4*i-2;
	int j=0,t=100;
    while(temp/t==0)
	{
		t/=10;
	}
	while(t)
	{
       	sign[j]=temp/t+'0';
		temp-=(int)(sign[j++]-'0')*t;
		t/=10;
	}
	sign[j]=0;
	excute(a[i-1].num,sign,a[i].num,i);
}

int main()
{
    
	int i,n;
	strcpy(a[1].num,"1");
	for(i=2;i<=100;i++)
	{
      work(i);
	}
	while(cin>>n)
	{
		if (n==-1) break;
		cout<<a[n].num<<endl;
	}
	return 0;
}