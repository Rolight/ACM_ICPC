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
const int maxn = 100000 + 5;
int n,a[maxn],b[maxn],c[maxn];

int main() {
    cin >> n;
    if(n % 2 == 0) {
        printf("-1\n");
        return 0;
    }
    for(int i = 0;i < n;i++) c[i] = i;
    b[n - 1] = n - 1;
    for(int i = n - 2,val = 0;i >= 0;i--,val++) b[i] = val;
    for(int i = 0;i < n;i++) {
        if(c[i] - b[i] < 0) a[i] = c[i] - b[i] + n;
        else a[i] = c[i] - b[i];
    }
    for(int i = 0;i < n;i++) {
        if(i) putchar(' ');
        printf("%d",a[i]);
    }
    putchar('\n');
    for(int i = 0;i < n;i++) {
        if(i) putchar(' ');
        printf("%d",b[i]);
    }
    putchar('\n');
    for(int i = 0;i < n;i++) {
        if(i) putchar(' ');
        printf("%d",c[i]);
    }
    putchar('\n');
    return 0;
}
