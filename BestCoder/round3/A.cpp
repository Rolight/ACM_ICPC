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
const int maxn = 200000 + 5;
set<int> st;
bool vis[maxn];
int n,m;

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        int maxv = -1;
        memset(vis,0,sizeof(vis));
        st.clear();
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++) {
            int tmp; scanf("%d",&tmp);
            vis[tmp] = true;
            maxv = tmp > maxv ? tmp : maxv;
        }
        for(int i = 1;i <= maxv;i++) {
            if(!vis[i]) st.insert(i);
        }
        for(int i = 0;i < m;i++) {
            int tmp; scanf("%d",&tmp);
            set<int>::iterator iter = st.lower_bound(tmp);
            if(iter != st.end()) {
                printf("%d\n",*iter);
            }
            else if(tmp > maxv) printf("%d\n",tmp);
            else printf("%d\n",maxv+ 1);
        }
    }
    return 0;
}
