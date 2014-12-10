#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
#define lson rt << 1,l,mid
#define rson rt << 1 | 1,mid + 1,r
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1e5 + 10;
VI num;
char buf[1024],cmd[maxn];
int val[maxn],knum,cnt[maxn << 2],n;
LL sum[maxn << 2][5];

int getID(int v) {
    return lower_bound(num.begin(),num.end(),v) - num.begin() + 1;
}

void pushup(int rt,int l,int r) {
    int lc = rt << 1, rc = rt << 1 | 1;
    cnt[rt] = cnt[lc] + cnt[rc];
    for(int i = 0;i < 5;i++) sum[rt][i] = sum[lc][i];
    for(int i = 0;i < 5;i++) sum[rt][(i + cnt[lc]) % 5] += sum[rc][i];
}

void update(int rt,int l,int r,int pos,int tar) {
    int mid = (l + r) >> 1;
    if(l == r) {
        sum[rt][1] = num[pos - 1] * tar;
        cnt[rt] = tar;
    }
    else {
        if(pos <= mid) update(lson,pos,tar);
        else update(rson,pos,tar);
        pushup(rt,l,r);
    }
}

int main() {
    while(~scanf("%d",&n)) {
        num.clear();
        for(int i = 1;i <= n;i++) {
            scanf("%s",buf); cmd[i] = buf[0];
            if(cmd[i] != 's') {
                scanf("%d",&val[i]);
                num.PB(val[i]);
            }
        }
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        knum = num.size();
        for(int i = 1;i <= n;i++) {
            if(cmd[i] == 'a') update(1,1,knum,getID(val[i]),1);
            else if(cmd[i] == 'd') update(1,1,knum,getID(val[i]),0);
            else printf("%I64d\n",sum[1][3]);
        }
    }
    return 0;
}
