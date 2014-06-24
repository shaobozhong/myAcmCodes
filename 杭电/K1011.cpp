#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[100];
	int i,count;
	bool t;
	double sum;
	while(gets(s))
	{
		t=false;
		count=0;
		sum=0;
		for(i=0;i<=strlen(s)-1;i++)
		{
			switch(s[i])
			{
			case 'A':sum+=4;break;
			case 'B':sum+=3;break;
			case 'C':sum+=2;break;
			case 'D':sum+=1;break;
			case 'F':break;
			case ' ':break;
			default: cout<<"Unknown letter grade in input"<<endl;t=true;
			}
			if(t) break;
			if (s[i]!=' ') count++;
		}
		if (i>strlen(s)-1) printf("%.2f\n",sum/count);
	}
	return 0;
}