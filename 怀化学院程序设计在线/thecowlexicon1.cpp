#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 310, M = 610, L = 30;

char _dic[M][L];
char _str[N];
int _dp[N];

int DP(int n, int m) {
	int i, j, k, l;
	for (i = 0; i < n; ++i) _dp[i] = i + 1;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			for (k = i, l = 0; k < n; ++k) {
				if (_str[k] == _dic[j][l]) {
					if (!_dic[j][++l]) break;
				}
			}
			if (_dic[j][l]) continue;

			// note here, this sentence may not be excuted, 
			// it shall be placed out of the loop
			// if (i) _dp[i] = min(_dp[i], _dp[i - 1] + 1);

			_dp[k] = min(_dp[k], (i ? _dp[i - 1] : 0) + k - i - l + 1);
		}
		_dp[i + 1] = min(_dp[i + 1], _dp[i] + 1);
	}
	return _dp[n - 1];
}

int main() {
	int n, m;
	scanf("%d%d\n", &m, &n);
	gets(_str);
	for (int i = 0; i < m; ++i) {
		gets(_dic[i]);
	}
	printf("%d\n", DP(n, m));
	return 0;
}
