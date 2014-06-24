#include<iostream>
using namespace std;

int num(char *s,int *i,int len)
{
	int number=0;
	int j=*i,k,t=1;
	for(;s[(*i)+1]!=' '&&s[(*i)+1]!=':'&&*i<=len-2;(*i)++)
	{}
		for(k=*i;k>=j;k--)
		{
			number+=((int)s[k]-48)*t;
			t*=10;
		}
		(*i)++;
		return number;
}
int main()
{
	double distance=0;
	double speed=0;
	int k,time=0,ntime,t,i,otime=0;
	char s[100];
	int len;
	while(gets(s))
	{
		len=(int)strlen(s);
		for(i=0;i<=len-1;i++)
			if (s[i]==' ') break;
		if (i<len)
		{
			ntime=0;
			t=3600;
			for(i=0;s[i-1]!=' ';i++)
			{
				ntime+=num(s,&i,len)*t;
				t/=60;
			}
			time=ntime-otime;
			otime=ntime;
			distance+=speed*time/3600;
			t=1;
			speed=0;
			k=i;
			for(i=len-1;i>=k;i--)
			{
				speed+=((int)s[i]-48)*t;
				t*=10;
			}
		}
		else 
		{
			ntime=0;t=3600;
			for(i=0;i<=len-1;i++)
				cout<<s[i];
			for(i=0;s[i-1]!=' '&&i<=len-1;i++)
			{
				ntime+=num(s,&i,len)*t;
				t/=60;
			}
			time=ntime-otime;
			otime=ntime;
			distance+=speed*time/3600;
			printf(" %.2f",distance);
			cout<<" km"<<endl;
		}
	}
	return 0;
}