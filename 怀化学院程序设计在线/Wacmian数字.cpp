#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int i,sum,len;
    char  str[1000];
	while(cin>>str,strcmp(str,"#")!=0)
	{
		sum=0;
		len=(int)strlen(str);
		for(i=0;i<len;++i)
		{
			switch(str[len-i-1])
			{
			case '%':break;
			case ')': sum+=(int)pow(6.0,i);break;
			case '~': sum+=(int)2*pow(6.0,i); break;
			case '@':  sum+=(int)3*pow(6.0,i); break;
			case '?':  sum+=(int)4*pow(6.0,i);break;
            case 92:  sum+=(int)5*pow(6.0,i);break;
			case '$':  sum-=(int)pow(6.0,i);
			}
		
		}
		cout<<sum<<endl;
	}
	return 0;
}