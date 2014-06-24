#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
	bool pend;
	int sum,num,i;
	pend=false;
	while(getline(cin,str))
	{
		sum=0;
		for(i=1;i<=(int)str.size();i++)
		{
			if (str[i-1]=='#') {if (sum==0) return 0;pend=true;break;}
			if (str[i-1]==' ') {num=0;}
			else num=str[i-1]-64;
			sum+=num*i;
		}
		cout<<sum<<endl;
		if (pend) break;
		
	}
	return 0;
}