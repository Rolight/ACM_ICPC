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
const int maxn = 300000 + 5;
int n,m,col[maxn];
VI p;

bool ok(int a,int b,int c,int ca,int cb,int cc) {
    if(col[a] != 0 && ca != col[a]) return false;
    if(col[b] != 0 && cb != col[b]) return false;
    if(col[c] != 0 && cc != col[c]) return false;
    col[a] = ca; col[b] = cb; col[c] = cc;
    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 1;i <= 3;i++) p.PB(i);
    for(int i = 0;i < m;i++) {
        int a,b,c; cin >> a >> b >> c;
        while(!ok(a,b,c,p[0],p[1],p[2])) next_permutation(p.begin(),p.end());
    }
    for(int i = 1;i <= n;i++) {
        if(i > 1) putchar(' ');
        printf("%d",col[i]);
    }
    putchar('\n');
    return 0;
}
