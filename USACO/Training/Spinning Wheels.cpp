/*
ID: flsnnx1
LANG: C++
TASK: spin
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

void setIO() {
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
}

const int maxn = 5;
int cnt[maxn], stime[maxn][maxn], etime[maxn][maxn], v[maxn], pos[maxn];
int gra[360];

bool gao(int i) {
	bool ret = false;
	for(int j = 0; j < cnt[i]; j++) {
		int s = stime[i][j] + pos[i], e = etime[i][j] + pos[i];
		for(int k = s; k <= e; k++) {
			gra[k % 360]++;
			if(gra[k % 360] >= 5) ret = true;
		}
	}
	return ret;
}

int main() {
	setIO();
	for(int i = 0; i < 5; i++) {
		scanf("%d%d", &v[i], &cnt[i]);
		for(int j = 0; j < cnt[i]; j++) {
			scanf("%d%d", &stime[i][j], &etime[i][j]);
			etime[i][j] += stime[i][j];
		}
	}
	int ans = -1;
	for(int i = 0; i < 360; i++) {
		memset(gra, 0, sizeof(gra));
		bool ok = false;
		for(int j = 0; j < 5; j++) {
			ok |= gao(j);
			pos[j] += v[j];
		}
		if(ok) {
			ans = i; break;
		}
	}
	if(ans == -1) puts("none");
	else printf("%d\n", ans);
}
