/*
ID: drn93031
PROG: fact4
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define N 4505

bool vis[N];
int prime[N];
int tot;

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	//
	
	int m = sqrt(N + 0.5);

	for (int i = 2; i <= m; i++) {
		if (vis[i]) continue;
		prime[tot++] = i;
		for (int j = i * i; j < N; j += i) {
			vis[j] = 1;
		}
	}

	int n;
	scanf("%d", &n);
	if (n == 1) {
		puts("1");
	}	
	else {
		int cnt = 0;

		int res = 1;

		for (int i = 2; i <= n; i++) {
			int v = i;
			while (v % 2 == 0) {
				cnt++;
				v /= 2;
			}

			while (v % 5 == 0) {
				cnt--;
				v /= 5;
			}	

			for (int j = 1; j < tot; j++) {
				while (v % prime[j] == 0) {
					v /= prime[j];
					res = (res * prime[j]) % 10;
				}
			}

			if (!vis[v]) {
				res = (res * v) % 10;
			}

		}

		for (int i = 0; i < cnt; i++) {
			res = (res * 2) % 10;
		}

		printf("%d\n", res);	
	}
	return 0;
}



