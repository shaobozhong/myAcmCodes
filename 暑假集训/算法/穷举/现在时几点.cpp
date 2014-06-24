#include<iostream>
#include<string>
using namespace std;
int xf;
int state=0;

void code(char s[][100],int num[][8])
{
	int temp,i,k;
	int count=1,la,j=0;
	while(j<=24)
	{
		la=1;
		if (j==12) j++;
		for(i=1;i<=3;i++)
		{   
			k=j; 
			temp=j;
			for(;k<=temp+2;k++)
			{  
				if (i==1) {k++;}
				if (s[i][k]!=' ') num[count][la++]=1;
				else num[count][la++]=0;
				if (i==1) k++;
		 }
		}
		j=k;
		count++;
	}
}

bool sindex(int num[][8],int data[][7],int i,int loca)//小匹配 判断是否能为此数 能返回FALSE
{
	int j;
	for(j=0;j<=6;j++)
	{
		if (data[i][j]&&num[loca][j+1]==1) {return true;}
	}
	return false;
}

bool nindex(int h1,int h2,int m1,int m2,int num[][8],int data[][7])//判断后面得那个能否与这个匹配
{
	int h3=h1,h4=h2,m3=m1-1,m4=m2-5;
	if (m4<0) 	{m3--;m4+=10;}
	if (m3<0) {h4--;m3+=6;}
	if (h4<0) {h3--;h4=9;}
	if (h3<0)  {h3=2;h4=3;}
	if (sindex(num,data,h3,5)) return false; 
	if (sindex(num,data,h4,6)) return false;
	if (sindex(num,data,m3,7)) return false;
	if (sindex(num,data,m4,8)) return false;
	return true;
}
void index(int num[][8])
{ int h3,h4,m3,m4;
int data[10][7]={{0,0,1,0,0,0,0},{1,1,1,0,1,1,0},{0,1,0,0,0,0,1},{0,1,0,0,1,0,0},{1,0,0,0,1,1,0},{0,0,0,1,1,0,0},{0,0,0,1,0,0,0},{0,1,1,0,1,1,0},{0,0,0,0,0,0,0},{0,0,0,0,1,0,0}};//存补码
int h1,h2,m1,m2;
for(h1=0;h1<=2&&xf!=2;h1++)
{
	if (sindex(num,data,h1,1)) continue;
	for(h2=0;h2<=9&&xf!=2;h2++)
	{
		if (h1==2&&h2>4) break;
		if (sindex(num,data,h2,2)) continue;
		for(m1=0;m1<=5;m1++)
		{
			if (sindex(num,data,m1,3)) continue;
			for(m2=0;m2<=9&&xf!=2;m2++)
			{
				if (sindex(num,data,m2,4)) continue;
				if (nindex(h1,h2,m1,m2,num,data)) {h3=h1;h4=h2;m3=m1;m4=m2;xf++;}
			}
		}
	}
}

if (xf==2) cout<<"Not Sure"<<endl;
else cout<<h3<<h4<<m3<<m4<<endl;
}

int main()
{
	char s[5][100];
	int num[9][8];
	int n;
	cin>>n;
	getchar();
	for(;n>=1;n--)
	{
		xf=0;
		gets(s[1]);
		gets(s[2]);
		gets(s[3]);
		//cout<<s[1]<<endl<<s[2]<<endl<<s[3]<<endl;
		code(s,num);	
		index(num);
		xf=0;
	}
	return 0;
}		