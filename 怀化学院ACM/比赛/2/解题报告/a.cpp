#include <stdio.h>
#include <string.h>
int v[1000];
int main()
{
	int k,kk,m;
	while(scanf("%d",&k) ,k)
	{		
		m=1;kk=k;
		while(kk<1000)
		{
			kk*=k;
			m++;
		}
		k=k%1000;
		kk=kk%1000;
		for(memset(v,0,sizeof(v));;m++)
		{
			if(v[kk]) break;
			v[kk]=m;
			kk=(kk*k)%1000;
		}
		printf("%d\n",v[kk]+m);
	}
	return 0;
}