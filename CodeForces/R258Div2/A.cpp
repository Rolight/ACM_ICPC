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
    int n,m; cin >> n >> m;
    if(min(n,m) % 2) puts("Akshat");
    else puts("Malvika");
    return 0;
}
