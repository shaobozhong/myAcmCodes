#include<iostream>
using namespace std;
int comp(const void *p1,const void *p2)
{
	return *((int *)p2) - *((int *)p1);
}

int main()
{
	int i,j,k,m,n,t,tt,sum,t1,c,d,T,Catkse=0;
	int *atk,*b;
	cin>>T;
	while(T--)
	{
		Catkse++;
		cin>>n;
		k=m=0;
		sum=0;
		atk=new int[n+1];
		b=new int[n+1];
		t1=n;
		for(i=0;i<n;i++)
			cin>>*(atk+i);
		qsort(atk,n,sizeof(atk[0]),comp);
		for(i=0;i<n;i++)
			cin>>*(b+i);
		qsort(b,n,sizeof(b[0]),comp);    
		i=0;
		j=0;
		c=n-1;d=n-1;
		while(n--)    
		{
			if(atk[i]>=b[j]) m++,i++,j++;  
			else if(atk[i]<=b[j]) k++,j++,c--; 
			else
			{
				if(atk[c]>=b[d]) m++,c--,d--;
				else if(atk[c]<=b[d]) k++,c--,j++;
				else
				{
					if(atk[c]<=b[j]) k++;    
					c--;
					j++;
				}
			}
		}
		cout<<"Case "<<Catkse<<": "<<m<<endl;
		//cout<<m<<endl;
	}
	return 0;
}
