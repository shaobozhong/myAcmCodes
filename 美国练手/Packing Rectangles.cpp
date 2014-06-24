/*
ID: shaoboz2
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 
int p[4];
bool e[4];
int sq;
 
typedef struct {
    int x, y;
}matrix;
 
matrix mat[ 4 ],mat2[ 4 ];
vector < matrix > ans;
 
inline int Max( int x, int y ) {
    return ( x > y ) ? x : y;
}
 
void update ( matrix tmp , int cas) {
    if ( tmp.x > tmp.y ) {
        int temp = tmp.x;
        tmp.x = tmp.y;
        tmp.y = temp;
    }
    if ( tmp.x * tmp.y < sq ) {
        sq = tmp.x * tmp.y;
        ans.clear();
        ans.push_back( tmp );
    }
    else
        if ( tmp.x * tmp.y == sq) {
        int SZ = ans.size();
        for (int i = 0; i < SZ; i++) {
            if ( tmp.x == ans[ i ].x && tmp.y == ans[ i ].y )
                return;
        }
        ans.push_back ( tmp );
    }
}
 
int calc() {
    matrix tmp;
    int i;
 
    // case 1
    tmp.x = 0;
    tmp.y = 0;
    for (i = 0; i < 4; i++) {
        tmp.x += mat[ p[ i ] ].x;
        tmp.y = Max ( tmp.y, mat[ p[ i ] ].y);
    }
    update ( tmp , 1 );
 
    // case 2
    tmp.x = 0;
    tmp.y = 0;
    for (i = 0; i < 3; i++) {
        tmp.x += mat[ p[ i ] ].x;
        tmp.y = Max ( tmp.y, mat[ p[ i ] ].y );
    }
    tmp.x = Max ( tmp.x , mat[ p[ 3 ] ].x );
    tmp.y += mat[ p[ 3 ] ].y;
    update ( tmp , 2);
 
    // case 3
    tmp.x = Max ( mat[ p[ 0 ] ].x + mat[ p[ 1 ] ].x , mat[ p[ 2 ] ].x ) + mat[ p [ 3 ] ].x;
    tmp.y = Max ( Max (mat[ p[ 0 ] ].y, mat[ p[ 1 ] ].y) + mat[ p[ 2 ] ].y , mat[ p[ 3 ] ]. y );   
    update ( tmp , 3);
 
    // case 4
    tmp.x = mat[ p[ 0 ] ].x + mat[ p[ 3 ] ].x;
    tmp.x += Max( mat[ p[ 1 ] ].x, mat[ p[ 2 ] ].x );
    tmp.y = Max( mat[ p[ 0 ] ].y, mat[ p[ 3 ] ].y );
    tmp.y = Max( tmp.y, mat[ p[ 1 ] ].y + mat[ p[ 2 ] ].y );
    update ( tmp , 4);
 
    // case 5
    tmp.x = Max( mat[ p[ 0 ] ].x, mat[ p[ 1 ] ].x );
     tmp.x += mat[ p[ 2 ] ].x + mat[ p[ 3 ] ].x;
    tmp.y = Max( Max( mat[ p[ 0 ] ].y + mat[ p[ 1 ] ].y, mat[ p[ 2 ] ].y ), mat[ p[ 3 ] ].y );
    update ( tmp , 5);   
 
    // case 6   ps : Think About All the Cases
 
    tmp.x = Max ( mat[ p[ 0 ] ].x + mat[ p[ 2 ] ].x , mat[ p[ 1 ] ].x + mat[ p[ 3 ] ].x ) ;
 
    if ( mat[ p[ 2 ] ].x < mat[ p[ 3 ] ].x && mat[ p[ 0 ] ].x > mat[ p[ 1 ] ].x &&
            mat[ p[ 0 ] ].y < mat[ p[ 2 ] ].y && mat[ p[ 1 ] ].y > mat[ p[ 3 ] ].y ) {
        tmp.y = Max( mat[ p[ 0 ] ].y + mat[ p[ 1 ] ].y, mat[ p[ 2 ] ].y + mat[ p[ 3 ] ].y );
 
    }
    else
        tmp.y =   Max ( mat[ p[ 0 ] ].y , mat[ p[ 2 ] ].y ) + Max (mat[ p[ 1 ] ].y , mat[ p[ 3 ] ].y );
 
    update( tmp , 6);
 
    return 0;
}
 
int main() {
    int i, j;
    int dfs(int dep);
    ifstream fin( "packrec.in" );
    ofstream fout( "packrec.out" );
    for (i = 0; i < 4; i++) {
        fin >> mat[ i ].x >> mat[ i ].y;   
    }
    for (i = 0; i < 4; i++) {
        e[ i ] = false;
    }
    sq = 1000000;
    dfs( 0 );
    int sz = ans.size();
    matrix tmp;
    for (i = 0; i < sz; i++)
        for (j = i + 1; j < sz; j++) {
            if ( ans[ i ].x > ans[ j ].x || ( ans[ i ].x == ans[ j ].x && ans[ i ].y > ans[ j ].y ) ) {
                tmp = ans[ i ];
                ans[ i ] = ans[ j ];
                ans[ j ] = tmp;
            }
        }
    fout << ans[ 0 ].x * ans[ 0 ].y << endl;
    for (i = 0; i < ans.size(); i++) {
        fout << ans[ i ].x << ' ' << ans[ i ].y << endl;
    }
    return 0;
}
int dfs(int dep) {
    int temp;
    int i, j ,k;
    if (dep == 4) {
        for (k = 0; k < 4; k++) {
            mat2[ k ].x = mat[ k ].x;
            mat2[ k ].y = mat[ k ].y;
        }
         for ( j = 0; j < 15; j++) {
            for (k = 0; k < 4; k++) {
                if ( j & (1 << k) ) {
                    mat[ p[ k ] ].x = mat2[ p[ k ] ].y;
                    mat[ p[ k ] ].y = mat2[ p[ k ] ].x;
                }
                else {
                    mat[ p[ k ] ].x = mat2[ p[ k ] ].x;
                    mat[ p[ k ] ].y = mat2[ p[ k ] ].y;
                }
            calc();
            }
        }
        return 0;
    }
    else {
        for (i = 0; i < 4; i++) {
            if (!e[ i ]) {
                p[ dep ] = i;
                e[ i ] = true;
                dep++;
                dfs( dep );
                dep--;
                e[ i ] = false;
            }           
        }
    }
    return 0;
}
 
 
