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
const int maxn = 2e5 + 10;
typedef long long LL;

typedef set< pair<int, int> >::iterator stsegit;
typedef multiset<int>::iterator stvalit;
int n, w, h;

class Solver {
    set< pair<int, int> > stseg;
    multiset<int> stval;
    int nl, nr, maxv;
    public:
    Solver(int maxv): maxv(maxv) {}
    void init() {
        stseg.clear(); 
        stval.clear();
        stseg.insert(make_pair(0, maxv));
        stval.insert(maxv);
    }

    void insert(int pos) {
        pair<int, int> nowp = make_pair(pos, pos);
        stsegit seg = stseg.lower_bound(nowp); 
        seg--;
        nl = seg->first, nr = seg->second;
        stvalit val = stval.lower_bound(nr - nl);
        stval.erase(val); 
        stval.insert(pos - nl);
        stval.insert(nr - pos);
        stseg.erase(seg);
        stseg.insert(make_pair(nl, pos));
        stseg.insert(make_pair(pos, nr));
    }

    LL getmax() {
        stvalit it = stval.end();
        --it;
        return *it;
    }
};


int main() {
    scanf("%d%d%d", &w, &h, &n);
    Solver H(h), V(w);
    H.init(); V.init();
    char cmd; int qpos;
    for(int i = 0; i < n; i++) {
        scanf(" %c%d", &cmd, &qpos);
        if(cmd == 'H') H.insert(qpos);
        else V.insert(qpos);
        cout << H.getmax() * V.getmax() << endl;
    }
    return 0;
}

