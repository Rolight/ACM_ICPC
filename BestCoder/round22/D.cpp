#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

//³Ë·¨ÄæÔª
LL extend_gcd(LL a,LL b,LL &x,LL &y){
    if(b == 0){ x = 1; y = 0; return a;}
    LL gcd = extend_gcd(b, a%b, x, y);
    LL t = x; x = y;  y = t - a / b * y;
    return gcd;
}
LL inv(LL num){
    LL x, y;
    LL gcd = extend_gcd(num, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

const int maxn = 3e4 + 100;

int nowcnt[maxn], a[maxn], n, m;
int ans[maxn];

struct Q {
    int l, r ,id;
    bool operator < (const Q &x) const {
        if(l == x.l) return r < x.r;
        return l < x.l;
    }
};

Q q[maxn];


int main() {
    int T; scanf("%d", &T);
    while(T--) {
        memset(nowcnt, 0, sizeof(nowcnt));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int nowl = 0, nowr = 0;
        LL nowval = 1, nowc = 0;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }
        sort(q + 1, q + 1 + m);
        for(int i = 1; i <= m; i++) {
            while(nowr < q[i].r) {
                nowr++; nowc++;
                nowval = (nowval * nowc) % MOD;
                nowcnt[a[nowr]]++;
                nowval = (nowval * inv(nowcnt[a[nowr]])) % MOD;
            }
            while(nowl < q[i].l - 1) {
                nowval = (nowval * inv(nowc)) % MOD;
                nowval = (nowval * nowcnt[a[nowl]]) % MOD;
                nowcnt[a[nowl]]--;
                nowl++; nowc--;
            }
            ans[q[i].id] = nowval;
        }
        for(int i = 1; i <= m; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
