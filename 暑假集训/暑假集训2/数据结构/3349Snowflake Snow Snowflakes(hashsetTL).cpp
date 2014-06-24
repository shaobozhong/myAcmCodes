#include<iostream>
#include<set>
#include<string>
using namespace std;

struct Sum
{
	set <string> vis; 
	int sum;
};

int atonum(char *num)
{
	int i;
	int res;
	res=0;
	int weight=1;
	for(i=int(strlen(num))-1;i>=0;--i)
	{
		res+=(int(num[i])-48)*weight;
	}
	return res;
}
Sum sum[100000];
int main()
{
	char a[6][20];
	int min1;
	int sum1;
	string str;
	string ch;
	int n,i;
	int loc;
	int pos;
	bool la=false;
	int b[6];
	cin>>n;
		while(!la&&n--)
		{
			
			scanf("%s%s%s%s%s%s",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
			for(i=0;i<6;++i)
			{
				b[i]=atonum(a[i]);
			}
			sum1=b[0]+b[1]+b[2]+b[3]+b[4]+b[5];
			pos=sum1%99991;
			while(sum[pos].vis.size()!=0 && sum[pos].sum!=sum1)
			{
				pos+=1;
				if (pos==100000) pos=0; 
			} 
			min1=b[0];
			loc=0;
			for(i=1;i<6;++i)
			{
				if (min1>b[i]) {min1=b[i];loc=i;}
			}
			str="";
			for(i=1;i<=6;++i)
			{
				str+=a[loc];
				loc+=1;
				if (loc>=6) loc%=6;
				str+=ch;
			}
			if (sum[pos].vis.find(str)!=sum[pos].vis.end()) 
			{
					la=true;
				puts("Twin snowflakes found.");
				break;
			}
			sum[pos].vis.insert(str);
			if (sum[pos].vis.size()==1) {sum[pos].sum=sum1;continue;}
			
			str="";
			for(i=1;i<=6;++i)
			{
				str+=a[loc];
				loc-=1;
				if (loc<0) loc=5;
				str+=ch;
			}

			if (sum[pos].vis.find(str)!=sum[pos].vis.end()) 
			{
				la=true;
				puts("Twin snowflakes found.");
				break;
			}
		}
		 if (!la)puts("No two snowflakes are alike.");
	return 0;
}