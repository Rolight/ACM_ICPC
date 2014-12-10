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
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 2e5 + 10;

struct Point {
    int x,y;
    Point(int x = 0,int y = 0): x(x),y(y) {}
    bool operator < (const Point &p) const {
        return x < p.x;
    }
};

int n,numy[maxn],ky;
int Cleft[maxn],Cright[maxn];
int Stan,Ollie[maxn],Ocnt;
Point p[maxn];

inline int lowbit(int x) {
    return x & -x;
}

void addv(int *C,int v,int pos) {
    while(pos <= ky) {
        C[pos] += v; pos += lowbit(pos);
    }
}

int ask_(int *C,int pos) {
    int ret = 0;
    while(pos > 0) {
        ret += C[pos]; pos -= lowbit(pos);
    }
    return ret;
}

int ask(int *C,int l,int r) {
    if(l > r) return 0;
    return ask_(C,r) - ask_(C,l - 1);
}

int getID(int Val) {
    return lower_bound(numy,numy + ky,Val) - numy + 1;
}

int main() {
    while(scanf("%d",&n), n) {
        ky = 0;
        memset(Cleft,0,sizeof(Cleft));
        memset(Cright,0,sizeof(Cright));
        Ocnt = 0; Stan = -1;
        for(int i = 0;i < n;i++) {
            scanf("%d%d",&p[i].x,&p[i].y);
            numy[ky++] = p[i].y;
        }
        sort(p,p + n); sort(numy,numy + ky);
        ky = unique(numy,numy + ky) - numy;
        for(int i = 0;i < n;i++) addv(Cright,1,getID(p[i].y));
        for(int i = 0;i < n;i++) if(!i || p[i].x != p[i - 1].x) {
            for(int j = i;j < n && p[j].x == p[i].x;j++) {
                addv(Cright,-1,getID(p[j].y));
            }
            int colStan = INT_MAX,colOile = -1;
            for(int j = i;j < n && p[j].x == p[i].x;j++) {
                int nowStan,nowOile,nowpos = getID(p[j].y);
                nowStan = ask(Cleft,1,nowpos - 1) + ask(Cright,nowpos + 1,ky);
                nowOile = ask(Cleft,nowpos + 1,ky) + ask(Cright,1,nowpos - 1);
                if(nowOile > colOile) colOile = nowOile,colStan = INT_MAX;
                if(nowOile == colOile) colStan = min(colStan,nowStan);
            }
            if(colStan > Stan) {
                Stan = colStan; Ocnt = 0;
            }
            if(colStan == Stan) Ollie[Ocnt++] = colOile;
            for(int j = i;j < n && p[j].x == p[i].x;j++) {
                addv(Cleft,1,getID(p[j].y));
            }
        }
        sort(Ollie,Ollie + Ocnt);
        Ocnt = unique(Ollie,Ollie + Ocnt) - Ollie;
        printf("Stan: %d; Ollie:",Stan);
        for(int i = 0;i < Ocnt;i++) printf(" %d",Ollie[i]);
        puts(";");
    }
    return 0;
}
