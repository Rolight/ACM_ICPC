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
const int maxn = 5000 + 5;
PII sub[maxn];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &sub[i].first, &sub[i].second);
    }
    sort(sub + 1, sub + 1 + n);
    int now = 0;
    for(int i = 1; i <= n; i++) {
        int nowa = sub[i].first, nowb = sub[i].second;
        if(now <= nowb) now = nowb;
        else now = nowa;
    }
    printf("%d\n", now);
    return 0;
}
