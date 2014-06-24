#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000




void reverse(char *from, char *to ){
        int len=(int)strlen(from);
        int l;
        for(l=0;l<len;l++)
                to[l]=from[len-l-1];
        to[len]='\0';
}


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
                sum=S[now] + extra-'0';
                Res[now]=sum%10 +'0';
                extra=sum/10;
        }
        if(extra!=0) Res[now++]=extra+'0';
        Res[now]='\0';
        if(strlen(Res)==0) strcpy(Res,"0");
        reverse(Res,result);
		}


int main(){
        char num[100][100];
		char res[100];
		int i,len;
        while(scanf("%s%s%s",num[0],num[1],num[2])!=EOF){
			    for(i=3;i<=99;++i)
				{
                  call_sum(num[i-3],num[i-2],res);
                  call_sum(num[i-1],res,num[i]);
				}
                len=(int)strlen(num[99]);
                for(i=0;i<len;i++) printf("%c",num[99][i]);
                printf("\n");
        }
        return 0;
}

