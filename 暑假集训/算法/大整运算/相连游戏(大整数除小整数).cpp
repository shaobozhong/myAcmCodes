#include<iostream>
#include<cstring>
using namespace std;
typedef struct 
{
	char num[210];
}elem;
	elem a[101];
	int result[210];


void excute(char  *s,char *t,char *t2,int n)
{
	int sum,slen,tlen,count,loca,temp,i,j;
        memset(result,0,sizeof(result));
		slen=(int)strlen(s);
		tlen=(int)strlen(t);
		count=0;
		for(i=tlen-1;i>=0;i--)
		{
			loca=count++;
			for(j=slen-1;j>=0;j--)
			{
				temp=(s[j]-'0')*(t[i]-'0');
				temp+=result[loca];
                result[loca++]=temp%10;
				result[loca]+=temp/10;
			}
		}
		if  (result[loca]==0) loca--;
		sum=0;
		count=0;
		temp=n+1;
		while(sum<temp)
		{
			sum+=result[loca];
			if (sum>=temp) {sum-=result[loca];break;}
			loca--;
			sum*=10;
		}
		for(i=loca;i>=0;i--)
		{
			sum+=result[i];
			if(sum>=temp) 
			{
				t2[count++]=(sum/temp)+'0';
				sum%=temp;
			}
			else t2[count++]='0';
			sum*=10;
		}
		t2[count]=0;
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