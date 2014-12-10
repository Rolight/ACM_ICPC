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
const int maxn = 10;
int a[maxn];

int main() {
    int T; cin >> T;
    while(T--) {
        for(int i = 0;i < 6;i++) cin >> a[i];
        sort(a,a + 6);
        if(a[5] + a[4] > a[3] + a[2] + a[1]) puts("Grandpa Shawn is the Winner!");
        else puts("What a sad story!");
    }
    return 0; 
}
