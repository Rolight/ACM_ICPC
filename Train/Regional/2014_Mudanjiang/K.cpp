#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1024;
char buf[maxn];

bool isnum(char c) {
    return c >= '0' && c <= '9';
}

int getval(int len) {
    puts(buf);
    int cnum = 0, cf = 0, ans = 0;
    for(int i = 0; i < len; i++) {
        if(buf[i] >= '0' && buf[i] <= '9') cnum++;
        else {
            cf++;
            while(cf > cnum - 1) {
                ans++; cnum++;
            }
        }
    }
    if(cf == 0) return -1;
    return ans;
}

int solve() {
    int len = strlen(buf);
    if(buf[len - 1] >= '0' && buf[len - 1] <= '9') {
        int ans = getval(len) + 1;
        for(int i = len - 2; i >= 0; i--) if(buf[i] == '*') {
            swap(buf[len - 1], buf[i]);
            ans = min(ans, getval(len) + 1);
            swap(buf[len - 1], buf[i]);
        }
        return ans;
    }
    else return getval(len);

}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", buf);
        int ret = solve();
        printf("%d\n", ret);
    }
    return 0;
}
