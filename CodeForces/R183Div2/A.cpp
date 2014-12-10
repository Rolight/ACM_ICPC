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
const int maxn = 10000 + 5;
int n;

int main() {
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j++) {
            int a = i * i,b = j * j,c = a + b;
            if((int)sqrt(c) * (int)sqrt(c) == c && (int)sqrt(c) <= n) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
