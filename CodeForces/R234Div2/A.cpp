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
const int maxn = 15;
char buf[maxn];
char mp[maxn][maxn];
vector<int> aa,ab;

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%s",buf + 1);
        aa.clear(); ab.clear();
        for(int r = 1;r <= 12;r++) if(12 % r == 0) {
            int cnt = 1;
            for(int i = 1;i <= r;i++) {
                for(int j = 1;j <= 12 / r;j++) {
                    mp[i][j] = buf[cnt++];
                }
            }
            bool ok = false;
            for(int j = 1;j <= 12 / r;j++) {
                ok = true;
                for(int i = 1;i <= r;i++) {
                    if(mp[i][j] != 'X') ok = false;
                }
                if(ok) break;
            }
            if(ok) {
                aa.push_back(r); ab.push_back(12 / r);
            }
        }
        printf("%d",(int)aa.size());
        for(int i = 0;i < aa.size();i++) printf(" %dx%d",aa[i],ab[i]);
        puts("");
    }
    return 0;
}
