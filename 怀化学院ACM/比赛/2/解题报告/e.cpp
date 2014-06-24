#include<stdio.h>
int b[1000][4];
int main()
{
		int N,i,j,a[101],q,w,t1,t2,t3,t,m;
		a[1]=0;
		for(i=2;i<101;i++)
		{
                a[i]=i*i*i;
		}
		while(scanf("%d",&N)>0)
		{
                      m=0;
			if(N<6)continue;
			else
			{
                            for(i=6;i<=N;i++)
				{
					for(j=i;a[j]>=a[i]/3;j--)
					{ 
						t1=j;
                                              t=a[i]-a[j];
						for(q=j;a[q]>=t/2;q--)
						{       t2=q;t3=0;
							for(w=q;w>1;w--)
								if(t-a[q]<0)break;
								else
								if(a[w]==t-a[q])
								{t3=w;break;}
							if(t3!=0)
							{b[m][0]=i;b[m][1]=t3;b[m][2]=t2;b[m][3]=t1;m++;}
						}
					}

				}
				printf("Cube = %d, Triple = (%d,%d,%d)\n",b[0][0],b[0][1],b[0][2],b[0][3]);
				for(i=1;i<m;i++)
				{   
					
					if(b[i][0]==b[i+1][0])
					{
						for(j=i;b[i][0]==b[j+1][0];j++)
							;
						for(q=i;q<j;q++)for(w=q;w<j+1;w++)
                                                    if(b[q][1]>b[q+1][1])
							 {
								 t=b[q][1];b[q][1]=b[q+1][1];b[q+1][1]=t;
						         t=b[q][2];b[q][2]=b[q+1][2];b[q+1][2]=t;
								 t=b[q][3];b[q][3]=b[q+1][3];b[q+1][3]=t;
						}

					}
					printf("Cube = %d, Triple = (%d,%d,%d)\n",b[i][0],b[i][1],b[i][2],b[i][3]);
				}
			}
		}
	return 0;
}