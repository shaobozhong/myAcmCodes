#include<iostream>
#include<string>
#include<set>
using namespace std;

int c[101][101];
int r[101][101];
string a,b,str;
int m,n;
set<string> res;

void work(int i,int j,int _count)
{
	char temp[2];
	if (_count==0) {res.insert(str);return;}
	if (c[i][j]==0) return;
	if (i<_count||j<_count) return;
	if (r[i][j]==1) 
	{
		temp[1]='\0';
		temp[0]=a[i-1];
		str.insert(0,temp);
		work(i-1,j-1,_count-1);
		str.erase(0,1);
		return;
	}
	if (r[i][j]==2)
	{
		work(i-1,j,_count);
	}
	else 
	{
		if (r[i][j]==3)
		{
			work(i,j-1,_count);
		}
		else 
		{
			work(i-1,j,_count);
			work(i,j-1,_count);
		}
	}

}
int main()
{
    int t,i,j;
	set<string>::iterator k;
	scanf("%d",&t);
	while (t--)
	{
		res.clear();
		str="";
		cin>>a;
		cin>>b;
		m=(int)a.size();
		n=(int)b.size();
		for (i=1;i<=m;++i)
		{
            c[i][0]=0;
		}
		for (i=1;i<=n;++i)
		{
			c[0][i]=0;
		}
		for (i=1;i<=m;++i)
		{
			for (j=1;j<=n;++j)
			{
				if (a[i-1]==b[j-1])
				{
					c[i][j]=c[i-1][j-1]+1;
					r[i][j]=1;//最后匹配上了
				}
				else 
				{
					c[i][j]=c[i-1][j];
					if (c[i-1][j]==c[i][j-1]) 
					{
						r[i][j]=4;// 两个方向来
					}
					else
					{
						if (c[i][j]<c[i][j-1])
						{
							c[i][j]=c[i][j-1];
							r[i][j]=3;//j-1来
						}
						else
						{
							r[i][j]=2;//i-1来
						}
					}
				}
			}
		}
		//cout<<c[m][n]<<endl;
		if (c[m][n]==0) {puts("NO matching");continue;}
		work(m,n,c[m][n]);
        for (k=res.begin();k!=res.end();++k)
        {
			cout<<(*k)<<endl;
        }
	}
	return 0;
}