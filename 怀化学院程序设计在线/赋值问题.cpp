#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	int t,n,count,j;
	char s[4];
	char a[53];
	set<char> result;
	set<char>::iterator i;
	scanf("%d",&t);
	while(t--)
	{
		result.insert('a');
        scanf("%d",&n);
        while(n--)
		{
			scanf("%s",s);
			if (result.find(s[2])!=result.end()) result.insert(s[0]);
		}
		if (result.size()==1) {puts("None.");continue;}
        for(i=result.begin();i!=result.end();++i)
		{
			if(*i=='a') continue;
			cout<<*i<<" ";
		}
		cout<<endl;
		/*count=0;
		for(i=result.begin();i!=result.end();++i)
		{
			a[count++]=*i;
		}

        for(j=0;j<count-1;++j)
		{
			if(a[j]=='a') continue;
			printf("%c ",a[j]);
		}
          if(a[j]!='a')  printf("%c",a[j]);
		putchar('\n');*/
			result.clear();

	}
	return 0;
}