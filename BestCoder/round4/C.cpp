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

int g(LL num) {
    stack<int> tmp;
    while(num) {
        tmp.push(num % 10);
        num /= 10;
    }
    int ret = 0,now = 1;
    while(!tmp.empty()) {
        int nowval = tmp.top(); tmp.pop();
        if(now % 2 == 0) nowval *= -1;
        ret += nowval;
        now++;
    }
    return ret;
}

int f(LL x) {
    LL ret = 0;
    if(x >= 0 && x <= 9) return x;
    else if(x < 0) {
        int K = 0;
        while(x + 9 * K < 0) K++;
        return f(x + 9 * K);
    }
    else {
        while(x) {
            ret += x % 10; x /= 10;
        }
        return ret;
    }
}

LL sg(int n) {
    LL ret = 0;
    for(int i = 1;i <= n;i++) ret += g[i];
    return ret;
}

int main() {
    return 0;
}
