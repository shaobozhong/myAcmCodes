#include <stdio.h>
#include <string.h>
void fun(char* s,int n)
{
    char* p=s;
    int temp,jinwei;
    for(*p=n+'0', jinwei=0;!(*p=='0'&&jinwei==1);p++)
        ((temp = (*p-'0')*n+jinwei)>9)?(*(p+1)=temp%10+'0',jinwei=temp/10):(*(p+1)=temp+'0',jinwei=0);
    *++p='1',*++p='\0';
    _strrev(s);
}
int main()
{
 int i;
    char s[200];
 printf("0\n1\n");
    for ( i = 2; i <= 9; i++)
    {
        fun(s,i);
        printf("%s\n",s);
    }
    return 0;
}
