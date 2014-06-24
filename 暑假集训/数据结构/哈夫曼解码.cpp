#include<iostream>
using namespace std;

typedef struct
{
	char sig;
	char coding[20];
}element;

int pipei(element *elem,char *article,int i,int n)
{
	int j,k,p,len;
	for(k=1;k<=n;k++)
	{
		len=(int)strlen(elem[k].coding);
		p=i;
		for(j=0;j<=len-1;j++)
		{
           if (article[p++]!=elem[k].coding[j]) break;
		}
		if (j==len) break;
	}
	if (j==len)
	{
		cout<<elem[k].sig;
		return i+len-1;
	}
	return i;
}

void decode(element *elem,int n)
{
	int i,loc;
	char article[100];
	int m;
	cin>>m;
	getchar();
	for(;m>=1;m--)
	{
	gets(article);
	for(i=0;i<=(int)strlen(article)-1;i++)
	{
		i=pipei(elem,article,i,n);
	}
	cout<<endl;
	}
}

int main()
{
	element *elem;
	char temp;
	int n,i,count;
while(scanf("%d",&n)+1)
{
	elem=new element[n+1];
	getchar();
	for(i=1;i<=n;i++)
	{
		count=0;
		cin>>elem[i].sig;
		getchar();
		getchar();
        while(temp=getchar(),temp!='\n')
		{
			elem[i].coding[count++]=temp;
		}
		elem[i].coding[count]='\0';
	}
	//for(i=1;i<=n;i++)
		//cout<<elem[i].coding<<endl;//Êä³ö¸ö×Ö·ûµÄ±àÂë
	decode(elem,n);
}
	return 0;
}