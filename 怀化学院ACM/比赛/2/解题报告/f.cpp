#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	//FILE *fin,*fout;
	//fin=fopen("data1.in","r");fout=fopen("data1.out","w");
	char a[30],b[30],c[30];
	int i,j,q1,q2,t,flag,count=0;
	double sum1=0,speed,speed1=0,t1,t2,sum;
    while(gets(a)!=NULL)
	{   
		count++ ;if(count==1)
	{  strcpy(c,a); }
		flag=0;
		speed=0;t=strlen(a);
		for(i=0;i<t;i++)
		{  
			if(a[i]==' ')
			{flag=1;	break;}
		}
             if(flag!=1)
			 { 
                strcpy(b,a);
			 }
			 else
			 {  
			 i=0;
				 while(a[i]!=' ')
				 {i++;}
				 for(i=i+1;i<t;i++)
                   speed=(a[i]-'0')+speed*10;
				 if(count==1)
				 speed1=speed;
                   q1=0;
			  while(c[q1]!=':')
			  {
				  q1++;
			  }q2=0;
		     while(a[q2]!=':')
                     q2++;
			  t1=0;
			  for(i=0;i<q1;i++)
			  {
				  t1=(c[i]-'0')+t1*10;
			  }
		      t2=0;
			  for(i=0;i<q2;i++)
			  {
				  t2=(a[i]-'0')+t2*10;
			  }
			 sum1+=(t2-t1)*speed1;
			 t1=0;t2=0;
              for(i=q1+1;i<=q1+2;i++)
			  {
                     t1=(c[i]-'0')+t1*10;
			  }
			for(i=q2+1;i<=q2+2;i++)
			  {
                     t2=(a[i]-'0')+t2*10;
			  }
              sum1+=(t2-t1)/60*speed1;
			  t1=0;t2=0;
			  for(i=q1+4;i<=q1+5;i++)
			  {
                       t1=(c[i]-'0')+t1*10;
			  }
			  for(i=q2+4;i<=q2+5;i++)
			  {
                       t2=(a[i]-'0')+t2*10;
			  }
				 sum1+=speed1*(t2-t1)/3600;
                   speed1=speed;
				   strcpy(c,a);
				 memset(b,'a',sizeof(char)*30);
			 }
		  		  
			  if(b[0]=='a')continue;
			  else{
				  q1=0;
			  while(c[q1]!=':')
			  {
				  q1++;
			  }
			  q2=0;
		     while(b[q2]!=':')
                     q2++;
			  t1=0;
			  for(i=0;i<q1;i++)
			  {
				  t1=(c[i]-'0')+t1*10;
			  }
		      t2=0;
			  for(i=0;i<q2;i++)
			  {
				  t2=(b[i]-'0')+t2*10;
			  }
			 sum=t2-t1;
			 t1=0;t2=0;
              for(i=q1+1;i<=q1+2;i++)
			  {
                     t1=(c[i]-'0')+t1*10;
			  }
			for(i=q2+1;i<=q2+2;i++)
			  {
                     t2=(b[i]-'0')+t2*10;
			  }
              sum+=(t2-t1)/60;
			  t1=0;t2=0;
			  for(i=q1+4;i<=q1+5;i++)
			  {
                       t1=(c[i]-'0')+t1*10;
			  }
			  for(i=q2+4;i<=q2+5;i++)
			  {
                       t2=(b[i]-'0')+t2*10;
			  }
			  sum+=(t2-t1)/3600;
			  printf("%s %.2lf km\n",b,sum*speed1+sum1);
			  }
	}
	return 0;
}
