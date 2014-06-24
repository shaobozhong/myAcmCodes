#include<iostream>
using namespace std;

typedef struct 
{
	int data;
	bool la;
}elem;

int main()
{
	int t,m,key,i,j,loca,tar,temp;
	elem *num;
	cin>>t;
	while(t--)
	{
		cin>>m;
		num=new elem[m];
		for(i=0;i<m;i++)
		{
			num[i].la=true;
		}
		for(i=1;i<=m;i++)
		{
			cin>>key;
			loca=key%m;
			temp=loca;
			if ((loca>=m||loca<0)||!num[loca].la)
			{
				for(j=0;j<=m-1;j++)
				{
                    loca=(temp+j)%m;
					if (num[loca].la) break;
				}
			}
			num[loca].data=key;
			num[loca].la=false;
		}
		for(i=0;i<m;i++)
		{
			cout<<num[i].data<<" ";
		}
		if (m>0) cout<<endl;
		cin>>tar;
		for(i=0;i<m;i++)
		{
			if (num[i].data==tar) break;
		}
		if (i<m) cout<<i<<endl;
		else cout<<"not this element"<<endl;
	}
	return 0;
}