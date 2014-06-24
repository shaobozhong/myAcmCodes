#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int slen,tlen,loca,i,j,temp,count,k;
	char s[105],t[105];
	int result[10005],n;
	cin>>n;
for(k=1;k<=n;k++)
	{
	    cin>>s>>t;
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
		while(result[loca]==0&&loca!=0) loca--; 
		cout<<"Case "<<k<<":"<<endl<<s<<" * "<<t<<" = ";
		for(i=loca;i>=0;i--)
			cout<<result[i];
		cout<<endl;
		if (k!=n) cout<<endl;
	}
	return 0;
}