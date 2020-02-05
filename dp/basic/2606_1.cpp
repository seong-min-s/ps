/*
부모노드를 다 찾아낸 뒤 연결된 정점들의 수를 찾는 방법
ref:https://www.acmicpc.net/source/5284209
*/
#include<cstdio>
int parent[101];
int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		parent[y] = x;
	}
}
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	while (m--) {
		scanf("%d %d", &a, &b);
		uni(a, b);
	}
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (find(1) == find(i)) {
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}