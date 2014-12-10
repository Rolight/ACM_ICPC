#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
VI ans;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    ans.PB(a * b * c);
    ans.PB(a + b * c);
    ans.PB((a + b) * c);
    ans.PB(a + b + c);
    ans.PB(a * (b + c));
    ans.PB(a * b + c);
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << endl;
    return 0;
}
