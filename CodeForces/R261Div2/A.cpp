#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;

int main() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
        int a = y1 - y2;
        if(a < 0) a = -a;
        printf("%d %d %d %d\n",x1 + a,y1,x2 + a,y2);
    }
    else if(y1 == y2) {
        int a = x1 - x2;
        if(a < 0) a = -a;
        printf("%d %d %d %d\n",x1,y1 + a,x2,y2 + a);
    }
    else if(abs(y1 - y2) == abs(x1 - x2)) {
        int a = abs(y1 - y2);
        if(x1 > x2) {
            int t = x1; x1 = x2; x2 = t;
            t = y1; y1 = y2; y2 = t;
        }
        if(x1 + a == x2 && y1 + a == y2) {
            printf("%d %d %d %d\n",x1,y1 + a,x1 + a,y1);
        }
        else {
            printf("%d %d %d %d\n",x1,y1 - a,x1 + a,y1);
        }
    }
    else puts("-1");
    return 0;
}


