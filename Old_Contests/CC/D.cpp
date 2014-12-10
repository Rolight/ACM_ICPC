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
typedef pair<pair<int,int>,pair<int,int> > piii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
double pl,pr,pz;
map<piii,VI> f;
int n;

double dpow(double a,int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    double ret = dpow(a * a,b / 2);
    if(b & 1) ret *= a;
    return ret;
}

char tmp[1005];
double dfs(int cl,int cr,int mdis,int dis) {
    if(cl + cr == n) {
        if(mdis) {
            printf("%d %d %d\n",cl,cr,mdis);
            for(int i = 0;i < n;i++) {
                printf("%c",tmp[i]);
            }
            puts("");
        }
        return mdis;
    }
    double ret = 0;
    tmp[cl+cr] = 'L';
    ret += dfs(cl + 1,cr,mdis,dis - 1) * pl;
    tmp[cl+cr] = 'R';
    ret += dfs(cl,cr + 1,mdis < dis + 1 ? dis + 1 : mdis,dis + 1) * pr;
    return ret;
}

double getval(int cl,int cr,int cz) {
    int mm = min(cr,cl);
    double p = dpow(pl,cl) * dpow(pr,cr) * dpow(cl + cr,cz)  * dpow(pz,cz);
    double nowval = 1;
    double ret = cr * p;
    if(mm == cr) mm--;
    for(int i = 1;i <= mm;i++) {
        nowval *= i;
        ret += dpow(cr,i) / nowval * p * (cr - i);
   //     printf("%d %f\n",cr - i,dpow(cr,i) / nowval);
    }
    return ret;
}

void solve(int kase) {
    double ans = 0;
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= n;j++) if(i + j <= n) {
            for(int k = 0;k <= n;k++) if(i + j + k <= n) {
                if(i + j + k == n) {
                    ans += getval(i,j,k);
                    printf("%d %d %d val is %f\n",i,j,k,getval(i,j,k));
                }
            }
        }
    }
    printf("%d %f\n",kase,ans);
}


int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d%d%lf%lf",&kase,&n,&pl,&pr);
        cout << dfs(0,0,0,0) << endl;
        //solve(kase);
    }
    return 0;
}
