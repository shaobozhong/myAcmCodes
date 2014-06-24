#include<iostream>
#include<algorithm>
using namespace std;

typedef struct
{
	int begin,end;
}TV;

bool cmp(const TV &a,const TV &b)
{
	return a.end<b.end;
}

int main()
{
	TV *t;
	int n,i,j,program;
	while(cin>>n,n!=0)
	{
		program=0;
		t=new TV[n+1];
		for(i=0;i<=n-1;i++)
		{
			cin>>t[i].begin>>t[i].end;
		}
       sort(t,t+n,cmp);
        for(i=0;i<=n-1;i++)
         {
			 if (t[i].end!=-1)
			 {
				 program++;
				 for(j=i+1;j<=n-1;j++)
				 {
					 if (t[j].begin<t[i].end) t[j].end=-1;
					 else 
					 {
						 i=j-1;
						 break;
					 }
				 }
			 }
         }
     cout<<program<<endl;
	}
	return 0;
}