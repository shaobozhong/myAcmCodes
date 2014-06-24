#include<iostream>
#include<string>
using namespace std;

char arrayOfLetter[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


	
int valueOfLetter(char ch,int n)
{
	for(int i=0;i<n;++i)
	{
		if(ch==arrayOfLetter[i]) return i;
	}
	return -1;
}

int main()
{
	string str1;
	string str2;
	string res="";
	int c;//进位
	int current;//当前值
	int n;
	cin>>n;
	cin>>str1>>str2;
	int i=str1.size()-1;
	int j=str2.size()-1;
	c=0;
	bool la=true;
	int num;
	while(i>=0||j>=0)
	{
		if (n > 35 || n < 2){
			la=false;
			break;
		}
		current=0;
		current+=c;
		if(i>=0)
		{
			num=valueOfLetter(str1[i--],n);
			if(num==-1) 
			{
				la=false;
				break;
			}
			current+=num;
		}
		if(j>=0){
			num=valueOfLetter(str2[j--],n);
			if(num==-1) 
			{
				la=false;
				break;
			}
			current+=num;
		}
		res.insert(res.begin(),arrayOfLetter[(current%n)]);
		c=current/n;
	}
	if(!la)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		if(c!=0)
		{
		res.insert(res.begin(),arrayOfLetter[c]);
		}
		while(res.size()>1&&res[0]=='0')
		{
			res.erase(0,1);
		}
		cout<<res<<endl;
	}
	
	return 0;
}

