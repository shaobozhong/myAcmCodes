#include<stdio.h>
#include<string.h>

int main()
{
	int x,y,i,j,temp,len,count,number,b;
	char hnum[33];
	char bnum[33];
	memset(bnum,'0',sizeof(bnum));
	bnum[32]='\0';
	scanf("%x,%d,%d",&number,&x,&y);
	itoa(number,hnum,16);
	len=strlen(hnum);
	count=0;
	for(i=len-1;i>=0;i--)
	{
		if (hnum[i]>'9') 
		{
			switch(hnum[i])
			{
			case 'a':temp=10;break;
			case 'b':temp=11;break;
			case 'c':temp=12;break;
			case 'd':temp=13;break;
			case 'e':temp=14;break;
			case 'f':temp=15;
			}
		}
		else 
			temp=hnum[i]-48;
		j=31-4*count;
		while(temp)
		{
			bnum[j--]=temp%2+'0';
			temp/=2;
		}
		count++;
	}
	count=0;
	for(i=31;i>=0;i--)
	{
		if (count==x) bnum[i]='0';
		if (count==y) 
		{
			bnum[i]='1';
			bnum[i+1]='1';
			bnum[i+2]='0';
		}
		count++;
	}

	count=0;
	for(i=0;i<32;i+=4)
	{
		temp=0;b=1;
		for(j=i+3;j>=i;j--)
		{
			temp+=(bnum[j]-48)*b;
			b*=2;
		}
		if (temp<10) hnum[count++]=temp+'0';
		else 
		{
			switch(temp)
			{
			case 10:hnum[count++]='a';break;
			case 11:hnum[count++]='b';break;
			case 12:hnum[count++]='c';break;
			case 13:hnum[count++]='d';break;
			case 14:hnum[count++]='e';break;
			case 15:hnum[count++]='f';
			}
		}
	}
	for(i=0;i<8;i++)
	{
		if (hnum[i]!='0') break;
	}
	for(;i<8;i++)
	{
		putchar(hnum[i]);
	}
	putchar('\n');
	return 0;
}