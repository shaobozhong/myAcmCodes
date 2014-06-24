#include<iostream>
#include<string>
using namespace std;


int main()
{
	int i;
	int num;
	string str;
	int count1;
	count1=0;
	for(i=1;i<=1000;++i)
	{
		if (i%13==0)
		{
			str="";
			num=i;
			while(num)
			{
				str.insert(str.begin(),num%10+'0');
				num/=10;
			}
			if (str.find("13")==-1) continue;
			cout<<i<<endl;
			count1++;
		}
	}
	printf("%d\n",count1);
	return 0;
}