#include<iostream>
using namespace std;

typedef struct 
{
	char name[20];
	float *score;
	float rpin;
}student;

typedef struct
{
	char major[20];
	float pin;
}Major;

int main()
{
	int i,n,m;
	student *p;
	Major *m1;
	scanf("%d%d",&n,&m);
	m1=new Major[m];
	for(i=0;i<=m-1;i++)
		scanf("%s",m1+i);
	p=new student[n];
	for(i=0;i<=m-1;i++)
		m1[i].pin=0;
	for(i=0;i<=n-1;i++)
	{
		scanf("%s",p[i].name);
		p[i].score=new float[m];
		p[i].rpin=0;
		for(int j=0;j<=m-1;j++)
		{
			scanf("%f",&p[i].score[j]);
			m1[j].pin+=p[i].score[j];
			p[i].rpin+=p[i].score[j];
		}
		(p[i].rpin)/=m;
	}


	for(i=0;i<=n-1;i++)
	{
		printf("%s\n%.2f\n",p[i].name,p[i].rpin);
	}


	for(i=0;i<=m-1;i++)
		printf("%s\n%.2f\n",m1[i].major,(m1[i].pin)/n);
	return 0;
}