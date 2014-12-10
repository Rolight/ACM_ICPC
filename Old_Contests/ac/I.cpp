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
const int maxn = 1005;

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void dis(int k,int e) {
    int fm = ++e;
    if(k * fm <= 0) {
        k = -abs(k); fm = abs(fm);
    }
    if(k % fm == 0) printf("%d ",k / fm);
    else printf("%d/%d ",k / gcd(abs(fm),abs(k)), fm / gcd(abs(fm),abs(k)));
    printf("%d",e);
}

int main() {
    int n; 
    while(scanf("%d",&n) != EOF) {
        for(int i = 0;i < n;i++) {
            if(i) putchar(' ');
            int k,e; scanf("%d%d",&k,&e);
            dis(k,e);
        }
        puts("");
    }
    return 0;
}
