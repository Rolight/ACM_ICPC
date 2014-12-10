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

const int maxn = 50005;

//以下是倍增法求后缀数组
int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
int cmp(int *r, int a, int b, int l) { return r[a] == r[b] && r[a + l] == r[b + l]; }
void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i++) ws[i] = 0;
    for(i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) ws[i] += ws[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) ws[i] = 0;
        for(i = 0; i < n; i++) ws[wv[i]]++;
        for(i = 0; i < m; i++) ws[i] += ws[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) 
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}

//以下是求解height 数组
int height[maxn], Rank[maxn];
void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; i++) Rank[sa[i]] = i;
    for(i = 0; i < n; height[Rank[i++]] = k) 
        for(k ? k-- : 0, j = sa[Rank[i] - 1]; 
                r[i + k] == r[j + k]; k++) ;
}

char buf[maxn];
int len, str[maxn], sa[maxn];

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", buf);
        len = strlen(buf);
        for(int i = 0; i < len; i++) str[i] = buf[i] + 1;
        str[len] = 0;
        da(str, sa, len + 1, 200);
        calheight(str, sa, len);
        int ans = 0;
        for(int i = 1; i <= len; i++) {
            ans += len - sa[i] - height[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
