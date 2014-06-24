#include<iostream>
using namespace std;
int a[16]={51200,58368,29184,12544,35968,20032,10016,4880,2248,1252,626,305,140,78,39,19};//翻i-1的情况
int init[16]={32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};//存储1 到16 的初始化

int minstep;
void work(int state,int i,int tstep)
{
	if (tstep>minstep) return;
	if (i==16)
	{
		//state=state&num;
		if ((state==0||state==65535) && tstep<minstep) 
		{
			minstep=tstep;
		}
		return;
	}
	work(state^a[i],i+1,tstep+1);
	work(state,i+1,tstep);
}
int main()
{
	char ch;
	int i;
	int state;//棋盘状态
	state=0;
	minstep=INT_MAX;
	for(i=0;i<16;++i)
	{
		cin>>ch;
		if (ch=='b')  state|=init[i];
	}
	work(state,0,0);
	if (minstep==INT_MAX) {puts("Impossible");return 0;}
	cout<<minstep<<endl;
	return 0;
}
