#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

using namespace std;
const int maxn = 105;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF) {
        int ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            int a, b; scanf("%d%d", &a, &b);
            int nowcost = 0, cnt = 0;
            while(cnt * a < n) cnt++;
            nowcost = cnt * b;
            ans = min(ans, nowcost);
        }
        printf("%d\n", ans);
    }
    return 0;
}

