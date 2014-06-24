#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Near
{
	int degree;
	char data;
	struct Near *next;
};

int num,m,n;

Near *G;
string exch;
string sttr;

void cmpchar(const string &a,const string &b,char &big,char &small)
{
	for(int i=0;i<int(a.size())&&i<int(b.size());++i)
	{
		if (a[i]!=b[i]) {small=a[i];big=b[i];return;}
	}
}


int searchchar(char ch)
{
	for(int i=0;i<num;++i)
	{
		if (G[i].data==ch) return i;
	}
	return 0;
}





bool cmp(char a,char b)
{
	return a<b;
}

void tuopu()
{
	string result;
	Near *p;
	int i,temp,total,j;
	bool la;
	la=true;
	if (num!=m) {puts("0");return;}
	while(la)
	{
		la=false;
		total=0;
		for(i=0;i<num;++i)
		{
			if (G[i].degree==0) {temp=i;total++;}
		}
		if (total!=1) break;
		la=true;
		i=temp;
		G[temp].degree=-1;
		result.push_back(G[temp].data);
		p=G[temp].next;
		while(p)
		{
			G[p->degree].degree-=1;
			p=p->next;
		}
	}
	if (int(result.size())<m) {puts("0");return;}
	sort(exch.begin(),exch.end(),cmp);
	for(i=0;i<int(sttr.size());++i)
	{
		for(j=0;j<int(result.size());++j)
		{
			if(result[j]==sttr[i]) {cout<<exch[j];break;}
		}
	}
  cout<<endl;
}

int main()
{

	char big=0,small=0;
    string s[100];
	int bignum,smallnum,i,j;
	
cin>>m>>n;
	for ( i=0;i<n;++i)
	{
		cin>>s[i];
	}
	cin>>sttr;
	num=0;
	G=new Near[m+1];
	for( i=0;i<n;++i)
	{
		G[i].next=NULL;
		G[i].data=0;
		G[i].degree=0;
	}
	for(i=0;i<n-1;++i)
	{
		big=0;small=0;
		cmpchar(s[i],s[i+1],big,small);

		if(big==0|| small==0) continue;


		for(j=0;j<num;++j)
		{
			if (G[j].data==small) break;
		}
		if (j>=num) { G[num++].data=small;exch.push_back(small);}
		if (num==m+1) break;
		for( j=0;j<num;++j)
		{
			if (G[j].data==big) break;
		}
		if (j>=num)  {G[num++].data=big;exch.push_back(big);}
		if (num==m+1) break;

		bignum=searchchar(big);
		smallnum=searchchar(small);


		Near *q=new Near;
		q->degree=bignum;
		q->next=G[smallnum].next;
		G[smallnum].next=q;
		G[bignum].degree++;
		
	}
    tuopu();
	return 0;
}