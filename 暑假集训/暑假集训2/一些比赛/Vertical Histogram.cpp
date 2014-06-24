#include<iostream>
#include<string>
using namespace std;


int main()
{
	//freopen("2.txt","w",stdout);
	int times[26],i,j,k,max1,temp,t;
	max1=0;
	string str;
	for(i=0;i<26;++i)
	{
		times[i]=0;
	}
	t=4;
	while(getline(cin,str))
	{
		t--;
		for(i=0;i<int(str.size());++i)
		{
			if (str[i]>='A' && str[i]<='Z') 
			{
				temp=++times[int(str[i])-65];
				if (max1<temp)
				{
					max1=temp;
				}
			}
		}
		if (t==0)
		{
			t=4;
			for(i=1;i<=max1;++i)
			{
				for(j=0;j<26;++j)
				{
					for(k=j;k<26;++k)
					{
						if (max1-i<times[k]) break;
					}
					if (k>=26) {cout<<endl;break;}
					if (j!=0) putchar(' ');
					if (max1-i<times[j]) {putchar('*');}
					else putchar(' ');
				}
				if (j>=26) cout<<endl;
			}

			for(i=0;i<26;++i)
			{
				if (i!=0) putchar(' ');
				putchar(i+'A');
				
			}
			cout<<endl;
		}
	}
	return 0;
}