/*
ID: drn93031
PROG: inflate
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define N 10005

int tt[N];
int val[N];
int f[N];

int main() {
	freopen("inflate.in", "r", stdin);
	freopen("inflate.out", "w", stdout);

	int m, n;

	scanf("%d%d", &m, &n);

	f[0] = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d%d", val + i, tt + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j + tt[i] <= m; j++) {
			f[j + tt[i]] = max(f[j + tt[i]], f[j] + val[i]);
		}	
	}

	printf("%d\n", f[m]);

	return 0;
}


