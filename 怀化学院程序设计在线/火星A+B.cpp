#include<iostream>
#include<string>
using namespace std;

int dic[26]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
	int i,j;
	int a[25];
	int b[25];
	int c[30];
	int num,add1;
    string str;
	while(1)
	{
		cin>>str;
		num=0;
		int count1=0;
		for(i=0;i<int(str.length());++i)
		{
			if (str[i]>='0' && str[i]<='9')
			{
				num=num*10+int(str[i])-48;
			}
			if (str[i+1]==',' || i==int(str.length())-1) 
			{
				a[++count1]=num;
				num=0;
			}
		}
		a[0]=count1;

		
        count1=0;
        cin>>str;
		for(i=0;i<int(str.length());++i)
		{
			if (str[i]>='0' && str[i]<='9')
			{
				num=num*10+int(str[i])-48;
			}
			if (str[i+1]==',' || i==int(str.length())-1) 
			{
				b[++count1]=num;
				num=0;
			}
		}
		b[0]=count1;

		if (a[0]==1 && b[0]==1 && a[1]==0 && b[1]==0) break;
		count1=0;
		add1=0;
		for(i=a[0],j=b[0];i>=1&&j>=1;--i,--j)
		{
			num=a[i]+b[j]+add1;
			add1=num/dic[count1+1];
			c[++count1]=num%dic[count1];
		}
		while(i>=1)
		{
			num=a[i]+add1;
			add1=num/dic[count1+1];
			c[++count1]=num%dic[count1];
			--i;
		}
		while(j>=1)
		{
			num=b[j]+add1;
			add1=num/dic[count1+1];
			c[++count1]=num%dic[count1];
			--j;
		}
		if (add1>0) c[++count1]=add1;
		c[0]=count1;

		for(i=c[0];i>1;--i)
		{
			printf("%d,",c[i]);
		}
		printf("%d\n",c[i]);
	}
	return 0;
}