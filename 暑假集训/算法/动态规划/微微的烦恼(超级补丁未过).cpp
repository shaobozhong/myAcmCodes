#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const int  &a,const int &b)
{
	return a<b;
}

int main()
{
	int a[2001];
	bool sign,bridge[2001];
	int n,k,left,right,lable,result,i,j,rleft,rright,max,temp,tj,min,ti;
	while(cin>>n>>k)
	{
		memset(bridge,false,sizeof(bridge));
		left=0;
		right=n-1;
		lable=0;
		for(i=0;i<=n-1;i++)
			cin>>a[i];
		sort(a,a+n,cmp);
		for(i=1;i<=n-2*k;i++)
		{
			sign=false;
			rleft=a[left+1]-a[left];
            rright=a[right]-a[right-1];
	     	max=rleft>rright? rleft: rright;
			for(j=lable;j<=right-1;j++)
			{
				temp=a[j+1]-a[j];
				if(temp>=max&&bridge[j]==false) {max=temp;tj=j;sign=true;}
			}
            if (sign) 
			{
                if (j%2==0) left++;
				else 
					bridge[tj]=true;
			}
			
			else  
			{
				if (rleft>rright) left++;
				else right--;
			}
		}
        result=0;
		tj=1;
		for(tj=1;tj<=k;tj++)
		{ 
			min=10000;
			for(i=left;i<=right-1;i+=2)
			{
				if (bridge[i]) {i--;continue;}
				temp=a[i+1]-a[i];
				if (min>temp) {min=temp;ti=i;}
			}
			 bridge[ti]=true;
             bridge[ti+1]=true;
			 result+=min*min;
		}
		cout<<result<<endl;
	}
	return 0;
}