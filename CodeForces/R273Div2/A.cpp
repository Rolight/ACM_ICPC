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

int main() {
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        int tmp; scanf("%d", &tmp);
        sum += tmp;
    }
    if(sum % 5 != 0 || sum == 0) puts("-1");
    else printf("%d\n", sum / 5);
    return 0;
}
