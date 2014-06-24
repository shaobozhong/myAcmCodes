#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
	int begin,end;
}TV;

bool cmp(const TV &a,const TV &b)
{
	if (a.end==b.end) return a.begin<b.begin;
	return a.end<b.end;
}

int main()
{
	TV *t;
	int n,i,j,program,temp;
	cin>>n;
	
		program=0;
		t=new TV[n+1];
		for(i=0;i<=n-1;i++)
		{
			cin>>t[i].begin>>t[i].end;
			if(t[i].begin>t[i].end) 
			{
				temp=t[i].begin;
				t[i].begin=t[i].end;
				t[i].end=temp;
			}
		}
        sort(t,t+n,cmp);
        for(i=0;i<=n-1;i++)
         {
			 if (t[i].end!=-1)
			 {
				 program++;
				 for(j=i+1;j<=n-1;j++)
				 {
					 if (t[j].begin<=t[i].end) { t[j].end=-1;}
					 else 
					 {
						 i=j-1;
						 break;
					 }
				 }
				 i=j-1;
			 }
         }
     cout<<n-program<<endl;
	
	return 0;
}