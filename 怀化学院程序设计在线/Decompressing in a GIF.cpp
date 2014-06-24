#include<iostream>
#include<string>
using namespace std;

	int a[5000];
	string dic[1050];
int main()
{
	string tag,tmp;

	int n,i,j,count1,count2,count3,num;
	int casenum;
	casenum=0;
	string res;
	//freopen("1.out","w",stdout);
	while(cin>>tag,tag!="0")
	{
		res="";
		++casenum;
		cin>>n;
		for(i=0;i<n;++i)
		{
			cin>>dic[i];
		}

		count2=n;
		count1=0;
		num=n;
		count3=1;

		for(i=0;i<int(tag.size());++i)
		{
			a[count1++]=int(tag[i]-'0');
		}
		
       
		for(i=0;i<count1;i+=count3)
		{
			
			num=count2-1;
			count3=0;
			while(num)
			{
				++count3;
				num/=10;
			}
			if (count3==0) count3=1;
			for(j=1;j<count3;++j)
			{
				a[i]=a[i]*10+a[i+j];
			}
			if (i>0) dic[count2-1]+=dic[a[i]][0];
			dic[count2++]=dic[a[i]];
			res+=dic[a[i]];
		}
		 cout<<"Case "<<casenum<<": "<<res<<endl;
	}
	return 0;
}