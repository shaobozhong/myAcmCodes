#include<iostream>
#include<string>
using namespace std;

int main()
{
	int size,i,count,total,len;
	string s;
	double test=0;
	total=0;
	count=0;
	while(getline(cin,s))
	{
		test+=0.5;
		count=0;
		len=s.size();
		for(i=0;i<=len-1;i++)
		{
			if (s[i]=='c'||s[i]=='w') break;
		}
		if (s[i]=='c') size=1;
		else size=2;
		for(i=0;i<=len-1;i++)
		{
            if (s[i]==',') count++;
		}
        total+=(count+1)*size;
		if ((int)test/1==test) 
		{
			cout<<"#program "<<test<<": "<<total<<endl;
			total=0;
			getline(cin,s);
		}
	}
}
