#include <queue>
#include <cstdio>
#define N 35
#define pr printf
using namespace std;
int map[N][N];
int step[N][N];
int counter[N][N];
int g[N][N][N][N];
int s[2],e[2];
int R,C;
queue<pair<int,int> >Q;

int mx[8] = {-2,-1,+1,+2,+2,+1,-1,-2};
int my[8] = {-1,-2,-2,-1,+1,+2,+2,+1};



bool check(int x,int y){
	return x>=0 && x<R && y >=0 && y<C;
}
void solve()
{
	int i,j,k,x,y,a,b,nexti,nextj;

	for(i = 0 ; i < R ; i ++){    
		for(j = 0 ; j < C; j ++){
			if(map[i][j] == 0){           

				//bfs,缩点
				g[i][j][i][j] = 1;//!!!!!!!!!!
				Q.push(make_pair(i,j));
				while(!Q.empty()){                
					int a = Q.front().first;
					int b = Q.front().second;
					Q.pop();
					for(k = 0 ; k < 8 ; k ++){                    
						nexti = a + mx[k];
						nextj = b + my[k];
						if(check( nexti,nextj ) && map[nexti][nextj] == 1 && g[i][j][nexti][nextj] == 0){                        
							g[i][j][nexti][nextj] = 1;
							Q.push( make_pair(nexti,nextj) );
						}
					}
				}

				for(x = 0 ; x < R ; x ++){                
					for(y = 0 ; y < C ; y ++){                    
						if(g[i][j][x][y] == 1){
							for(k = 0 ; k < 8 ; k ++){                            
								nexti = x + mx[k];
								nextj = y + my[k];
								if( check(nexti,nextj) && map[nexti][nextj] == 0 && g[i][j][nexti][nextj] == 0){
									g[i][j][nexti][nextj] = 2;
								}
							}
						}
					}
				}
			}
		}
	}

	//BFS走缩点后的地图，既g[][][][] = 2
	step[ s[0] ][ s[1] ] = 0;
	counter[ s[0] ][ s[1] ] = 1; 
	Q.push( make_pair(s[0],s[1]) );

	while(!Q.empty()){
		a = Q.front().first;
		b = Q.front().second;
		Q.pop();
		for(i = 0 ; i < R ; i ++)
		{
			for(j = 0 ; j < C ; j ++)
			{
				if(g[a][b][i][j] == 2){
					if(step[i][j] == -1){
						step[i][j] = step[a][b] + 1;
						counter[i][j] = counter[a][b];
						Q.push( make_pair(i,j) );
					}
					else
						if(step[i][j] == step[a][b] + 1)
							counter[i][j] += counter[a][b];
				}
			}
		}
	}



	if(step[e[0]][e[1]] == -1)pr("-1\n");
	else pr("%d\n%d\n",step[e[0]][e[1]] - 1 , counter[e[0]][e[1]]);

}
int main()
{
	int i,j;
	while(scanf("%d%d",&R,&C) != EOF)
	{
		//reset
		memset(g,0,sizeof(g));
		while(!Q.empty())Q.pop();
		memset(step,-1,sizeof(step));
		//input
		for(i = 0 ; i < R ; i ++)
		{
			for(j = 0 ; j < C; j ++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j] == 3)map[i][j] = 0,s[0] = i, s[1] = j;
				if(map[i][j] == 4)map[i][j] = 0,e[0] = i, e[1] = j;
			}
		}
		//pr("%d %d\n %d%d\n",s[0],s[1],e[0],e[1]);

		solve();

	}


	return 0;
}
