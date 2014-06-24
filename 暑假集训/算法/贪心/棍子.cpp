#include<iostream>
using namespace std;

typedef struct node 
{
	int weight;
	int length;
	bool la;
}sticks;

void sort(sticks *s,int ns)
{
	int i,j,temp;
	for(i=0;i<=ns-2;i++)
	{
		for(j=0;j<=ns-i-2;j++)
		{
			if (s[j].length>s[j+1].length)
			{
				temp=s[j].length;
				s[j].length=s[j+1].length;
				s[j+1].length=temp;

				temp=s[j].weight;
				s[j].weight=s[j+1].weight;
				s[j+1].weight=temp;

			}
			
			
				if (s[j].length==s[j+1].length&&s[j].weight>s[j+1].weight)
				{
					temp=s[j].weight;
					s[j].weight=s[j+1].weight;
					s[j+1].weight=temp;
             }

			
		}
	}
}

void work(sticks *s,int ns)
{
	int i,j,total=0,temp;
	for(i=0;i<=ns-1;i++)
	{
		if (s[i].la)
		{
			total++;
			s[i].la=false;
			temp=s[i].weight;
			for(j=i+1;j<=ns-1;j++)
			{
				if (s[j].la&&s[j].weight>=temp)
				{
					s[j].la=false;
					temp=s[j].weight;
				}
			}
		}
	}
	cout<<total<<endl;
}

int main()
{

	int n,ns,i;
	sticks s[5005];
	cin>>n;
	for(;n>=1;n--)
	{
		cin>>ns;
		for(i=0;i<=ns-1;i++)
		{
			cin>>s[i].length>>s[i].weight;
			s[i].la=true;
		}
		sort(s,ns);
		work(s,ns);
	}
	return 0;
}