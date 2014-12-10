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
const int maxn = 5005;


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
int str[maxn], sa[maxn], len, n;
int minv[maxn][20];

void init_RMQ() {
    for(int i = 0; i <= len; i++) minv[i][0] = height[i];
    for(int j = 1; (1 << j) <= len + 1; j++) {
        for(int i = 0; i + (1 << j) - 1 <= len; i++) {
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
    while(scanf("%s", buf) != EOF) {
        n = len = strlen(buf);
        for(int i = 0; i < len; i++) str[i] = buf[i] + 1;
        str[len++] = '*' + 1;
        for(int i = n - 1; i >= 0; i--) str[len++] = buf[i] + 1;
        str[len] = 0;
        da(str, sa, len + 1, 200);
        calheight(str, sa, len);
        init_RMQ();
        int anslen = 1, anspos = 0;
        for(int i = 0; i < n; i++) {
            int nowval = query(Rank[i], Rank[len - i - 1]);
            int nowlen = nowval * 2 - 1;
            if(nowlen > anslen) {
                anslen = nowlen; anspos = i - nowval + 1;
            }
            if(i == 0) continue;
            nowval = query(Rank[i], Rank[len - i]);
            nowlen = nowval * 2;
            if(nowlen > anslen) {
                anslen = nowlen; anspos = i - nowval;
            }
        }
        for(int i = 0; i < anslen; i++) putchar(buf[i + anspos]);
        puts("");
    }
    return 0;
}
