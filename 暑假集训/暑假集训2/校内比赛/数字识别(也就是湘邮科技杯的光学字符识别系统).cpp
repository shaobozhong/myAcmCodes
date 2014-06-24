/*段位的对应关系
算法分析：没用什么算法，主要就是二进制 表示7段  然后分情况去讨论
这个题 代码不短快 200行了 但是一遍就过了  很是自豪

  1
  _ 
2|_|6      中间的那一段是7
3|_|5 
4
*/
#include<iostream>
using namespace std;
int w[7]={64,32,16,8,4,2,1};//1-7段  对应的二进制转换成10进制
int bin[10]={126,6,91,79,39,109,125,70,127,111};//用二进制表示0-9 10个数字

int a[9];//存储9位数位上的信息
int d[9];//存储9位数位上10进制表示的信息
int res[9];//存储唯一的结果

void init()//输入函数
{
	char ch[3];
	int i;
	for(i=0;i<9;++i)
	{
		a[i]=0;
	}

	cin>>ch[1]>>ch[2];
	if (ch[1]=='_') a[0]|=w[0];
	for(i=1;i<9;++i)
	{
		cin>>ch[0]>>ch[1]>>ch[2];
		if (ch[1]=='_') a[i]|=w[0];
	}//之前是第一行的输入 并且只可能对1位置产生影响  只有输入的2位置可能为_

	for(i=0;i<9;++i)
	{
		cin>>ch[0]>>ch[1]>>ch[2];
		if (ch[0]=='|') a[i]|=w[1];
		if (ch[1]=='_') a[i]|=w[6];
		if (ch[2]=='|') a[i]|=w[5];
	}//读第二行 根据顶上的图来改变a【i】的值

	for(i=0;i<9;++i)
	{
		cin>>ch[0]>>ch[1]>>ch[2];
		if (ch[0]=='|') a[i]|=w[2];
		if (ch[1]=='_') a[i]|=w[3];
		if (ch[2]=='|') a[i]|=w[4];
	}//读第三行
}

int find1(int num)
{
	int i;
	for(i=0;i<10;++i)
	{
		if (num==bin[i]) return i;
	}
	return -1;
}

bool judge1(int *ar)
{
	int sum;
	int i;
	sum=0;
	for(i=8;i>=0;--i)
	{
		sum+=(9-i)*ar[i];
	}
	if (sum%11==0) return true;
	return false;
}

int judge2(int loc)
{
	int temp[9];
	int i,j;
	int num;
	int count1;
	count1=0;
	for(i=0;i<7;++i)
	{
		if ((a[loc]&w[i])==0) 
		{
			num=find1(a[loc]|w[i]);
			if (num==-1) continue;
			for(j=0;j<9;++j)
			{
				temp[j]=d[j];
			}
			temp[loc]=num;
			if (judge1(temp)) 
			{
				count1++;
				if(count1==1)
				{
					for(j=0;j<9;++j)
					{
						res[j]=temp[j];
					}
				}
				if (count1==2) break;
			}
		}
	}
	return count1;
}

int judge3()
{
	int i;
	int count1;
	count1=0;
	for(i=0;i<9;++i)
	{
		count1+=judge2(i);
		if (count1>=2) {count1=2;break;} 
	}
	return count1;
}

void work()
{
	int i;
	int count1;
	int loc;
	count1=0;
	for(i=0;i<9;++i)
	{
		d[i]=find1(a[i]);
		if (d[i]==-1) 
		{
			loc=i;
			++count1;
			if (count1==2) break;
		}
	}

	if (count1>=2)//有两个以上无法正常表示
	{
		puts("failure"); return;
	}
	else if (count1==0)
	{
		if (judge1(d))//判断能否满足表达式
		{
			for(i=0;i<9;++i)
			{
				cout<<d[i];
			}
			cout<<endl;
		}
		else 
		{
			switch(judge3())//当需要对所有位进行穷举时进行的判断
			{
			case 0:puts("failure"); return;
			case 1:
				{
					for(i=0;i<9;++i)
					{
						cout<<res[i];
					}
					cout<<endl;
					return;
				}
			case 2:puts("ambiguous");return;
			}
		}
	}
	else//有一个是无法表示数字的
	{
		switch(judge2(loc))//对一位数进行的穷举判断
		{
		case 0:puts("failure"); return;
		case 1:
			{
				for(i=0;i<9;++i)
				{
					cout<<res[i];
				}
				cout<<endl;
				return;
			}
		case 2:puts("ambiguous");return;
		}
	}


}


int main()
{
	char ch;//读第一个字符  一定是. 所以可以不管
	while(cin>>ch)
	{
		init();//输入
		work();//处理过程
	}
	return 0;
}