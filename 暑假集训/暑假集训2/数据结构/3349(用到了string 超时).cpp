#include<iostream>
#include<set>
#include<string>
using namespace std;

struct node 
{
	string str;
	struct node *next;
};

struct Sum
{
	node head;
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
	string str[12];
	string ch;
	int n,i,j;
	int loc;
	int pos;
	bool la=false;
	int b[6];
	node *p,*q,*qq;

	for(i=0;i<100000;++i)
	{
		sum[i].head.next=NULL;
	}

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
		while(sum[pos].head.next!=NULL && sum[pos].sum!=sum1)
		{
			pos+=1;
			if (pos==100000) pos=0; 
		} 
		min1=b[0];
		int count1=0;
		for(j=0;j<6;++j)
		{
			loc=j;
			str[count1]="";
			for(i=1;i<=6;++i)
			{
				str[count1]+=a[loc];
				loc+=1;
				if (loc==6) loc=0;
			}
			if (str[count1]<str[0]) 
			{
				swap(str[0],str[count1]);
			}
			count1++;
		}
		for(j=0;j<6;++j)
		{
			loc=j;
			str[count1]="";
			for(i=1;i<=6;++i)
			{
				str[count1]+=a[loc];
				loc-=1;
				if (loc<0) loc=5;
			}
			if (str[count1]<str[0]) 
			{
				swap(str[0],str[count1]);
			}
			count1++;
		}


		if (sum[pos].head.next==NULL)
		{
			sum[pos].sum=sum1;
			q=new node;
			q->str=str[0];
			q->next=NULL;
			sum[pos].head.next=q;
			continue;
		}


		p=&sum[pos].head;
		while(!la&&p->next&&(p->next->str<=str[0]))
		{
			for(j=0;!la&&j<6;++j)
			{  
				if (p->next->str==str[0])
				{
					la=true; 
					break;
				}
			}
			p=p->next;
		}
		if (la) {break;}
		qq=new node;
		q->str=str[0];
		q->next=NULL;
		p->next=q;


	}
	if (!la) puts("No two snowflakes are alike.");
	else puts("Twin snowflakes found.");
	return 0;
}