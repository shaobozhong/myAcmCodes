#include <stdio.h>
#include <string.h>
#define NL 104
int adj[NL][NL]; 
// 0 is exit
int my[NL], mx[NL];
bool used[NL];
int n;

bool path(int u)
{ 
	for (int v=1; v<=n; v++)
	{       
		if (!adj[u][v] && !used[v]) 
		{            
			used[v] = true; 
			if (my[v] == -1 || path(my[v])) 
			{             
				my[v] = u;
				mx[u] = v; 
				return true;       
			}                  
		}    
	}  
	return false;
}

int main()
{  
	int i;  
	bool flag=false;
	while (scanf("%d", &n) != EOF)
	{       
		if (flag) putchar('\n');
		flag=true;
		int x, y;       
		memset(adj, 0, sizeof(adj));   
		while (scanf("%d%d", &x, &y)) 
		{           
			if (!x && !y) break; 
			adj[x][y] = 1;     
		}      
		memset(mx, -1, sizeof(mx));  
		memset(my, -1, sizeof(my));    
		int match = 0;       
		for (i=1; i<=n; i++) 
		{           
			memset(used, 0, sizeof(used));  
			if (path(i)) match++;      
		}       
		if (match != n) {    
			printf("none\n"); 
			continue;  
		}


		int cnt = 0;       
		for (i=1; i<=n; i++) 
		{         
			int t = mx[i]; 
			my[t] = -1;     
			adj[i][t] = 1;    
			memset(used, 0, sizeof(used));        
			if (!path(i)) 
			{              
				my[t] = i;       
				cnt++;        
				printf("%d %d\n", i, mx[i]);  
			}            
			adj[i][t] = 0;
		}
		if (!cnt) puts("none"); 
		//printf("\n");    
	}    
	return 0;
}

