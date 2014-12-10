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

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
/*********************************************************************/
vector<double> vd;
char buf[1024];

bool findval(double val) {
    int l = 0,r = vd.size() - 1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(fabs(vd[mid] - val) < eps) return true;
        if(vd[mid] > val) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

bool ok(double n) {
    if(fabs(n - 1) < eps) return true;
    vd.clear();
    vd.push_back(n);
    while(1) {
        int nowval = n * 3;
        if(nowval == 1) return false;
        n = n * 3 - nowval;
        if(findval(n)) break;
    }
    return true;
}

int main() {
    while(scanf("%s",buf),strcmp(buf,"END")) {
        double n;
        sscanf(buf,"%lf",&n);
        if(ok(n)) puts("MEMBER");
        else puts("NON-MEMBER");
    }
    return 0;
}
