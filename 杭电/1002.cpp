#include<iostream>
#include<string>
using namespace std;

int main()
{
	int c,n,alen,blen,i,count,max,k,j,temp;
	char *sum;
	string a,b;
	cin>>n;
	for(k=1;k<=n;k++)
	{
		c=0;
		count=0;
		cin>>a>>b;
		alen=(int)a.size();
		blen=(int)b.size();
		if (alen>blen) max=alen+2; else max=blen+2;
		sum=new char[max];
		for(i=alen-1,j=blen-1;i>=0&&j>=0;i--,j--)
		{
			temp=a[i]-'0'+b[j]-'0'+c;
			c=temp/10;
			sum[count++]=temp%10+'0';
		}
		if (i>=0)
		{		
			for(;i>=0;i--)
			{
				temp=a[i]-'0'+c;
				c=temp/10;
				sum[count++]=temp%10+'0';
			}
		}
		else if (j>=0)
		{
			for(;j>=0;j--)
			{
				temp=b[j]-'0'+c;
				c=temp/10;
				sum[count++]=temp%10+'0';
			}
		}
	
	cout<<"Case "<<k<<":"<<endl;
	cout<<a<<" + "<<b<<" = ";
	if (c)sum[count++]=c+'0';
for(i=count-1;i>=0;i--)
		cout<<sum[i];
if (k==n) cout<<endl;
else 
	cout<<endl<<endl;
	}
	return 0;
}

/*别人的程序
#include<stdio.h>
#include <string.h>
main()
{
 int m,n;
 scanf("%d",&n);
 m=n;
 while( n--)
 {
  int a1,b1,i=0,j;
  char a[1000],b[1000];
     int k[1000]={0};
  scanf("%s %s",a,b);
  a1=strlen(a);
  b1=strlen(b);
  if(a1>=b1)j=a1;
  else
   j=b1;
  while((i<a1)&&(i<b1))
  {
   k[i]=a[a1-i-1]-'0'+b[b1-i-1]-'0';
   i++;
  }
  while(i<a1)
  {
   k[i]=a[a1-i-1]-'0';
   i++;
  }
  while(i<b1)
  {
   k[i]=b[b1-i-1]-'0';
   i++;
  }
  for(i=0;i<=j;i++)
  {
   k[i+1]+=k[i]/10;
   k[i]=k[i]%10;
  }
  printf("Case %d:\n",m-n);
  printf("%s + %s = ",a,b);
  if(k[j]==0) j--;
  for(i=j;i>=0;i--)
  {
   printf("%d",k[i]);
  }
  if(n)
          printf("\n\n");
          else printf("\n");

 }
} */