#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
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
const int maxn = 1e3;
int s, m, n, k;
vector<PII> ans;

struct Tower {
    int h, id;
    bool operator < (const Tower &x) const {
        return h < x.h;
    }
};

Tower a[maxn];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].h; a[i].id = i + 1;
    }
    sort(a, a + n); s = a[n - 1].h - a[0].h;
    while(s && m < k) {
        if(a[0].h + 1 > a[n - 1].h - 1) break;
        a[0].h++; a[n - 1].h--;
        ans.PB(MP(a[n - 1].id, a[0].id));
        sort(a, a + n);
        s = a[n - 1].h - a[0].h;
        m++;
    }
    cout << s << " " << m << endl;
    for(int i = 0; i < m; i++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}
