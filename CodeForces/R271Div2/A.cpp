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

using namespace std;

typedef long long LL;
int a[4];

int main() {
    int n; scanf("%d",&n);
    for(int i = n + 1;i <= 9999;i++) {
        a[0] = i / 1000;
        a[1] = i % 1000 / 100;
        a[2] = i % 100 / 10;
        a[3] = i % 10;
        sort(a,a + 4);
        bool ok = true;
        for(int j = 1;j < 4;j++) {
            if(a[j] == a[j - 1]) ok = false;
        }
        if(ok) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
