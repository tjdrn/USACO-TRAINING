/*
ID: drn93031
PROG: stamps
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define N 2000005
unsigned char dis[N];
int val[55];
queue<int> Q;

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	int K, n;
	scanf("%d%d", &K, &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", val + i);
	}
	for (int i = 0; i < N; i++) {
		dis[i] = 255;
	}

	Q.push(0);
	dis[0] = 0;

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		if (dis[v] > K) break;

		for (int i = 0; i < n; i++) {
			if (v + val[i] >= N || dis[v + val[i]] < 255) continue;
			dis[v + val[i]] = dis[v] + 1;
			Q.push(v + val[i]);	
		}
	}

	for (int i = 0; i < N; i++) {
		if (dis[i] > K) {
			printf("%d\n", i - 1);
			break;
		}
	}	
	return 0;
}

