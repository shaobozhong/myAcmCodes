#include<iostream>
using namespace std;
int main()
{
	int m;
	while(cin>>m)
	{
		char str[100];
                int j,i=0;
		if(m==0)
		{
			cout<<0<<endl;
			continue;
		}
		while(m)
		{
			if(m>0)
			{
				switch(m%3)
				{
				case 0:m=m/3;str[i++]='0';break;
				case 1:m=m/3;str[i++]='1';break;
				default:m=m/3+1;str[i++]='-';break;//若是2 此处为-1 往前进一位
				}
			}
			else
			{
				switch(-m%3)
				{
				case 0:m=m/3;str[i++]='0';break;//0=-0
				case 1:m=m/3;str[i++]='-';break;//-1 不变
				default:m=m/3-1;str[i++]='1';break;
//-2 =1-3 所以往前进一位
				}
			}
		}
		for(j=i-1;j>=0;j--)
			cout<<str[j];
		cout<<endl;
	}
	return 0;
}