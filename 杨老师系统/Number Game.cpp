#include<iostream>

#include<cstring>

#include<algorithm>

using namespace std;

int r,a[3],b[3],c[3],d[3],e[3];

bool chk(int aa[],int cc[]){

    int i;

    for(i=0; i<3; i++) if(aa[i]!=cc[i]) return false;

    return true;

}

int main(){

	int i;
    scanf("%d",&r);

    while(r--){

        scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);

        sort(a,a+3); sort(b,b+3);

        int t=0;

        if( chk(a,b) ) { printf("Yes\n"); continue; }       

        c[0]=b[0]; c[1]=b[1]; c[2]=(b[0]+b[1])-1; sort(c,c+3);      

        d[0]=b[1]; d[1]=b[2]; d[2]=(b[1]+b[2])-1; sort(d,d+3);     

        e[0]=b[0]; e[1]=b[2]; e[2]=(b[0]+b[2])-1; sort(e,e+3);

        int pp[3];

         for(i=0;i<3;++i)
			{
				pp[i]=a[i];
			}

        while(1){

        if( chk(a,c) || chk(a,d) || chk(a,e) ) { t=1; printf("Yes\n"); break; }  //3 3 5 3 3 3  这组数据发现我的程序忘记先判断，再变化了 

            if(a[2]!=a[1]+a[0]-1) break;

            a[2]=a[1]+1-a[0];

            sort(a,a+3);    

            if( chk(a,pp) ) break;      

            for(i=0;i<3;++i)
			{
				pp[i]=a[i];
			}

        }

        if(!t) {

            if( chk(a,c) || chk(a,d) || chk(a,e) ) printf("Yes\n");

            else printf("No\n");

        }

    }return 0;

}
