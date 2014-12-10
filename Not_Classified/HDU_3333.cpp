#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 5e4 + 10;

struct Seg {
    int l,r,id;
    LL ans;
    Seg(int l,int r,int id): l(l),r(r),id(id) {}
}; 

int n,val[maxn],last[maxn],m;
VI num;
vector<Seg> query;
LL C[maxn];
bool ext[maxn];

bool cmp(const Seg &a,const Seg &b) {
    if(a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

bool cmp1(const Seg &a,const Seg &b) {
    return a.id < b.id;
}

inline int lowbit(int x) {
    return x & (-x);
}

void addv(int pos,LL v) {
    while(pos <= n) {
        C[pos] += v; pos += lowbit(pos);
    }
}

LL ask_(int pos) {
    LL ret = 0;
    while(pos > 0) {
        ret += C[pos]; pos -= lowbit(pos);
    }
    return ret;
}

LL ask(int l,int r) {
    return ask_(r) - ask_(l - 1);
}

int getID(int Val) {
    return lower_bound(num.begin(),num.end(),Val) - num.begin() + 1;
}

void solve() {
    memset(C,0,sizeof(C));
    memset(last,-1,sizeof(last));
    int npos = 1;
    for(int i = 0;i < m;i++) {
        Seg &now = query[i];
        while(npos <= now.r) {
            int nowval = getID(val[npos]);
            if(last[nowval] != -1) addv(last[nowval],-val[npos]);
            last[nowval] = npos;
            addv(npos,val[npos]);
            npos++;
        }
        now.ans = ask(now.l,now.r);
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        query.clear();
        num.clear();
        int tmp; scanf("%d",&n);
        for(int i = 1;i <= n;i++) {
            scanf("%d",&val[i]); num.PB(val[i]);
        }
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        scanf("%d",&m);
        for(int i = 0;i < m;i++) {
            int l,r; scanf("%d%d",&l,&r);
            query.PB(Seg(l,r,i));
        }
        sort(query.begin(),query.end(),cmp);
        solve();
        sort(query.begin(),query.end(),cmp1);
        for(int i = 0;i < m;i++) cout << query[i].ans << endl;
    }
    return 0;
}
