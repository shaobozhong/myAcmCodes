/****** Big Number Multiplication *********************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10000
/******************************************************************/
void reverse(char *from, char *to )
{
        int len=strlen(from);
        int i;
        for(i=0;i<len;i++)
                to[i]=from[len-i-1];
        to[len]='\0';
}
/******************************************************************/
void call_mult(char *first,char *sec,char *result)
{
        char F[MAX],S[MAX],temp[MAX];
        int f_len,s_len,f,s,r,t_len,hold,res;
        f_len=strlen(first);
        s_len=strlen(sec);
        reverse(first,F);
        reverse(sec,S);

        t_len=f_len+s_len;
        r=-1;
        for(f=0;f<=t_len;f++)
                temp[f]='0';
        temp[f]='\0';
        for(s=0;s<s_len;s++)
		{
                hold=0;
                for(f=0;f<f_len;f++)
				{
                        res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
                        temp[f+s]=res%10+'0';
                        hold=res/10;
                        if(f+s>r) r=f+s;
                }
                while(hold!=0)
				{
                        res=hold+temp[f+s]-'0';
                        hold=res/10;
                        temp[f+s]=res%10+'0';
                        if(r<f+s) r=f+s;
                        f++;
                }
        }
        for(;r>0 && temp[r]=='0';r--);
        temp[r+1]='\0';
        reverse(temp,result);
}
/***************************************************************/

void call_sum(char *first, char *sec, char *result){
        char F[MAX], S[MAX], Res[MAX];
        int f,s,sum,extra,now;
        f=strlen(first);
        s=strlen(sec);
        reverse(first,F);
        reverse(sec,S);
        for(now=0,extra=0;(now<f && now<s);now++){
                sum=(F[now]-'0') + (S[now]-'0') + extra;
                Res[now]=sum%10 +'0';
                extra= sum/10;
        }
        for(;now<f;now++){
                sum=F[now] + extra-'0';
                Res[now]=sum%10 +'0';
                extra=sum/10;
        }
        for(;now<s;now++){
                sum=F[now] + extra-'0';
                Res[now]=sum%10 +'0';
                extra=sum/10;
        }
        if(extra!=0) Res[now++]=extra+'0';
        Res[now]='\0';
        if(strlen(Res)==0) strcpy(Res,"0");
        reverse(Res,result);
		}

char*  calc(char *p)
{
	char temp1[MAX];
	char temp[MAX];
	char res[MAX]="3";
	call_mult(res,p,res);
	call_mult(p,p,temp);
	if (int(strlen(temp))>int(strlen(res)))
	{
	     call_sum(temp,res,res);
	}
	else 
	{
			call_sum(res,temp,res);
	}

	call_mult(temp,p,temp);
	if (int(strlen(temp))>int(strlen(res)))
	{
	     call_sum(temp,res,res);
	}
	else 
	{
			call_sum(res,temp,res);
	}
	return res;
}

bool panduan(char *a,char *b)
{
	int i;
	if (int(strlen(a))>int(strlen(b))) return true;
	else if (int(strlen(a))<int(strlen(b))) return false;
	for(i=0;i<int(strlen(a));++i)
	{
		if (a[i]>b[i]) return true;
		else if (a[i]<b[i]) return false;
	}
	return false;
}

int main()
{ 
	char ch;
	int len,i;
    char num[MAX],p[MAX];
	while(scanf("%s",num)!=EOF)
	{
		len=int(strlen(num));
		for(i=0;i<len;++i)
		{
			p[i]='0';
		}
		p[len]='\0';

		for(i=0;i<len;++i)
		{
			ch='0';
			while(1)
			{
				p[i]=ch;
				if (panduan(calc(p),num)) break;
				ch++;
			}
			p[i]--;
		}

		for(i=0;i<len;++i)
		{
			if (p[i]!='0') break;
		}
		if (i>=len) {puts("0");continue;}
		for(;i<len;++i)
		{
			putchar(p[i]);
		}
		putchar('\n');
	}
	return 0;
}