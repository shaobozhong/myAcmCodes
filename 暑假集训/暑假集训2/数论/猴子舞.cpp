/*
算法分析：分成n个圈子 最小公倍数最大的  就是所求   而由互质的数组成的必定是最大的   互质的数 可以由质数组成
并且质数的多次方之间也会是互质的 只要不用 2 和3  6 和所有的质数都是互质的   

*/
#include<iostream>
#include<cmath>
using namespace std;
long long max1;
int p[100];
int vis[100];
void getprime()//获得一定范围内的素数   第一个置为6  有妙用
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



void checkres(int num,int k)//检验当前状态可达到的步数  其实就是计算步数
{
	int i,j;
	long long res;
	if (num==1) return;//若是1 返回  
    res=1;
	for(i=1;i<=k;++i)//计算个互质的数的乘积 即最小公倍数 
	{
		if (vis[i]>0)
		{
			for(j=0;j<vis[i];++j)
			{
				res*=p[i];
			}
		}
	}

	//特殊处理2和3两个素数
	if (vis[0]==0)//不用六的时候 2 和 3 可用可不用
	{
		
		if (vis[1]==0 &&(num==2 || num>3)) res*=2;//要是 2 没有用 并且 num不等于3  并且比2 大  那么就是用2
		if (vis[2]==0 && (num % 2==1)) res*=3;//要是 3没有用 并且num等于或是大于3 就是用3 
	}
	else//用六的时候  2和3 必须要用  含1的情况即 5+1=6  5=2+3；
	{
		if (vis[1]==0) res*=2;//要是没有用到2 这个因子 也就是没有用到 2的 某次方
		res*=3;//必定用3   
	}

	if (res>max1)  //将当前的步数和max1 比较 要是大 就更新
	{
		max1=res;
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
void work(int num,int k)
{
	int val;
	val=p[k];//确定该素数为基数
	vis[k]=0;//开始时0次幂 也就是不取
	if (val>num) //如果现在的val放不下 就对k-1进行计算步数
	{
		checkres(num,k-1);
		return;
	}

    work(num,k+1);//不取用当前的这个素数 

	++(vis[k]);  //表示接下了用val 就用到了这个素数

    if (k<3)//2和3 已经在最后特殊考虑了   在搜索过程中 不进行搜索  直接升幂 到  4 或 9
	{
		++(vis[k]);
		val=val*p[k];
	}

	while(val<num-1)//对当前素数的1-n   当前素数的n次方  大于等于 num-1   为什么是num-1 因为 搜索后面剩余1 的情况没有意义
	{
		work(num-val,k+1);//取用 当前素数的某次方  然后继续往后搜索
		val=val*p[k];//升幂
		++(vis[k]);//标记幂的数组当然要更新
	}

	if (val==num) checkres(0,k);//若是最后正好等于 num自然要再运算一次
}

//含有1元素的搜索
void findresult1(int num,int k)//剩下的数是num当前 搜索的是第k个素数
{
	int val;
	val=p[k];//确定基数
	vis[k]=0;//开始时0次幂 也就是不取
	if (val>num)//同上
	{
		if (num==2 || num==4) checkres(num,k-1);//最后只能剩偶数 不然 那个1 白处理了
        return;
	}
	findresult1(num,k+1);//不取用 当前素数
	if (k==2) return;//不使用 当前素数和他的某次幂  因为 最后要用到3 
	++(vis[k]);//升幂为1次
	if (k==1) //不用2  但是用2的 除去 1以外的其他次方
	{
		++(vis[k]);
		val=val*p[k];
	}

	while(val<num-1)//基本同上
	{
		findresult1(num-val,k+1);
		val*=p[k];
		++(vis[k]);
	}
	if (val==num) checkres(0,k);
}

int main()
{
	int num;
	getprime();
	while(scanf("%d",&num),num!=0)//输入待求的圈子个数
	{
		memset(vis,0,sizeof(vis)); //对标记 指数的数组 赋初值
	    max1=0;//max1 赋初值
		work(num,1);//普通搜索  只有  6 才可能出现1 的情况 而 2*3==6  6本身就应该是6 即走一圈
		if (num>=6)//要是大于6  可能出现 1 的情况
		{
			vis[0]=1;//用到6
			vis[1]=0;//不用2
			vis[2]=0;//不用3
			if (num>6) findresult1(num-6,1);//含1 情况的搜索
			else checkres(0,0);//减掉六了 已经满了
		}
		printf("%lld\n",max1);//输出结果
	}
	return 0;
}