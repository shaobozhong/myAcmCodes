#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[105],t[105]="0",t1[105];
	int  c,i,j,count,slen,tlen,temp;
	while(gets(s))
	{
		if (strcmp(s,"0")==0) break;
		c=0;
		count=0;
		slen=(int)strlen(s);
		tlen=(int)strlen(t);
		for(i=slen-1,j=tlen-1;i>=0&&j>=0;i--,j--)
		{
			temp=(s[i]-'0')+(t[j]-'0')+c;
			t1[count++]=temp%10+'0';
			c=(temp/10);
		}
		if (i>=0) 
		{
			for(;i>=0;i--)
			{
				temp=s[i]-'0'+c;
			t1[count++]=temp%10+'0';
			c=(temp/10);
			}
		}
		if (j>=0)
		{
			for(;j>=0;j--)
			{
			temp=t[j]-'0'+c;
			t1[count++]=temp%10+'0';
			c=temp/10;
			}
		}
		if (c>0)
			t1[count++]=c+'0';
		for(i=count-1,j=0;i>=0;i--,j++)
          t[j]=t1[i];
		t[count]='\0';
	}
	cout<<t<<endl;
	return 0;
}