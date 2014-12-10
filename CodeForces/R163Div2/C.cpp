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
const int maxn = 1000 + 5;
const int maxm = 100000 + 5;
struct AA {
    int cnt,id;
    bool operator < (const AA &x) const {
        return cnt > x.cnt;
    }
};

struct ANS {
    int a,b,c;
};

bool under(int x,int y) {
    return x > y;
}

int n;
AA r[maxn],l[maxn];
vector<ANS> ans;


int main() {
    scanf("%d",&n);
    for(int i = 1;i < n;i++) {
        int a,b; scanf("%d%d",&a,&b);
        r[a].cnt++; l[b].cnt++;
    }
    for(int i = 1;i <= n;i++) {
        r[i].id = i; l[i].id = i;
    }
    sort(r + 1,r + n + 1);
    sort(l + 1,l + n + 1);
    for(int i = 1;i <= n;i++) {
        if(l[i].id != i && l[i].cnt != 0) {
            ans.push_back((ANS){2,i,l[i].id});
        }
    }
    for(int i = 1;i <= n;i++) {
        if(r[i].id != n - i + 1 && r[i].cnt != 0) {
            ans.push_back((ANS){1,n - i + 1,r[i].id});
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i = 0;i < ans.size();i++) printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
    return 0;
}
