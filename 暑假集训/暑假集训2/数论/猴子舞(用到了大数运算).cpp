/*
根据分析可以知道，由质数组成可以得到最大值   详见  书
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;
#define MAX 1000
int p[100];
char max1[MAX];
int vis[100];
int svis[100];

int sk;
/******************************************************************/
void reverse(char *from, char *to )
{
	int len=int(strlen(from));
	int i;
	for(i=0;i<len;i++)
		to[i]=from[len-i-1];
	to[len]='\0';
}
/******************************************************************/
void call_mult(char *first,char *sec,char *result)
{
	char F[MAX],S[MAX],temp[MAX];
	int f_len,s_len,f,s,r,t_len,hold,res;
	f_len=int(strlen(first));
	s_len=int(strlen(sec));
	reverse(first,F);
	reverse(sec,S);
	t_len=f_len+s_len;
	r=-1;
	for(f=0;f<=t_len;f++)
		temp[f]='0';
	temp[f]='\0';
	for(s=0;s<s_len;s++)
	{
		hold=0;
		for(f=0;f<f_len;f++)
		{
			res=(F[f]-'0')*(S[s]-'0') + hold+(temp[f+s]-'0');
			temp[f+s]=res%10+'0';
			hold=res/10;
			if(f+s>r) r=f+s;
		}
		while(hold!=0)
		{
			res=hold+temp[f+s]-'0';
			hold=res/10;
			temp[f+s]=res%10+'0';
			if(r<f+s) r=f+s;
			f++;
		}
	}
	for(;r>0 && temp[r]=='0';r--);
	temp[r+1]='\0';
	reverse(temp,result);
}
/***************************************************************/
void getprime()//获得一定范围内的素数
{
	int count1;
	int i,j;
	memset(p,0,sizeof(p));
	p[0]=6;
	p[1]=2;
    count1=2;
	for(i=3;i<300;++i)
	{
		for(j=2;j<=int(sqrt(double(i)));++j)
		{
			if (i%j==0) break;
		}
		if (j>int(sqrt(double(i)))) p[count1++]=i; 
	}
	p[count1]=INT_MAX;
}


void itoa1(int num,char *res,int ra)
{
	char a[MAX];
	int i;
	int count1;
	count1=0;
	while(num)
	{
		a[count1++]=num%ra;
		num/=ra;
	}
	for(i=count1-1;i>=0;--i)
	{
		res[count1-1-i]=char(a[i]+48);
	}
	res[count1]='\0';
}

bool whomax(char *tempres)//比较两个用字符串存起的两个大整数的大小
{
	int len1,len2;//临时结果和max1的长度
	int i;
	len1=int(strlen(tempres));
	len2=int(strlen(max1));

	if (len1>len2) return true;
	if (len1<len2) return false;
	for(i=0;i<len1;++i)
	{
		if (tempres[i]>max1[i]) return true;
		if (max1[i]>tempres[i]) return false;
	}
	return false;
}

void checkres(int num,int k)//检验当前状态可达到的步数
{
	int i,j;
	char temp[MAX];
	char res[MAX];
	if (num==1) return;//如果剩余1 返回
	strcpy(res,"1");//给当前步数 赋初值1 
	for(i=1;i<=k;++i)//将各个分解出来的数 相乘 得结果
	{
		if (vis[i]>0)
		{
			for(j=0;j<vis[i];++j)
			{
				itoa1(p[i],temp,10);
				call_mult(res,temp,res);
			}
		}
	}

	//特殊处理2和3两个素数
	if (vis[0]==0)//要是没有用到6  
	{
		//分别判断 2 和 3 是否能放进去  就是剩下的要是 3 就用3  比三大就用2 并且是奇数 就用3
		if (vis[1]==0 &&(num==2 || num>3)) call_mult(res,"2",res);//如果2没用 而且（剩下2 或者 剩下的数大于3 ） 那么把我乘进去 也就是算进去
		if (vis[2]==0 && (num % 2==1)) call_mult(res,"3",res);//如果3没被用过 而且 剩下的num是奇数 当然不可能是1啦！ 至少是5 2 和 3 同用
	}
	else //要是用到了6  也就是 针对含1元素搜索的情况
	{
		if (vis[1]==0) call_mult(res,"2",res);//2没用过 就用2 
		call_mult(res,"3",res);//一定用3  这样就由 2 和 3 构成了6  而不是 用和数6 
	}

	if (whomax(res))  //将当前的步数和max1 比较 要是大 就更新
	{
		strcpy(max1,res);
        /*在本题里面没有用 是更新最佳状态的
		for(i=0;i<100;++i)
		{
			svis[i]=vis[i];
		}
		sk=k;
		*/
	}
}
//一般搜索
void work(int num,int k)//素数的多次方之间 还是互质的 因为 他的因子 除了1和本身 只有该素数
{
	int val;
	val=p[k];
	vis[k]=0;
	if (val>num) //若是当前的素数已经大于 num
	{
		checkres(num,k-1);
		return;
	}

    work(num,k+1);//不取用当前的这个素数

	++(vis[k]);//使用了下标为k的素数的计数数组加1  代表用的是 当前素数的1次方  

    if (k<3)//如果当前的k小于3  也就是 是素数2 或者 3    因为2 和 3 会特殊处理
	{
		++(vis[k]);//当前素数使用次数  加1  代表要用到 该素数的平方
		val=val*p[k];// val乘以当前素数  也就是当前素数的 平方
	}

	while(val<num-1)
	{
		work(num-val,k+1);//先使用 当前素数的某次方 进行搜索 
		val=val*p[k];//升幂
		++(vis[k]);//标记加1  代表此素数的升幂
	}

	if (val==num) checkres(0,k);//最后若是等于num 则使用该素数   否则结束
}

//含有1元素的搜索
void findresult1(int num,int k)
{
	int val;
	val=p[k];// 该素数的1次方
	vis[k]=0;//初始化 次数为0  也就是
	if (val>num)//如果大于num了 就进行计算
	{
		if (num==2 || num==4) checkres(num,k-1);//num剩下的必须要是2 或者4  
        return;
	}
	findresult1(num,k+1);//不取当前的素数
	if (k==2) return;//如果到了 3 就返回  也就是不使用3 和3的某次幂  就不会出现6和6的倍数
	++(vis[k]);//变成1 次幂
	if (k==1) //要是是使用2  就直接升幂一次 用四
	{
		++(vis[k]);//标记加1
		val=val*p[k];//升幂
	}

	while(val<num-1)//升幂 同时进行搜索
	{
		findresult1(num-val,k+1);//搜索当前次幂的可行方案
		val*=p[k];
		++(vis[k]);
	}
	if (val==num) checkres(0,k);//如果等于 num了 就进行计算  否则大于则结束
}

int main()
{
	int num;
	getprime();
	while(cin>>num,num!=0)
	{
		memset(vis,0,sizeof(vis));//给标记数组赋初值  
		strcpy(max1,"0");// 最大值 初值 置为零
		work(num,1);//从素数2 开始搜索
		if (num>=6)
		{
			vis[0]=1;//代表使用了 6的1次方
			vis[1]=0;
			vis[2]=0;
			if (num>6) findresult1(num-6,1);//如果数大于六 分解其中一个圈为6
			else checkres(0,0);//6的处理 等于六 直接用六表示
		}
		cout<<max1<<endl;
	}
	return 0;
}