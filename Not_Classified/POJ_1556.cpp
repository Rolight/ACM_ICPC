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
#include <sstream>

using namespace std;

typedef long long LL;
const int maxn = 2000;
const int maxm = 2000 * 2000; 
const double INF = 1e30;
const double eps = 1e-7;
struct Point {
    double x,y;
    Point(double x = 0,double y = 0):x(x),y(y) {}
};

Point str(0,5),end(10,5);
vector<Point> p,pw;
double dist[maxn][maxn],d[maxn];
int N,M;

int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    return 1;
}

Point operator - (Point a,Point b) {
    return Point(a.x - b.x,a.y - b.y);
}

double Cross(Point a,Point b) {
    return a.x * b.y - a.y * b.x;
}

double Dot(Point a,Point b) {
    return a.x * b.x + a.y * b.y;
}


bool SegmentCross(Point a1,Point a2,Point b1,Point b2) {
    double c1 = Cross(a2 - a1,b1 - a1),
           c2 = Cross(a2 - a1,b2 - a1),
           c3 = Cross(b2 - b1,a1 - b1),
           c4 = Cross(b2 - b1,a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool nonecross(Point a1,Point a2) {
    for(int i = 0;i < pw.size();i += 2) {
        if(SegmentCross(a1,a2,pw[i],pw[i + 1]))
            return false;
    }
    return true;
}


void solve() {
    //构建邻接矩阵
    M = p.size();
    for(int i = 0;i < M;i++) {
        for(int j = i + 1;j < M;j++) {
            if(nonecross(p[i],p[j])) {
                dist[i][j] = dist[j][i] = 
                    sqrt(Dot(p[i]-p[j],p[i]-p[j]));
            } else dist[i][j] = INF;
        }
    }
    //bellman-ford
    for(int i = 0;i < M;i++) d[i] = INF;
    d[0] = 0;
    for(int i = 0;i < M;i++) {
        for(int j = 0;j < M;j++) {
            for(int k = 0;k < M;k++) if(dist[j][k] < INF) {
                if(d[j] < INF) {
                    d[k] = min(d[k],d[j] + dist[j][k]);
                }
            }
        }
    }
    printf("%.2f\n",d[M - 1]);
}

int main() {
    while(cin >> N,N != -1) {
        p.clear();
        pw.clear();
        p.push_back(Point(0,5));
        for(int i = 1;i <= N;i++) {
            double posx,posy;
            cin >> posx;
            pw.push_back(Point(posx,0));
            for(int j = 0;j < 4;j++) {
                cin  >> posy;
                p.push_back(Point(posx,posy));
                pw.push_back(Point(posx,posy));
            }
            pw.push_back(Point(posx,10));
        }
        p.push_back(Point(10,5));
        solve();
    }
    return 0;
}
