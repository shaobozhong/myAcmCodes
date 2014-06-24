#include<iostream>
using namespace std;

int a[20001];
int main()
{
    int count;
	int sumA,sumB;
	int n,i,j,num;
	while(scanf("%d",&n)>0&&n!=0)
	{
		num=2*n;
		count=0;
		sumA=0;sumB=0;
		for(i=0;i<num;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=-1,j=num;i<num,j>=0;)
		{
			if (sumA==sumB&&i!=-1&&j!=-1) count++;
			if (sumA>sumB) {j--;if (j<0) break; sumB+=a[j];}
			else {i++;if (i>num-1) break;sumA+=a[i];}
			
		}
		printf("%d\n",count);
	}
	return 0;
}