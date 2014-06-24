#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int _dp[305];
char _str[305];
char _index[601][30];
int nen[601];

int main()
{
	int _W,n,i,j,k,l,_temp;
	scanf("%d%d",&_W,&n);
   //while (scanf("%d%d",&_W,&n)!=EOF)
   {
	   getchar();
	   gets(_str);
	   //scanf("%s",_str);
	   for (i=0;i<n;++i)
	   {
		   _dp[i]=i+1;//初值
	   }
       for (i=0;i<_W;++i)
       {
		   gets(_index[i]);//输入
		   //scanf("%s",_index[i]);
		   nen[i]=(int)strlen(_index[i]);//nen匹配上的个数 自然就是单词的长度
	   }

	   for (i=0;i<n-1;++i)
	   {
		   for (j=0;j<_W;++j)
		   {
			   
			   if ((n-i+1)<nen[j]) continue;
			   for (k=i,l=0;k<n&&l<nen[j];++k,++l)//匹配过程
			   {
                   if (_str[k]!=_index[j][l])  --l; 
			   }
			   if (l<nen[j]) continue;//匹配到最后也不能包含正在进行匹配的单词
			   if (i==0) _temp=k-nen[j];//这里_temp是求出的一个dp[k-1]的值
			   else _temp=_dp[i-1]+k-i-nen[j];//这里就是动态方程
			   if (_dp[k-1]>_temp) _dp[k-1]=_temp;
		   }
		   if (_dp[i+1]>_dp[i]+1) _dp[i+1]=_dp[i]+1;//下一个位置不包含那么只能+1 得到值
	   }
	   printf("%d\n",_dp[n-1]);
   }
	return 0;
}
