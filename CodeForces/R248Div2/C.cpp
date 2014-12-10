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

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 300000;
int a[maxn],n;
VI e[maxn];
LL sum = 0,val[maxn];

int myabs(LL x) {
    return x < 0 ? -x : x;
}

int ab(int aa,int bb) {
    if(aa == 0 || bb == 0) return 0;
    return myabs(a[aa] - a[bb]);
}

void adde(int u,int vv,int w) {
    if(u == vv) return;
    e[u].PB(vv);
    e[vv].PB(u);
}


int main() {
    int m;
    scanf("%d%d",&m,&n);
    LL oldsum = 0;
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 2;i <= n;i++) {
        adde(a[i],a[i - 1],ab(i,i - 1));
        oldsum += ab(i,i - 1);
    }
    for(int i = 1;i <= m;i++) if(e[i].size()) sort(e[i].begin(),e[i].end());
    LL maxdelta = 0;
    for(int i = 1;i <= m;i++) if(e[i].size()) {
        int cnt = e[i].size();
        LL nv1 = e[i][cnt / 2 - 1],nv2 = e[i][cnt / 2];
        LL cnt1 = 0,cnt2 = 0,cnt0 = 0;
        for(int j = 0;j < cnt;j++) {
            cnt0 += myabs(i - e[i][j]);
            cnt1 += myabs(nv1 - e[i][j]);
            cnt2 += myabs(nv2 - e[i][j]);
        }
        //printf("%d %lld %lld %lld %lld %lld\n",i,nv1,nv2,cnt0,cnt1,cnt2);
        maxdelta = min(maxdelta,min(cnt1 - cnt0,cnt2 - cnt0));
    }
    cout << oldsum + maxdelta << endl;
    return 0;
}
