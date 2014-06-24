#include<iostream>
using namespace std;
int a[16]={63624,62532,61986,61713,36744,20292,12066,7953,35064,17652,8946,4593,34959,17487,8751,4383};//翻i-1的情况
int init[16]={32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};//存储1 到16 的初始化

const int num=65535;//这个数代表16个1
int minstep;
bool r[16],b[16];
void work(int state,int i,int tstep)
{
	if (tstep>minstep) return;
	if (i==16)
	{
		//state=state&num;
		if (state==0 && tstep<minstep) 
		{
			minstep=tstep;
			for(i=0;i<16;++i)
			{
				r[i]=b[i];
			}
		}
		return;
	}
	b[i]=true;
	work(state^a[i],i+1,tstep+1);
	b[i]=false;
	work(state,i+1,tstep);
}
int main()
{
	int first,second;
	char ch;
	int i;
	int state;//棋盘状态
	state=0;
	minstep=INT_MAX;
	memset(r,false,sizeof(r));
	memset(b,false,sizeof(b));
	for(i=0;i<16;++i)
	{
		cin>>ch;
		if (ch=='+')  state|=init[i];
	}
	work(state,0,0);
	//if (minstep==INT_MAX) {puts("error");continue;}
	cout<<minstep<<endl;
	for(i=0;i<16;++i)
	{
		if (r[i]) 
		{
			if ((i+1)%4!=0) first=(i+1)/4+1;
			else first=(i+1)/4;
			second=i-(first-1)*4+1;
			cout<<first<<" "<<second<<endl;
		}
	}
	return 0;
}