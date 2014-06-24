#include <iostream>
using namespace std;

int main()
{
	int n, r;
	
	while (cin >> n)
	{
		r = n * n;
		for (int i = 1; i != n; ++i) 
			r += (i + 1) * i / 2;
		for (int i = 2; i <= n / 2; ++i)
		{
			for (int j = i; j != n; ++j)
			{
				if (j + i > n) 
					break;
				r += j - i + 1;
			}
		}
		cout << r << endl;
	}
	return 0;
}
