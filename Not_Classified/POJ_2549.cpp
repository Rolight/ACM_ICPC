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
const int maxn = 1010;
const int mod = 1000007;
int S[maxn], n;

int mabs(int x) {
    return x < 0 ? -x : x;
}

struct Hash_Table {
    int first[mod], nxt[mod * 5], val[mod * 5], B[mod * 5], A[mod * 5];
    int sz;

    void clear() {
        memset(first,-1,sizeof(first));
        sz = 0;
    }

    Hash_Table() {
        clear();
    }

    int hash_code(int v) {
        return mabs(v) % mod;
    }

    void insert(int v,int a,int b) {
        int pos = hash_code(v);
        val[sz] = v; B[sz] = b; A[sz] = a;
        nxt[sz] = first[pos];
        first[pos] = sz++;
    }

    bool exist(int v,int a,int b) {
        int pos = hash_code(v);
        for(int i = first[pos];~i;i = nxt[i]) {
            if(val[i] == v && B[i] != b && A[i] != b && B[i] != a && A[i] != a) return true;
        }
        return false;
    }
};

Hash_Table hash;

int main() {
    while(scanf("%d",&n),n) {
        hash.clear();
        for(int i = 0;i < n;i++) scanf("%d",&S[i]);
        sort(S,S + n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) if(i != j) {
                int a = S[i], b = S[j];
                hash.insert(a + b,i,j);
            }
        }
        int ans = -INT_MAX;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) if(i != j) {
                int c = S[i], d = S[j];
                if(hash.exist(d - c,i,j)) {
                    ans = d;
                }
            }
        }
        if(ans == -INT_MAX) {
            printf("no solution\n");
        }
        else printf("%d\n",ans);
    }
    return 0;
}
