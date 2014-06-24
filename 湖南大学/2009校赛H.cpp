//time=828ms
#include <iostream>
using namespace std;

#define MAXN 1000005


int a[MAXN], n;
int s[MAXN], top;
int l[MAXN], r[MAXN];
void solve() {
	int i;
	top = -1;
	i = 0;
	while (i < n) {
		if (top == -1 || a[s[top]] >= a[i]) s[++top] = i++;
		else {
			l[s[top]] = i - s[top];
			top--;
		}
	}
	top = -1;
	i = n + 1;
	while (i >= 0) {
		if (top == -1 || a[s[top]] >= a[i]) s[++top] = i--;
		else {
			r[s[top]] = s[top] - i;
			top--;
		}
	}

}


int main() {
	int i;
	__int64 res;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			l[i] = r[i] = n;
		}
		solve();
	    res = 0;
		for (i = 0; i < n; i++) {
			if (l[i] != n || r[i] != n)
			{
				if (l[i]<=r[i]) res+=l[i];
				else res+=r[i];
			}
			else res+=n;
		}
		printf("%.2f\n", (double)res / n);
	}
	return 0;
}
