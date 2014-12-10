#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
int cnt[105];

int main() {
    int n; scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    bool bad = false;
    for(int i = 1;i <= n;i++) {
        int tmp; scanf("%d",&tmp);
        if(tmp == 25) {
            cnt[25]++;
        }
        if(tmp == 50) {
            if(cnt[25] == 0) {
                bad = true;
                break;
            } else {
                cnt[25]--;
                cnt[50]++;
            }
        }
        if(tmp == 100) {
            if(cnt[50] != 0 && cnt[25] != 0) {
                cnt[50]--; cnt[25]--; cnt[100]++;
            } else if(cnt[50] == 0 && cnt[25] >= 3) {
                cnt[25] -= 3; cnt[100]++;
            } else {
                bad = true; break;
            }
        }
    }
    if(bad) puts("NO");
    else puts("YES");
    return 0;
}
