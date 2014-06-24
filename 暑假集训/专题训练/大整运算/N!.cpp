#include<iostream>
#include<string>
using namespace std;
int result1[1000000];
void multiplication(string &multiplicand,int multiplicator,string &result)
{
	
	int i,j,count=0,add;
	    memset(result1,0,sizeof(result));
		for(i=multiplicand.size()-1;i>=0;i-=3)
		{
			if (i>=2) result1[count]=((multiplicand[i]-'0')+(multiplicand[i-1]-'0')*10+(multiplicand[i-2]-'0')*100)*multiplicator;
			else if (i==1) result1[count]=((multiplicand[i]-'0')+(multiplicand[i-1]-'0')*10)*multiplicator;
			else result1[count]=(multiplicand[i]-'0')*multiplicator;
			count+=3;
		}
		add=result1[0]/10;
		result1[0]%=10;
		i=1;
		while(add||i<=count)
		{
			result1[i]+=add;
			add=result1[i]/10;
		    result1[i++]%=10;
		}
		for(j=i-1;j>=0;j--)
			if (result1[j]!=0) break;
		for(;j>=0;j--)
			result.push_back(result1[j]+'0');
}

int main()
{
	string number[10001];
	int n,count;
	string sign;
	number[1]="1";
	count=2;
	while(cin>>n)
	{
		if (number[n].size()>0) cout<<number[n]<<endl;
		else 
		{
			
			for(;count<=n;count++)
			{
				
				multiplication(number[count-1],count,number[count]);
			}
			cout<<number[n]<<endl;
		}
	}
	return 0;
}