#include<iostream>
using namespace std;
#define M 100

typedef struct
{
 int i[M],j[M],e[M];
}Node;


int main()
{
	Node s,t;
	int n,m,x,i,j;
	int num[M]={0},copt[M]={1};
	cin>>n>>m;
    s.i[0]=n;s.j[0]=m;s.e[0]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			cin>>x;
			if (x!=0)
			{
				s.i[s.e[0]]=i;
				s.j[s.e[0]]=j;
				s.e[s.e[0]++]=x;
			}
		}
		
		/*cout<<s.i[0]<<" "<<s.j[0]<<" "<<s.e[0]-1<<endl;
		for(i=1;i<=s.e[0]-1;i++)
			cout<<s.i[i]<<" "<<s.j[i]<<" "<<s.e[i]<<endl;
			cout<<endl;*/
        t.i[0]=s.j[0];
		t.j[0]=s.i[0];
		t.e[0]=s.e[0];

		cout<<t.i[0]<<" "<<t.j[0]<<" "<<t.e[0]-1<<endl;
		for(i=1;i<=s.e[0]-1;i++)
		{
			num[s.j[i]]++;
		}
		for(i=1;i<=s.j[0];i++)
		{
			copt[i]=copt[i-1]+num[i-1];
		}
		for(i=1;i<=s.e[0]-1;i++)
		{
			t.i[copt[s.j[i]]]=s.j[i];
			t.j[copt[s.j[i]]]=s.i[i];
            t.e[copt[s.j[i]]++]=s.e[i];
		}
		for(i=1;i<=t.e[0]-1;i++)
			cout<<t.i[i]<<" "<<t.j[i]<<" "<<t.e[i]<<endl;
		 

	return 0;
}