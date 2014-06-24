#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int slen,tlen,loca,i,j,temp,count;
	char s[105],t[105];
	int result[10005];
	while(cin>>s>>t)
	{
	
		memset(result,0,sizeof(result));
		slen=(int)strlen(s);
		tlen=(int)strlen(t);
		count=0;
		for(i=tlen-1;i>=0;i--)
		{
			loca=count++;
			for(j=slen-1;j>=0;j--)
			{
				temp=(s[j]-'0')*(t[i]-'0');
				temp+=result[loca];
                result[loca++]=temp%10;
				result[loca]+=temp/10;
			}
		}
		if  (result[loca]==0) loca--; 
		for(i=loca;i>=0;i--)
			cout<<result[i];
		cout<<endl;
	}
	return 0;
}