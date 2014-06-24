#include<iostream>
using namespace std;

long long  a[6000];

void build()
{
	int index[5]={0},prime[5]={2,2,3,5,7};
	int tj,i,j;
	long long min,temp;
	/*for(i=0;i<=5842;i++)
	{
		a[i]=0;
	}*/
	a[1]=1;
    for(i=2;i<=5842;i++)
	{
		while(a[i]<=a[i-1])
		{
			tj=1;
			min=2000000001;
			for(j=1;j<=4;j++)
			{
				temp=prime[j]*a[index[j]];
				if (temp<min) {min=temp;tj=j;} 
			}
			index[tj]++;
			a[i]=min;
		}
	}
}

int main()
{
	int n;
	build();
	while(cin>>n,n!=0)
	{
		cout<<"The ";
		switch(n%10)
		{
		case 1:
			{
				if (n%100!=11) cout<<n<<"st humble number is ";
			   else  
				   cout<<n<<"th humble number is ";
				   break;
			}
		case 2:
			{
				if (n%100!=12) cout<<n<<"nd humble number is ";
				else cout<<n<<"th humble number is ";
				break;
			}
		case 3:
			{
				if (n%100!=13) cout<<n<<"rd humble number is ";
			   else cout<<n<<"th humble number is ";
			break;
			}
		default :cout<<n<<"th humble number is ";
		}
		cout<<a[n]<<'.'<<endl;
	}

	return 0;
}

/*哈姆伯数的规律
只需考虑temp=prime[j]*a[index[j]];
*/
