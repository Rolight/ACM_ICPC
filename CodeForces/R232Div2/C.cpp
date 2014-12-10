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
const ULL mod = 1e9 + 7;
map<int,int> st;
int n;
VI pnum,val,cnt;
bool vis[100000 + 5];
LL C[15000][505];

void init() {
    for(int i = 2;i < 100000;i++) if(!vis[i]) {
        pnum.PB(i);
        for(int j = i + i;j < 100000;j += i) vis[j] = true;
    }
    for(int i = 0;i < 15000;i++) C[i][0] = 1;
    for(int i = 1;i < 15000;i++) {
        for(int j = 1;j <= min(i,500);j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

void calc(LL num) {
    int mm = pnum.size();
    for(int i = 0;i < mm && pnum[i] <= num;i++) if(num % pnum[i] == 0) {
        while(num % pnum[i] == 0) {
            st[pnum[i]]++; num /= pnum[i];
        }
    }
    if(num != 1) st[num]++;
}

void solve() {
    if(n == 1) {
        cout << "1" << endl;
        return;
    }
    for(map<int,int>::iterator it = st.begin();it != st.end();++it) {
        val.PB(it->first); cnt.PB(it->second);
    }
    ULL ans = 1;
    int mm = cnt.size();
    for(int i = 0;i < mm;i++)  {
        ULL nowval = C[cnt[i] + n - 1][n - 1];
        ans = (ans * nowval) % mod;
    }
    cout << ans << endl;
}

int main() {
    init();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        LL tmp; cin >> tmp;
        calc(tmp);
    }
    solve();
    return 0;
}
