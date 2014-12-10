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
const int maxn = 26;
int incnt[maxn],outcnt[maxn],n,f[maxn],ext[maxn];
char buf[1024];

int findp(int x) {
    return x == f[x] ? x : f[x] = findp(f[x]);
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        bool bad = false;
        int one = -1,rone = -1;
        scanf("%d",&n);
        memset(incnt,0,sizeof(incnt));
        memset(outcnt,0,sizeof(outcnt));
        memset(ext,0,sizeof(ext));
        for(int i = 0;i <= 26;i++) f[i] = i;
        for(int i = 1;i <= n;i++) {
            scanf("%s",buf);
            int len = strlen(buf);
            incnt[buf[0] - 'a']++;
            outcnt[buf[len - 1] - 'a']++;
            int pa = findp(buf[0] - 'a'),pb = findp(buf[len - 1] - 'a');
            if(pa != pb) f[pa] = pb;
            ext[buf[0] - 'a'] = ext[buf[len - 1] - 'a'] = true;
        }
        for(int i = 0;i < 26;i++) {
            int nowval = incnt[i] - outcnt[i];
            if(nowval == 1) {
                if(one == -1) one = i;
                else bad = true;
            }
            else if(nowval == -1) {
                if(rone == -1) rone = i;
                else bad = true;
            } else if(nowval != 0) bad = true;
        }
        int all = -1;
        for(int i = 0;i < 26;i++) if(ext[i]) {
            if(all == -1) all = findp(i);
            else if(all != findp(i)) bad = true;
        }
        if(bad) puts("The door cannot be opened.");
        else puts("Ordering is possible.");
    }
    return 0;
}
