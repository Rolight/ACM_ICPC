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

int main() {
    int n; scanf("%d",&n);
    if(n > 0) printf("%d\n",n);
    else {
        int a = n / 10;
        int b = n / 100 * 10 + n % 10;
        printf("%d\n",max(a,b));
    }
    return 0;
}
