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
const int maxn = 100000 + 5;
int num[maxn];
int r[maxn],l[maxn],n;
stack<pair<int,int> > ss;

void init() {
    pair<int,int> tmp,ntop;
    for(int i = 1;i <= n;i++) {
        if(ss.empty()) {
            ss.push(make_pair(num[i],i));
        } else {
            ntop = ss.top();
            if(ntop.first <= num[i]) ss.push(make_pair(num[i],i));
            else {
                while(!ss.empty() && (tmp = ss.top()).first > num[i]) {
                    r[tmp.second] = i - 1;
                    ss.pop();
                }
                ss.push(make_pair(num[i],i));
            }
        }
    }
    while(!ss.empty()) {
        tmp = ss.top(); ss.pop();
        r[tmp.second] = n;
    }
    for(int i = n;i >= 1;i--) {
        if(ss.empty()) {
            ss.push(make_pair(num[i],i));
        } else {
            ntop = ss.top();
            if(ntop.first <= num[i]) ss.push(make_pair(num[i],i));
            else {
                while(!ss.empty() && (tmp = ss.top()).first > num[i]) {
                    l[tmp.second] = i + 1;
                    ss.pop();
                }
                ss.push(make_pair(num[i],i));
            }
        }
    }
    while(!ss.empty()) {
        tmp = ss.top(); ss.pop();
        l[tmp.second] = 1;
    }
}

LL mw[maxn],mini[maxn];

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        int m;
        while(!ss.empty()) ss.pop();
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            scanf("%d",&num[i]);
            mini[i] = 1e16;
        }
        init();
        memset(mw,0,sizeof(mw));
        for(int i = 1;i <= n;i++) {
            LL nmv = (r[i] - l[i] + 1) * (LL)num[i];
            LL nowlen = r[i] - l[i] + 1;
            mw[nowlen] = max(mw[nowlen],nmv);
            LL noww = min(nmv,(LL)n);
            mini[noww] = min(nowlen,mini[noww]);
        }
        for(int i = n - 1;i >= 1;i--) {
            mw[i] = max(mw[i],mw[i + 1]);
            mini[i] = min(mini[i],mini[i + 1]);
        }
        for(int i = 0;i < m;i++) {
            int cmd,vv; scanf("%d%d",&cmd,&vv);
            if(cmd == 1) {
                if(vv > n) {
                    puts("-1");
                } else {
                    if(vv <= 0) vv = 1;
                    printf("%lld\n",mw[vv]);
                }
            }
            else {
                if(mini[vv] > 1e12) puts("-1");
                else printf("%lld\n",mini[vv]);
            }
        }
    }
    return 0;
}
