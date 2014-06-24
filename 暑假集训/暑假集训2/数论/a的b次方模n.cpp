#include<iostream>
using namespace std;

int modExp(int a,int b,int n)//该算法  实现了将b往里放的一个过程 利用了  a^c=(a^b)^d b*d==c
{
	int t,y;
	t=1;
	y=a;
	while(b!=0)
	{
		if (b%2==1) t=(t*y)%n;
		y=(y*y)%n;
		b=b/2;
	}
	return t;
}

int main()
{
	int a,b,n;
	int k;
	cin>>k;
	while(k--)
	{
		cin>>a>>b>>n;
		cout<<modExp(a,b,n)<<endl;
	}
	return 0;
}

/*不知道为什么这个快些
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,k,i;
	cin>>a>>b>>c;
	for(i=k=1;i<=b;i++)//递推
		k=k*a%c;
	cout<<k<<endl;
	return 0;
}
*/