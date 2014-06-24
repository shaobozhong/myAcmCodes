#include <stdio.h>

#include <string.h>




int son[205][205], unique[205][2], ans[205][2], last, flag;

char name[205][205];



int get_id(char str[])

{

	int i;

	for (i = 0; i < last; i++)

	{

		if(strcmp(name[i],str) ==0)

		{

			return i;

		}

	}

	//从来没有出现过就存储在name中

	if (i == last)

	{

		strcpy(name[i], str);

		last++;

		return i;

	}

	return 0;

}



void dfs(int father)

{

	int i, sum, temp;
	int max1;
	sum = son[father][0];

	for (i = 1; i <= sum; i++)

	{

		temp = son[father][i];

		dfs(temp);

		//状态转移方程

		ans[father][1] += ans[temp][0];
		max1=ans[temp][0];
		if (max1<ans[temp][1]) max1=ans[temp][1];

		ans[father][0] +=max1;

		//唯一性的考虑

		if (ans[father][0] == ans[father][1] && ans[temp][0] == ans[temp][1])

		{

			flag = 0;

		}

	}

}



int main()

{

	int i, n, a, b;
	char str[105], eme[105], boss[105];
	while (scanf("%d", &n)&&n)
	{
		last = 0;
		flag = 1;
		for (i = 0; i < n; i++)
		{
			ans[i][1] = 1;
			ans[i][0] = 0;
		}
		memset(son, 0, sizeof(son));
		memset(name, '\0', sizeof(name));
		memset(unique, 1, sizeof(unique));
		scanf("%s", str);
		get_id(str);
		//用son保存数据,即用到链表的形式。
		for (i = 1; i < n; i++)
		{
			scanf("%s%s", eme, boss);
			a = get_id(eme);     
			b = get_id(boss);
			son[b][++son[b][0]] = a;      
		}
		dfs(0);
		if (ans[0][0] > ans[0][1])
		{
			printf("%d %s\n", ans[0][0], flag ? "Yes" : "No");
		}
		else if (ans[0][0] < ans[0][1])       
		{
			printf("%d %s\n", ans[0][1], flag ? "Yes" : "No");

		}
		else
		{
			printf("%d No\n", ans[0][0]);
		}
	}

	return 0;

}
