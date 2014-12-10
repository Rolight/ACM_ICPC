#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define MP(a,b) make_pair(a,b)
typedef long long LL;
typedef pair<int,int> pii;
const int maxn = 100000 + 5;
int n,m;
int a[maxn];
set<pii> seg[32];

LL add(set<pii> &sg,int pos,int k) {
    pii now = MP(pos,n + 1);
    set<pii>::iterator it = sg.lower_bound(now);
    int cnt_prev = 0,cnt_next = 0,nl = pos,nr = pos;
    if(it != sg.begin()) {
        it--;
        if(it->second == pos - 1) {
            cnt_prev = it->second - it->first + 1;
            nl = it->first; sg.erase(it);
        }
    }
    it = sg.lower_bound(now);
    if(it != sg.end()) {
        if(it->first == pos + 1) {
            cnt_next = it->second - it->first + 1;
            nr = it->second; sg.erase(it);
        }
    }
    sg.insert(MP(nl,nr));
    return (1LL << k) * (cnt_prev + 1) * (cnt_next + 1);
}

LL del(set<pii> &sg,int pos,int k) {
    pii now = MP(pos,n + 1);
    set<pii>::iterator it = sg.upper_bound(now);
    it--;
    int cnt_prev = pos - it->first,cnt_next = it->second - pos;
    if(pos != it->first) sg.insert(MP(it->first,pos - 1));
    if(pos != it->second) sg.insert(MP(pos + 1,it->second));
    sg.erase(it);
    return (1LL << k) * (cnt_prev + 1) * (cnt_next + 1) * -1;
}

LL update(int p,int v) {
    LL ret = 0;
    for(int i = 0;i < 32;i++) {
        int bita = (bool)(a[p] & (1 << i)),bitb = (bool)(v & (1 << i));
        if(bita == 0 && bitb == 1) ret += add(seg[i],p,i);
        if(bita == 1 && bitb == 0) ret += del(seg[i],p,i);
    }
    a[p] = v;
    return ret;
}

int main() {
    scanf("%d%d",&n,&m);
    LL sum = 0;
    for(int i = 1;i <= n;i++) {
        int tmp; scanf("%d",&tmp);
        sum += update(i,tmp);
    }
    for(int i = 1;i <= m;i++) {
        int p,v; scanf("%d%d",&p,&v);
        sum += update(p,v);
        cout << sum << endl;
    }
    return 0;
}
