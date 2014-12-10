#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

const int maxn = 100000 + 5;
const int L = 1;
const int R = 0;
const double eps = 1e-9;

struct Event {
    double time;
    int kind;
    Event(double time=1e9,int kind=0):time(time),kind(kind) {}
    bool operator < (const Event &x) const {
        if(fabs(time - x.time) < eps) return kind < x.kind;
        return time < x.time;
    } 
};

Event e[maxn * 2];
int cnte,w,h;

void update(double x,double v,double w,double &l,double &r) {
    //0<x+v*t<w
    if(v == 0) {
        if(x <= 0 || x >= w) {
            r = l - 1;
        }
    } 
    else if(v > 0) {
        l = max(l,-x / v);
        r = min(r,(w - x) / v);
    } 
    else {
       l = max(l,(w - x) / v);
       r = min(r,-x / v);
    }
}

void insert(double x,double y,double vx,double vy) {
    double l = 0,r = 1e50;
    update(x,vx,w,l,r);
    update(y,vy,h,l,r);
    if(l < r) {
        e[cnte++] = Event(l,L);
        e[cnte++] = Event(r,R);
    }
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        cnte = 0;
        scanf("%d%d",&w,&h);
        int n; scanf("%d",&n);
        for(int i = 0;i < n;i++) {
            double x,y,vx,vy; 
            scanf("%lf%lf%lf%lf",&x,&y,&vx,&vy);
            insert(x,y,vx,vy);
        }
        sort(e,e + cnte);
        int ans = 0,now = 0;
        for(int i = 0;i < cnte;i++) {
            if(e[i].kind == L) now++;
            else now--;
            ans = max(ans,now);
        }
        printf("%d\n",ans);
    }
    return 0;
}
