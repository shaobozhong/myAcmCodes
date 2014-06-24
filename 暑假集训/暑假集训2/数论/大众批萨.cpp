#include<iostream>
#include<vector>
using namespace std;


struct Taste
{
	int want,hate;
};

vector<Taste> t;
bool la;
int res;
void work(int i,int pizaid)
{
	int j;
	if (la) return;
	if (i>15)
	{
		for(j=0;j<int(t.size());++j)
		{
			if (((pizaid & t[j].want)<=0)&& ((~pizaid & t[j].hate)<=0)) return;
		}
		la=true;
		res=pizaid;
		return;
	}
	work(i+1,pizaid);
	pizaid+=(1<<i);
	work(i+1,pizaid);
	pizaid-=(1<<i);
}

int main()
{
	bool vis1[16],vis2[16];
	int num;
	Taste tt;
	int a[16];
	int temp,i;
	char ch;
	int k;
	while(cin>>ch)
	{
		
		res=-1;
		la=false;
		t.clear();
		while(1)
		{
			tt.want=0;tt.hate=0;
			for(i=0;i<16;++i)
			{
				vis1[i]=true;
			}

			for(i=0;i<16;++i)
			{
				vis2[i]=true;
			}

			while(ch!=';')
			{
				if (ch=='+')
				{
					cin>>ch;

					if (vis1[int(ch)-65]) 
					{
						temp=1;
						temp=temp<<(15-(int(ch)-65));
						tt.want+=temp;
						vis1[int(ch)-65]=false;
					}
				}
				else 
				{
					if (ch=='-')
					{
						cin>>ch;

						if (vis2[int(ch)-65]) 
						{
							temp=1;
							temp=temp<<(15-(int(ch)-65));
							tt.hate+=temp;
							vis2[int(ch)-65]=false;
						} 
					}
				}
				cin>>ch;
			}
			t.push_back(tt);
			cin>>ch;
			if (ch=='.') break;

		}
		work(0,0);
		if (res==-1) puts("No pizza can satisfy these requests.");
		else 
		{
			if (res==0) {puts("Toppings: ");continue;}
			else printf("Toppings: ");
			for(i=0;i<16;++i)
			{
				a[i]=0;
			}
			num=0;
			while(res)
			{
				if (res%2) a[num]=80-num;
				num++;
				res/=2;
			}
			for(i=15;i>=0;--i)
			{
				if (a[i]) putchar(a[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}