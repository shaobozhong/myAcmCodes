#include <stdio.h>
#include <stdlib.h>
 
const int maxn = 20003;
int n, tree_last;
unsigned w, h, data[maxn][4], tree[maxn][4];
 
bool input() {
	if (scanf("%d%u%u", &n, &w, &h) == EOF)
		return false;
	for (int i = 1; i <= n; ++i) {
		scanf("%u%u%u", &data[(i<<1)-1][0], &data[(i<<1)-1][1], &data[(i<<1)-1][2]);
		data[i<<1][0] = data[(i<<1)-1][0];
		data[i<<1][1] = data[(i<<1)-1][1] + h;
		data[i<<1][2] = -data[(i<<1)-1][2];
	}
	n <<= 1;
	--w, --h;
	return true;
}
 
int comp_x(unsigned x[], unsigned y[]) {
	return x[0]!=y[0] ? (x[0]<y[0]?-1:1) : (x[1]==y[1]?0:(x[1]<y[1]?-1:1));
}
 
int comp_y(unsigned x[], unsigned y[]) {
	return x[1]!=y[1] ? (x[1]<y[1]?-1:1) : (x[2]==y[2]?0:(x[2]>y[2]?-1:1));
}
 
int build_tree(int t) {
	int left = t << 1;
	int right = left + 1;
	if (left <= n)
		build_tree(left);
	data[++tree_last][3] = t;
	tree[t][0] = data[tree_last][2];
	tree[t][1] = tree[t][2] = 0;
	tree[t][3] = 0;
	if (right <= n)
		build_tree(right);
	return 0;
}
 
int max(int x, int y) {
	return x > y ? x : y;
}
 
void tree_update(int t) {
	int left = t << 1, right = (t << 1) + 1;
	left = left > n ? 0 : left;
	right = right > n ? 0 : right;
	tree[t][2] = tree[t][1] + tree[left][2] + tree[right][2];
	tree[t][3] = max(tree[left][3], tree[t][2] - tree[right][2]);
	tree[t][3] = max(tree[t][3], tree[t][2] - tree[right][2] + tree[right][3]);
	if (t > 1)
		tree_update(t >> 1);
}
 
void tree_insert(int w) {
	tree[w][1] = tree[w][0];
	tree_update(w);
}
 
void tree_delete(int w) {
	tree[w][1] = 0;
	tree_update(w);
}
 
int work() {
	qsort(data[1], n, sizeof(int) * 4, (int(*) (const void*, const void*)) comp_y);
	tree_last = 0;
	build_tree(1);
	tree[0][0] = tree[0][1] = tree[0][2] = tree[0][3] = 0;
	qsort(data[1], n, sizeof(int) * 4, (int(*) (const void*, const void*)) comp_x);
	int res = 0, line1 = 0, line2 = 0;
	while (line2 < n) {
		do {
			tree_insert(data[++line2][3]);
		} while (data[line2][0] == data[line2+1][0]);
		while (data[line2][0] - data[line1+1][0] > w) {
			tree_delete(data[++line1][3]);
		}
		res = max(res, tree[1][3]);
	}
	return res;
}
 
int main() {
	while (input())
		printf("%d\n", work());
	return 0;
}