#include<cstdio>
using namespace std;
int p[30005], c[30005], t[30005];
int find(int x)
{   
	if(x!=p[x]) 
	{        
		int px=p[x];  
		p[x]=find(p[x]);
		c[x]=c[x]+c[px];
	}   
	return p[x];
}

int main()
{    
	int pp, x, y, px, py;   
	char ch;  
	scanf("%d", &pp); 
	for(int i=1; i<=30000; i++)
	{
		p[i]=i; c[i]=0; t[i]=1;
	}    
	while(pp--)
	{       
		while(scanf("%c", &ch)) if(ch!='\n' && ch!=' ') break; 
		if(ch=='M') 
		{          
		scanf("%d%d", &x, &y);         
		px=find(x);         
		py=find(y);         
		if(px!=py) 
		{               
			p[py]=px;    
			c[py]+=t[px];          
			t[px]+=t[py];        
		}  
		}     
		else 
		{     
			scanf("%d", &x);      
			px=find(x);           
			printf("%d\n", t[px]-c[x]-1);   
		}  
	}   
	return 0;
}