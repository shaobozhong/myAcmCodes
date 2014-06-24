#include<stdio.h>
#include<string.h>


int SafeStrcpy2KeyWord(char* pDestBuffer,	//源字符串
					   char* pSourceString,	//目的字符串
					   int nDestBufferSize,	//缓冲区长度
					   char* szKeyWord)	//指定键字符串
{
	int i,j,keylen;
	if (strcmp(szKeyWord,"NULL")==0) {return 0;}
	keylen=(int)strlen(szKeyWord);
	for(i=0;i<nDestBufferSize;i++)
	{
		for(j=0;j<keylen;j++)
		{
			if (pDestBuffer[i+j]!=szKeyWord[j]) break;
		}
		if (j>=keylen) break;
	}
	if (i==0) {strcpy(pSourceString,"NULL");return 0;}
	else 
	{
		if (i>=nDestBufferSize)  
		{
			strcpy(pSourceString,pDestBuffer);
			return nDestBufferSize;
		}

		for(j=0;j<i;j++)
		{
			pSourceString[j]=pDestBuffer[j];
		}
		pSourceString[j]='\0';
		return i;
	}
	return 0;
}

int main()
{
	int loca;
	char pDestBuffer[300],szKeyWord[20],pSourceString[300];

	while(scanf("%s",pDestBuffer)!=EOF)
	{
		while(scanf("%s",szKeyWord)!=EOF&&strcmp(szKeyWord,"END")!=0)
		{
			loca=SafeStrcpy2KeyWord(pDestBuffer,pSourceString,(int)strlen(pDestBuffer),szKeyWord);
			if (loca==0) printf("0 NULL\n");
			else 
			{
				printf("%d %s\n",loca,pSourceString);
			}
		}
	}
	return 0;
}