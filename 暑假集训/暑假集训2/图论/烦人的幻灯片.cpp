#include<iostream>
using namespace std;


struct Powerpoint//以区域来保存幻灯片 和他可能对应的数字 
{
	int x1,y1,x2,y2;//区域的对顶点坐标
	struct Powerpoint *next;//保存可能对应的数字 链表
	int count1;// 个数
};


int main()
{

	int i,j,k,x,y;
	Powerpoint *p,*q;
	bool res;
	int n,count2;
	int ppt;
	res=true;
	cin>>n;
	p=new Powerpoint[n];
	for(i=0;i<n;++i)
	{
		cin>>p[i].x1>>p[i].x2>>p[i].y1>>p[i].y2;
		p[i].count1=0;
		p[i].next=NULL;
	}

	for(i=1;i<=n;++i)//建立可能的对应关系
	{
		cin>>x>>y;
		for(j=0;j<n;++j)
		{
			if (x>=p[j].x1&&x<=p[j].x2 && y>=p[j].y1&&y<=p[j].y2) 
			{
				q=new Powerpoint;
				q->count1=i;
				q->next=p[j].next;
				p[j].next=q;
				p[j].count1++;
			}
		}
	}

    //寻找n-1次 若是找到了 n-1个能确定的 就能够确定
	for(i=1;i<=n-1;++i)
	{
		for(j=0;j<n;++j)
		{
			if (p[j].count1==0) {res=false;break;}//有没有能对应的  不行
		}
		if (!res) break;

		for(j=0;j<n;++j)
		{
			if (p[j].count1==1) break;// 唯一对应的就确定下来 同时在其他的区域中删除这个数字
		}
		if (j>=n) {res=false;break;}
		ppt=p[j].next->count1;
		
		for(k=0;k<n;++k)
		{
			if (k!=j)
			{
				count2=0;
				q=&p[k];
				while(q->next)
				{
					count2++;
					if (q->next->count1==ppt)
					{
						q->next=q->next->next;break;
					}
					q=q->next;
				}
				if (count2<p[k].count1) --p[k].count1;//若是找到了要删除的数
			}
		}
	}


	if (!res) {puts("None");return 0;}

	for(i=0;i<n;++i)
	{
		printf("%c %d\n",i+65,p[i].next->count1);
	}

	return 0;
}