#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	string na;
	int g,a,c;
}medal;
int main()
{
	bool result;
	medal m[202];
	medal temp;
	int c,i,j,k,l,cscore,score;
	while(scanf("%d",&c)>0&&c)
	{
		result=true;
		for(i=1;i<=c;++i)
		{
			cin>>m[i].na;
			scanf("%d%d%d",&m[i].g,&m[i].a,&m[i].c);
			if (m[i].na=="Canada") 
			{
				m[0]=m[i];
				i--;
				c--;
			}
		}
       
		for(i=0;i<=2&&result;++i)
		{
			for(j=0;j<=2&&result;++j)
			{
				for(k=0;k<=2&&result;++k)
				{
					//if (i==0&&j==0&&k==0) continue;
					cscore=m[0].g*i+m[0].a*j+m[0].c*k;
					for(l=1;l<=c;++l)
					{
						score=m[l].g*i+m[l].a*j+m[l].c*k;
						if (cscore<=score) break;
					}
					if (l>c) {puts("Canada win");result=false;break;}
				}
			}
		}
		if (result) puts("Canada cannot win");
	}
	return 0;
}