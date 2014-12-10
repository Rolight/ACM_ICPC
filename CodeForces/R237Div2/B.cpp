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

using namespace std;
double a,d;
int n;

void printpos(double now) {
    double x,y;
    if(now <= a) x = now,y = 0;
    else if(now <= 2 * a) x = a,y = now - a;
    else if(now <= 3 * a) x = a - (now - 2 * a),y = a;
    else x = 0,y = a - (now - 3 * a);
    printf("%f %f\n",x,y);
}

int main() {
    double nx = 0;
    scanf("%lf%lf%d",&a,&d,&n);
    while(d - 4 * a > 0) d -= 4 * a;
    for(int i = 1;i <= n;i++) {
        nx += d;
        if(nx >= 4 * a) nx -= 4 * a;
        printpos(nx);
    }
    return 0;
}
