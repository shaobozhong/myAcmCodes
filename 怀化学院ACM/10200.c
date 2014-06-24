#include<stdio.h>
#include<string.h>
int main()
{char a[1000000]={0};

int s,i;
int t;
while(scanf("%s",a)>0&&a[0]!='0')
{s=0;
for(i=0;i<=(int)strlen(a)-1;i++)
			s+=(int)a[i]-48;

		while(s>=10)
		{
		t=s;
		s=0;
		while(t!=0)
		{
			s+=t%10;
			t/=10;
		}
		}
printf("%d\n",s);
}
return 0;
}


