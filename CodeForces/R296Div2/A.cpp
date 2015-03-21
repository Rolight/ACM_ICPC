#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>

using namespace std;
typedef long long LL;

int main() {
    LL a, b, ans = 0;
    cin >> a >> b;
    while(b) {
        ans += a / b;
        LL tmp = b;
        b = a % b;
        a = tmp;
    }
    cout << ans << endl;
    return 0;
}

