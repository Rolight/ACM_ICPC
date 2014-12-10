#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = (5e4 + 10) * 4;

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x) * 3 + 1 : ((x) - tb) * 3 + 2)
int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
int c0(int *r, int a, int b) {
	return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b) {
	if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
	else return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}

void sort(int *r, int *a, int *b, int n, int m) {
	int i;
	for (i = 0; i < n; i++) wv[i] = r[a[i]];
	for (i = 0; i < m; i++) ws[i] = 0;
	for (i = 0; i < n; i++) ws[wv[i]]++;
	for (i = 1; i < m; i++) ws[i] += ws[i - 1];
	for (i = n - 1; i >= 0; i--) b[--ws[wv[i]]] = a[i];
}

void dc3(int *r, int *sa, int n, int m) {
	int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
	r[n] = r[n + 1] = 0;
	for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
	sort(r + 2, wa, wb, tbc, m);
	sort(r + 1, wb, wa, tbc, m);
	sort(r, wa, wb, tbc, m);
	for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
		rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
	if (p < tbc) dc3(rn, san, tbc, p);
	else for (i = 0; i < tbc; i++) san[rn[i]] = i;
	for (i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
	if (n % 3 == 1) wb[ta++] = n - 1;
	sort(r, wb, wa, ta, m);
	for (i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
	for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
		sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
	for (; i < ta; p++) sa[p] = wa[i++];
	for (; j < tbc; p++) sa[p] = wb[j++];
}

int Rank[maxn], height[maxn];

void calheight(int *r, int *sa, int n) {
	int i, j, k = 0;
	for (i = 1; i <= n; i++) Rank[sa[i]] = i;
	for (i = 0; i < n; height[Rank[i++]] = k)
	for (k ? k-- : 0, j = sa[Rank[i] - 1]; r[i + k] == r[j + k]; k++);
}

#undef F
#undef G

int str[maxn], sa[maxn], T, n, minv[maxn][30];

void init_RMQ() {
	for(int i = 0; i <= n; i++) {
		minv[i][0] = height[i];
	}
	for(int j = 1; (1 << j) <= n + 1; j++) {
		for(int i = 0; i + (1 << j) - 1 <= n; i++) {
			minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int ql, int qr) {
	if(ql > qr) swap(ql, qr);
	ql++;
	int k = 0;
	while((1 << (k + 1)) <= qr - ql + 1) k++;
	return min(minv[ql][k], minv[qr - (1 << k) + 1][k]);
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			char tmp; scanf(" %c", &tmp);
			str[i] = tmp;
		}
		str[n] = 0;
		dc3(str, sa, n + 1, 200);
		calheight(str, sa, n);
		init_RMQ();
		int maxstep = 1;
		for(int L = 1; L <= n; L++) {
			for(int i = 0; i + L < n; i += L)  {
				int s1 = query(Rank[i], Rank[i + L]);
				int step = s1 / L + 1, ql = i - (L - s1 % L);
				if(ql >= 0) {
					step = max(step, query(Rank[ql], Rank[ql + L]) / L + 1);
				}
				maxstep = max(maxstep, step);
			}
		}
		printf("%d\n", maxstep);
	}
	return 0;
}