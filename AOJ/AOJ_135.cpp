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
const int maxn = 5000;
char buf[maxn], tmp[maxn];
int f[1000], k;

int main() {
    while(scanf("%d%d", &f[0], &f[1]) == 2) {
        scanf("%d", &k);
        buf[0] = tmp[0] = 0;
        sprintf(buf, "%d%d", f[0], f[1]);
        int nowlen = strlen(buf), now = 2;
        while(nowlen < k) {
            f[now] = f[now - 1] + f[now - 2];
            sprintf(tmp, "%d", f[now]);
            now++;
            nowlen += strlen(tmp);
            strcat(buf, tmp);
        }
        buf[nowlen] = 0;
        printf("%c\n", buf[k - 1]);
    }
    return 0;
}
