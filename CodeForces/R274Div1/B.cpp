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
const int maxn = 1e5 + 10;
set<int> st;
vector<int> ans;
int n, l, x, y, a[maxn];

bool gao0(int val) {
    for(int i = 1; i <= n; i++) {
        int pval = a[i] + val;
        if(st.count(pval)) return true;
    }
    return false;
}

bool gao1(int mid, int p) {
    bool exmid = false, exp = false;
    ans.clear();
    for(int i = 1; i <= n; i++) {
        int pval = a[i] + mid + p;
        if(st.count(pval) && mid + a[i] <= l && mid + a[i] >= 0) {
            ans.PB(mid + a[i]);
            return true;
        }
        exmid |= st.count(a[i] + mid);
        exp |= st.count(a[i] + p);
    }
    if(exmid == true && exp == false) {
        ans.PB(p); return true;
    }
    if(exp == true && exmid == false) {
        ans.PB(mid); return true;
    }
    return false;
}

void gao() {
    //不加刻度
    if(gao0(x) && gao0(y)) {
        puts("0"); return;
    }
    //加一个刻度
    if(gao1(x, y) || gao1(y, x) || gao1(x, -y) || gao1(y, -x) || gao1(-x , y) || gao1(-y, x)) {
        puts("1"); printf("%d\n", ans[0]); return;
    }
    if(x == y) {
        printf("1\n%d\n",x);
        return;
    }
    printf("2\n%d %d\n", x, y);
}

int main() {
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        st.insert(a[i]);
    }
    gao();
    return 0;
}
