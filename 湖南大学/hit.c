#include<stdio.h>
int main()
{
	int k,n,l,z,i,v[1001];
	
	double d,m,tscore,accuracy,score,t300,t100,t50,t0;
	scanf("%d",&n);
	for(z=1;z<=n;z++)
		
	{k=0;tscore=0;score=0;	t300=0;t100=0;t50=0;t0=0;
	scanf("%lf%lf%d",&d,&m,&l);
	for(i=0;i<=l-1;i++)
	{
		scanf("%d",&v[i]);
		if (v[i]==0) {k=0;t0++;}
		if (v[i]==300) t300++;
		if (v[i]==100) t100++;
		if (v[i]==50) t50++;
		score+=v[i];
		if (k!=0)
			tscore+=v[i]+v[i]*((k-1)*d*m)/25.0;
		else 
			tscore+=v[i]+v[i]*(k*d*m)/25.0;
		if (v[i]!=0) k++;
	}
	t300/=l;t100/=l;t50/=l;t0/=l;
	accuracy=score/(l*300);
	printf("%.2f %.2f%% ",tscore,accuracy*100);
	   if (accuracy==1) printf("SS\n");
	   else if (t300>0.9&&t50<0.01&&t0==0) printf("S\n");
	   else if (t300>0.8&&t0==0||t300>0.9)  printf("A\n");
	   else if ( t300>0.7&&t0==0||t300>0.8) printf("B\n");
	   else if (t300>0.6) printf("C\n");
	   else printf("D\n");
	   
	}
	return 0;
}