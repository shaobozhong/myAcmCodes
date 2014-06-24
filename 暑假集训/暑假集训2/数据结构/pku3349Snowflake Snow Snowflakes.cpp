/*hash基础题，虽然有几个hash噶模板，不过仲系自己写下，对比岩岩个条，呢条就系水题了。

不过发现左一样好重要噶野：用cin cout 噶时间比 scanf printf 多出差唔多1000ms 所以TLE左几次都唔知咩事

代码如下：
*/
 

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int N = 9997;//足够大的素数

typedef struct {
    int a[6];
    long sum;
} Node;
vector<Node> vec[N];//hash节点可以用vector而唔一定用链表

int Compare(Node n1, Node n2) {
    int i, j;
    for (i = 0; i < 6; i++) {
        if (n1.a[0] == n2.a[i]) {
            for (j = 1; j < 6; j++) {
                if (n1.a[j] != n2.a[(i + j) % 6])
                    break;
            }
            if (j == 6) return 1;
            for (j = 1; j < 6; j++) {
                if (n1.a[6 - j] != n2.a[(i + j) % 6])
                    break;
            }
            if (j == 6) return 1;
        }
    }
    return 0;
}

int check() {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < vec[i].size(); j++) {
            for (k = j + 1; k < vec[i].size(); k++) {
                if (vec[i][j].sum == vec[i][k].sum && Compare(vec[i][j], vec[i][k]))
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, i;
    Node node;
    scanf("%d", &n);
    while (n--) {
        node.sum = 0;
        for (i = 0; i < 6; i++) {
            scanf("%d", node.a + i);
            node.sum += node.a[i];
        }
        vec[node.sum % N].push_back(node);
    }
    puts(check() ? "Twin snowflakes found." : "No two snowflakes are alike.");
    return 0;
}
