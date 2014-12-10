#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10;

//以下是DC3算法求后缀数组

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

int sa[maxn], str[maxn], len, n, minv[maxn][30], val[maxn], vsz;
char buf[maxn];

void init_RMQ() {
	for(int i = 0; i <= len; i++) {
		minv[i][0] = height[i];
	}
	for(int j = 1; (1 << j) <= len + 1; j++) {
		for(int i = 0; i + (1 << j) - 1 <= len; i++) {
			minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int ql, int qr) {
	if(ql > qr) swap(ql, qr);
	ql++;
	int kp = 0;
	while((1 << (kp + 1)) <= qr - ql + 1) {
		kp++;
	}
	return min(minv[ql][kp], minv[qr - (1 << kp) + 1][kp]);
}

int main() {
	int kase = 1;
	while(gets(buf), buf[0] != '#') {
		len = strlen(buf);
		vsz = 0;
		for(int i = 0; i < len; i++) {
			str[i] = buf[i];
		}
		str[len] = 0;
		dc3(str, sa, len + 1, 200);
		calheight(str, sa, len);
		init_RMQ();
		int maxstep = 0;
		for(int L = 1; L <= len; L++) {
			for(int i = 0; i < len && i + L < len; i += L) {
				int s1 = query(Rank[i], Rank[i + L]);
				int step = s1 / L + 1;
				if(i - (L - s1 % L) >= 0) {
					s1 = query(Rank[i - (L - s1 % L)], Rank[i - (L - s1 % L) + L]);
					if(s1 / L + 1 > step) step++;
				}
				if(step > maxstep) {
					maxstep = step; vsz = 0;
				}
				if(step == maxstep) val[vsz++] = L;
			}
		}
		//printf("maxstep is %d\n", maxstep);
		printf("Case %d: ", kase++);
		if(maxstep <= 1) {
			int minval = 500;
			for(int i = 0; i < len; i++) minval = min(minval, (int)buf[i]);
			putchar(minval); puts("");
			continue;
		}
		
		bool found = false;
		for(int i = 0; i <= len; i++) {
			for(int j = 0; j < vsz; j++) {
				if(sa[i] + val[j] <= len && query(i, Rank[sa[i] + val[j]]) / val[j] + 1 == maxstep) {
					for(int k = 0; k < maxstep * val[j]; k++) {
						putchar(buf[sa[i] + k]);
					}
					puts("");
					found = true;
					break;
				}
			}
			if(found) break;
		}

	}
	return 0;
}