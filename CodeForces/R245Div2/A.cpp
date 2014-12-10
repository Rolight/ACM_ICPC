#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 105;

struct Seg {
    int l,r; 
    Seg(int l,int r):l(l),r(r) {}
    bool operator < (const Seg &x) const {
        if(l == x.l) return l < x.l;
        return r < x.r;
    }
};

int n,m,col[maxn];
vector<Seg> s;
vector<int> p;

bool check(int now) {
    for(int i = 0;i < m;i++) {
        int sum = 0;
        for(int j = 0;j < now;j++) if(p[j] >= s[i].l && p[j] <= s[i]) {
            sum += col[j];
        }
        if(sum < -1 || sum > 1) return false;
    }
    return true;
}

bool dfs(int now) {
    if(now == n) return check(now);
    col[now] = 1;
    if(dfs(now + 1)) return true;
    col[now] = -1;
    if(dfs(now + 1)) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        int tmp; cin >> tmp; p.push_back(tmp);
    }
    for(int i = 1;i <= m;i++) {
        int cc,dd; cin >> cc >> dd; s.push_back(Seg(cc,dd));
    }
    bool bad = false;
    sort(s.begin(),s.end());
    for(int i = 0;i < s.size();i++) {
        int sum = 0;
        for(int j = 0;j < n;j++) if(p[j] >= s[i].l && p[j] <= s[i].r) {
            if(!col[j]) {
                if(sum <= 0) col[j] = 1;
                else col[j] = -1;
            }
            sum += col[j];
        }
        if(sum < -1 || sum > 1) {
            bad = true; break;
        }
    }
    if(bad) puts("-1");
    else {
        for(int i = 0;i < n;i++) {
            if(i) putchar(' ');
            printf("%d",max(col[i],0));
        }
        puts("");
    }
    return 0;
}


