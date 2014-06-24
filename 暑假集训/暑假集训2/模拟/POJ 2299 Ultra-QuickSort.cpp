#include<iostream>
using namespace std;

int a[500001];
int temp[500001];
__int64 count1;

void merge(int leftPos,int rightPos,int rightEnd)
{
	int leftEnd=rightPos-1;
	int tmpPos=leftPos;
	int numElements=rightEnd-leftPos+1;
    int i;
	while(leftPos<=leftEnd && rightPos<=rightEnd)
	{
		if (a[leftPos]<=a[rightPos])
		{
			count1+=rightPos-leftEnd-1;
			temp[tmpPos++]=a[leftPos++];
		}
		else 
		{
			temp[tmpPos++]=a[rightPos++];
		}
	}

	if (leftPos<=leftEnd)
	{
		count1+=(leftEnd-leftPos+1)*(rightEnd-leftEnd);
	}

	while(leftPos<=leftEnd)
	{
       temp[tmpPos++]=a[leftPos++];
	}

	while(rightPos<=rightEnd)
	{
		temp[tmpPos++]=a[rightPos++];
	}

	for(i=0;i<numElements;++i,rightEnd--)
	{
		a[rightEnd]=temp[rightEnd];
	}

}

void mergesort(int left,int right)
{
	int center;
	if (left<right)
	{
		center=(left+right)/2;
        mergesort(left,center);
		mergesort(center+1,right);
		merge(left,center+1,right);
	}
}
int main()
{
	int n;
	int i;
	//freopen("2299(1).in","r",stdin);
	while(cin>>n,n!=0)
	{
		count1=0;
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		mergesort(0,n-1);
		printf("%I64d\n",count1);
	}
	return 0;
}