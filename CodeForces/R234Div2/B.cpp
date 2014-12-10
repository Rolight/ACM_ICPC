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
const int maxn = 1005;
set<int> st;

int main() {
    int n,m; scanf("%d%d",&n,&m);
    bool bad = false;
    for(int i = 1;i <= n;i++) {
        int ns,ng;
        for(int j = 1;j <= m;j++) {
            char tmp; scanf(" %c",&tmp);
            if(tmp == 'G') ng = j;
            if(tmp == 'S') ns = j;
        }
        if(ns - ng < 0) bad = true;
        st.insert(ns - ng);
    }
    if(bad) puts("-1");
    else printf("%d\n",(int)st.size());
    return 0;
}
