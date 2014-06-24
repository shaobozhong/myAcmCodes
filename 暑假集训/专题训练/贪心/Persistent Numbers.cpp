#include<iostream>
#include<list>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;

//高精度带余除法，除数为一位数
int Divide(list<int>& a,int b)
{
	int r;
	list<int>::iterator i=a.begin();
	list<int>::iterator j=a.begin();
	while(++i!=a.end())
	{
		*i+=*j%b*10;
		*j/=b;
		j++;
	}
	r=*j%b;
	*j/=b;
	i=a.begin();
	while(i!=a.end()&&*i==0)
		i++;
	a.erase(a.begin(),i);
	return r;
}

int main()
{
	while(true)
	{
		char c=getchar();
		if(c=='-')
			break;
		list<int> num;
		int counter[10];
		memset(counter,0,10*sizeof(int));
		num.push_back(c-'0');
		while((c=getchar())!='\n')
			num.push_back(c-'0');
		//第一步Persistent Number在10以内的，加10即可
		if((++num.begin())==num.end())
		{
			cout<<*num.begin()+10<<endl;
			continue;
		}
		//判定2的因子数
		while(*(--num.end())%2==0)
		{
			counter[2]++;
			Divide(num,2);
		}
		//判定5的因子数
		while(*(--num.end())%5==0)
		{
			counter[5]++;
			Divide(num,5);
		}
		//判定3的因子数
		list<int>::iterator i=num.begin();
		while(true)
		{
			int sum=0;
			i=num.begin();
			while(i!=num.end())
			{
				sum+=*i;
				i++;
			}
			if(sum%3)
				break;
			counter[3]++;
			Divide(num,3);
		}
		//判定7的因子数
		int r;
		while((r=Divide(num,7))==0)
			counter[7]++;
		//r=1并且num变为0，说明数字可以分解成1位数的连乘积
		if(r==1&&num.empty())
		{
			counter[8]=counter[2]/3;
			counter[2]%=3;
			counter[9]=counter[3]/2;
			counter[3]%=2;
			if(counter[3]>0&&counter[2]>0)
			{
				counter[6]++;
				counter[3]--;
				counter[2]--;
			}
			counter[4]=counter[2]/2;
			counter[2]%=2;
			for(int k=2;k<10;k++)
				for(int m=0;m<counter[k];m++)
					cout<<k;
			cout<<endl;
		}
		else
			cout<<"There is no such number."<<endl;//否则不能
	}
	return 0;
}

/*小数
#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<char>::iterator j;
	list<char>s;
	int n,i;
	while(cin>>n&&n!=-1)
	{	
		i=0;
		if (n<10) {cout<<"1"<<n<<endl;continue;}
		while(n!=1&&i!=1)
		{
			for(i=9;i>=2;i--)
			{
				if (n%i==0) 
				{
					s.push_front(i+'0');n/=i;break;
				}
			}   
			if (i==1) {cout<<"There is no such number."<<endl;s.clear();break;}
		}
		if (i==1) continue;
		for(j=s.begin();j!=s.end();j++)
		{
			cout<<*j;
		}
		cout<<endl;
		s.clear();
	}
}*/