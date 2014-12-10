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
const int maxn = 16;
char buf[maxn];
vector<int> pp;
int ans[1000 + 5];
bool found;
int m,mm;

bool dfs(int delta,int times,int prev) {
    if(times == m) {
        return true;
    }
    bool ret = false;
    for(int i = 0;i < mm;i++) if(delta + pp[i] > 0 && pp[i] != prev) {
        ans[times] = pp[i];
        ret |= dfs(-(delta + pp[i]),times + 1,pp[i]);
        if(ret) break;
    }
    return ret;
}

int main() {
    //freopen("out","w",stdout);
    scanf("%s%d",buf,&m);
    for(int i = 0;i < 10;i++) if(buf[i] == '1') {
        pp.push_back(i + 1);
    }
    sort(pp.begin(),pp.end());
    mm = pp.size();
    if(pp.size() == 0) puts("NO");
    else if(pp.size() == 1) {
        if(m == 1) printf("YES\n%d\n",pp[0]);
        else puts("NO");
    }
    else {
        bool ret = dfs(0,0,-1);
        if(ret) {
            puts("YES");
            for(int i = 0;i < m;i++) {
                if(i) putchar(' ');
                printf("%d",ans[i]);
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
