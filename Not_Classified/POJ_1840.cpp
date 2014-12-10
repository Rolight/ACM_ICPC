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
#define tq(x) ((x)*(x)*(x))
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const LL mod = 1000007;

LL mabs(LL x) {
    return x < 0 ? -x : x;
}

struct Hash_Table {
    int first[mod], nxt[mod * 2];
    LL val[mod * 2], cnt[mod * 2];
    int sz;

    void clear() {
        memset(first,-1,sizeof(first));
        sz = 0;
    }

    int hash_code(LL val) {
        return mabs(val) % mod;
    }

    Hash_Table() {
        clear();
    }

    LL &operator[] (LL num) {
        int pos = hash_code(num);
        for(int i = first[pos];~i;i = nxt[i]) {
            if(val[i] == num) return cnt[i];
        }
        nxt[sz] = first[pos];
        val[sz] = num; cnt[sz] = 0;
        first[pos] = sz++;
        return cnt[sz - 1];
    }
};

LL a1,a2,a3,a4,a5;
Hash_Table mp;

int main() {
    while(cin >> a1 >> a2 >> a3 >> a4 >> a5) {
        mp.clear();
        LL ans = 0;
        for(int x1 = -50;x1 <= 50;x1++) if(x1) {
            for(int x2 = -50;x2 <= 50;x2++) if(x2) {
                for(int x3 = -50;x3 <= 50;x3++) if(x3) {
                    LL val = a1 * tq(x1) + a2 * tq(x2) + a3 * tq(x3);
                    mp[val]++;
                }
            }
        } 
        for(int x4 = -50;x4 <= 50;x4++) if(x4) {
            for(int x5 = -50;x5 <= 50;x5++) if(x5) {
                LL val = a4 * tq(x4) + a5 * tq(x5);
                ans += mp[-val];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
