/*
ID: drn93031
PROG: contact
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

#define N 200005
#define LL long long

char ss[N];
int L, R, m;
vector<pair<LL, int> > vec[N];

int count(LL val) {
	int res = 0;
	if (!val) return 1;
	while (val) {
		res++;
		val /= 10;
	}	
	return res;
}


void output(pair<LL, int>& pa) {
	for (int i = pa.second - 1; i >= 0; i--) {
		if (pa.first & (1LL << i)) {
			putchar('1');			
		}
		else {
			putchar('0');
		}
	}
}

map<LL, int> ms;

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	scanf("%d%d%d", &L, &R, &m);

	int n = 1;

	while (~scanf("%s", ss + n)) {
		int t = strlen(ss + n);
		n += t;	
	}
	n--;

	for (int len = L; len <= R; len++) {
		ms.clear();
		LL key = 0;
		LL mask = (1LL << len) - 1;

		for (int i = 1; i <= len; i++) {
			key = key * 2 + (ss[i] == '1');	
		}

		for (int i = len; i <= n; i++) {
			if (ms.find(key) == ms.end()) {
				ms[key] = 1;
			}	
			else {
				ms[key]++;
			}
			if (i < n) {
				key = key << 1 | (ss[i + 1] == '1');		
				key &= mask;
			}
		}

		for (map<LL, int>::iterator it = ms.begin(); it != ms.end(); it++) {
			pair<LL, int> pa = *it;
			vec[pa.second].push_back(make_pair(pa.first, len));
		}			
	}	

	int cnt = 0;

	for (int i = N - 1; i >= 0; i--) {
		if (vec[i].size() == 0) continue;

		printf("%d\n", i);

		sort(vec[i].begin(), vec[i].begin());

		int cc = 0;

		for (int j = 0; j < vec[i].size(); j++) {
			output(vec[i][j]);
			cc++;
			if (cc < 6) {
				if (j == vec[i].size() - 1)
					puts("");
				else
					putchar(' ');
			}
			else {
				cc = 0;
				puts("");
			}
		}

		cnt++;
		if (cnt == m) break;	
	}
	return 0;
}


