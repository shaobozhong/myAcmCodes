#include<iostream>
using namespace std;

typedef struct 
{
	int month;
	int cost;
}Elem;

int main()
{
	int limit,cost,month,i,j,k,l,temp,r[4];
	Elem th[3],ex[3],gov[3],sale[3];
	while(scanf("%d",&limit),limit!=0)
	{
		cost=INT_MAX;
           for(i=0;i<3;i++)
		   {
			   scanf("%d%d%d%d%d%d%d%d",&th[i].month,&th[i].cost,&ex[i].month,&ex[i].cost,&gov[i].month,&gov[i].cost,&sale[i].month,&sale[i].cost);
		   }
        for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					for(l=0;l<3;l++)
					{
						month=th[i].month+ex[j].month+gov[k].month+sale[l].month;
						if (month>limit) continue;
						temp=th[i].cost+ex[j].cost+gov[k].cost+sale[l].cost;
						if (temp>=cost) continue;
						cost=temp;
						r[0]=i;r[1]=j;r[2]=k;r[3]=l;
					}
				}
			}
		}

		if (cost==INT_MAX) {puts("NO.");continue;}
        for(i=0;i<4;i++)
		{
			switch(r[i])
			{
			case 0:printf("SLOW");break;
			case 1:printf("NORMAL");break;
			case 2:printf("QUICK");break;
			}
			if (i<3) printf("->");
		}
		puts(".");
	}
	return 0;
}