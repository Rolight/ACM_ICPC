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
struct Obj {
    int val,tt;
    Obj(int val,int tt):val(val),tt(tt) {}
    bool operator < (const Obj &x) const {
        return tt < x.tt;
    }
};
int n,cnt;
vector<Obj> o;

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        o.clear();
        for(int i = 0;i < n;i++) {
            int val,hh,mm;
            scanf("%d",&val);
            scanf("%d:%d",&hh,&mm);
            o.push_back(Obj(val,hh * 60 + mm));
            scanf("%d:%d",&hh,&mm);
            o.push_back(Obj(-val,hh * 60 + mm));
        }
        sort(o.begin(),o.end());
        int ans = 0,nowval = 0;
        for(int i = 0;i < o.size();i++) {
            nowval += o[i].val;
            ans = max(nowval,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
