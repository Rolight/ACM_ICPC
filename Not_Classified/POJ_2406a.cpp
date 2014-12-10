#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 4e6 + 50;

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

char buf[maxn];
int str[maxn], sa[maxn], len;

int main() {
    while(scanf("%s", buf), buf[0] != '.') {
        len = strlen(buf);
        for(int i = 0; i < len; i++) str[i] = buf[i] + 1;
        str[len] = 0;
        dc3(str, sa, len + 1, 200);
        calheight(str, sa, len);
        for(int i = Rank[0] - 1, val = height[Rank[0]]; i > 0; i--) {
            int tmp = val; 
            val = min(val, height[i]), height[i] = tmp;
        }
        for(int i = Rank[0] + 1; i + 1 < len; i++)
            height[i + 1] = min(height[i + 1], height[i]);
        int ans = 1;
        for(int i = 0; i < len; i++) if(len % (i + 1) == 0) {
            if(height[Rank[i + 1]] == len - i - 1) {
                ans = len / (i + 1); break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
