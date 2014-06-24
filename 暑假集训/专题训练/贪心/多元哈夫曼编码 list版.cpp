#include<iostream>
#include<list>
using namespace std;

int main()
{
	int n,k,num,i,min=0,max=0,rest,temp;
	list<int> l;
	list<int>::iterator j;
	list<int>::reverse_iterator p;
	//freopen("input.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		l.push_back(num);
	}
	l.sort();
	p=l.rbegin();
	temp=*p;
	p++;
	while(p!=l.rend())
	{
		temp+=*p;
	    max+=temp;	
		p++;
	}
    num=0;
	rest=n%(k-1);
    if (rest!=1)
	{
		
	
		while(rest--)
		{	
			j=l.begin();
			num+=*j;
			l.pop_front();
		}
		j=l.begin();
		while(j!=l.end()&&*j<=num)
		{
			j++;
		}
		l.insert(j,num);
		min+=num;
	}
	while(l.size()>1)
	{
		num=0;
		temp=k;
		while(temp--)
		{
        j=l.begin();
		num+=*j;
		l.pop_front();
		}
		j=l.begin();
		while(j!=l.end()&&*j<=num)
		{
			j++;
		}
		l.insert(j,num);
		min+=num;
	}
	printf("%d %d\n",max,min);
	
	return 0;
}