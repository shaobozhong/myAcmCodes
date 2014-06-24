#include<iostream>
using namespace std;


typedef struct 
{
	int start,end;
	bool la;
}desk;

typedef struct 
{
	int start,end;
}action;

int main()
{
	int T,nd,i,count,nac,j,loca;
	desk *table;
	action *ac;
	cin>>T;
	for(;T>=1;T--)
	{
		count=0;
		cin>>nd;
		table=new desk[nd+1];
		ac=new action[nd+1];
		for(i=0;i<=nd-1;i++)
		{
			cin>>table[i].start>>table[i].end;
			table[i].la=true;
		}
		loca=0;
		while(loca<=nd-1)
		{
			nac=0;
			for(i=0;i<=nd-1;i++)
			{
				if (table[i].la)
				{
					ac[nac].start=table[i].start;
					ac[nac++].end=table[i].end;
					table[i].la=false;
					count++;
					break;
				}
			}
			loca=i;
			if (loca<=nd-1)
			{
				for(i=0;i<=nd-1;i++)
				{
					if (table[i].la)
					{
						for(j=0;j<=nac-1;j++)
						{

							if ((table[i].start>=ac[j].start&&table[i].start<=ac[j].end||table[i].end>=ac[j].start&&table[i].end<=ac[j].end)   ||   (table[i].start<=ac[j].start&&table[i].end>=ac[j].start)&&table[i].end>=ac[j].end)
							{
								break;
							}
						}
						if (j==nac) 
						{
							ac[nac].start=table[i].start;
							ac[nac++].end=table[i].end;
							table[i].la=false;
						}
					}
				}
			}
		}
		cout<<count*10<<endl;
		free(ac);
		free(table);   		
	}
	return 0;
}