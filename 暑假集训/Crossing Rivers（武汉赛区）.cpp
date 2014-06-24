//本题意思是很简单 就是  A地到B地 中间有n条河 过河是要船的 开始时船可以在任意位置 告诉你河的宽度和过河的速度 并且河是不会重叠的  陆地上行走速度为1
//求的是从A地到B地的预期时间   这个题目主要是看出预期时间是最大时间  所以只要所有的河都算成是 到的时候 船正好在对岸
//也就是过河时间为 2*l/v  然后将这一步时间 替换 原本的 l 最后的结果就出来了ans=d  ans-=l  ans+=2.0*l/v就是 这一思想的体现
int main()
{
    int n,d;
	double ans;
	int p,l,v;
	int caseNum;
	caseNum=0;
	while(scanf("%d%d",&n,&d),n!=0||d!=0)
	{
		++caseNum;
         ans=d;
		 while(n--)
		 {
			 scanf("%d%d%d",&p,&l,&v);
			 ans-=l;
			 ans+=2.0*l/v;
		 }
		 printf ("Case %d: %.3lf\n\n",caseNum,ans);
	}
	return 0;
}
