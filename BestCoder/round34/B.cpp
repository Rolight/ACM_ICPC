#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

using namespace std;

const int maxn = 15e4 + 120;
typedef long long LL;
int a[maxn];
LL b[maxn], c[maxn], d[maxn];
int n, w, h;
LL sum = 0;

LL gao(int l, int r) {
    LL cnt = r - l + 1, sumv, cv;
    if(l == 0) {
        sumv = b[r]; 
        cv = d[r];
    }
    else { 
        sumv = b[r] - b[l - 1];
        cv = d[r] - d[l - 1];
    }
    if(sumv >= h * w) {
        return cv;
    }
    else if(sumv < h * w) {
        return cv + (LL)w * h - sumv;
    }
}

int main() {
    while(scanf("%d%d%d", &n, &w, &h) != EOF) {
        sum = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        for(int i = w + 1; i <= w + n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            b[i] = b[i - 1] + a[i];
            c[i] = a[i] - h > 0 ? a[i] - h : 0;
            d[i] = d[i - 1] + c[i];
        }
        for(int i = w + n + 1; i <= w + n + 1 + w; i++) {
            b[i] = b[i - 1] + a[i];
            c[i] = 0;
            d[i] = d[i - 1];
        }
        if((LL)w * h > sum) {
            puts("-1"); continue;
        }
        LL ans = 1e17;
        for(int i = w; i <= w + n + 1 + w; i++) {
            ans = min(ans, gao(i - w + 1, i));
        }
        cout << ans << endl;
    }
    return 0;
}

