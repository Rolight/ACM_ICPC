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
const int maxn = 50000 + 5;
const int mod = 65536;
char S[maxn];

void solve() {
    int len = strlen(S);
    int lb = 0, rb = len - 1;
    LL lhash = 0,rhash = 0,rp = 1;
    int ans = 0;
    bool pp = false;
    while(lb <= rb) {
        //BKDRHash
        lhash = lhash * 131 + S[lb];
        rhash = rhash + rp * S[rb]; rp *= 131;
        if(lhash == rhash) {
            if(lb == rb) ans++;
            else ans += 2;
            lhash = rhash = 0;
            rp = 1;
            pp = true;
        }
        else pp = false;
        lb++; rb--;
    }
    ans += (int)!pp;
    printf("%d\n",ans);
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%s",S);
        printf("Case #%d: ",kase);
        solve();
    }
    return 0;
}
