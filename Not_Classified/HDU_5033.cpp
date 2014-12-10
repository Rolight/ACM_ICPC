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
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1e5 + 10;
const double PI = acos(-1.0);
struct Building {
    double x,h;
    bool operator < (const Building &b) const {
        return x < b.x;
    }
};

struct Query {
    double x,ans;
    int id;
    bool operator < (const Query &b) const {
        return x < b.x;
    }
};

struct Node {
    double k, outpos, x, h;
};

bool cmp(const Query &a, const Query &b) {
    return a.id < b.id;
}

Query q[maxn];
Building lou[maxn];
int n,m;
stack<Node> stk;

void calc(int rev) {
    while(!stk.empty()) stk.pop();
    for(int i = 0, j = 0; i < m; i++) {
        while(j < n && (lou[j].x < q[i].x) ^ rev) {
            while(!stk.empty()) {
                Node now = stk.top();
                double nowk = (lou[j].h - now.h) / (lou[j].x - now.x);
                if(rev) nowk *= -1;
                if(nowk >= now.k) stk.pop();
                else break;
            }
            Node nxt; 
            nxt.x = lou[j].x;
            nxt.h = lou[j].h;
            if(stk.empty()) {
                nxt.outpos = rev ? -DINF : DINF;
                nxt.k = 0;
            }
            else {
                Node now = stk.top();
                nxt.k = (nxt.h - now.h) / (nxt.x - now.x);
                nxt.outpos = nxt.x - nxt.h / nxt.k;
                if(rev) nxt.k *= -1;
            }
            stk.push(nxt);
            j++;
        } 
        if(!rev) while(!stk.empty() && (stk.top().outpos < q[i].x)) stk.pop();
        else while(!stk.empty() && (stk.top().outpos > q[i].x)) stk.pop();
        Node now = stk.top();
        q[i].ans += atan(now.h / abs(now.x - q[i].x));
    }
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1; kase <= T; kase++) {
        scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            scanf("%lf%lf", &lou[i].x, &lou[i].h);
        }
        scanf("%d",&m);
        for(int i = 0;i < m;i++) {
            scanf("%lf", &q[i].x);
            q[i].ans = 0; q[i].id = i;
        }
        sort(lou, lou + n);
        sort(q, q + m);
        calc(false);
        reverse(lou, lou + n);
        reverse(q, q + m);
        calc(true);
        sort(q, q + m, cmp);
        printf("Case #%d:\n", kase);
        for(int i = 0;i < m;i++) {
            printf("%.10f\n", 180 - q[i].ans * 180 / PI);
        }
    }
    return 0;
}
