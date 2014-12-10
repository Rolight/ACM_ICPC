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


int main() {
    int T; scanf("%d",&T);
    char c;
    for(int kase = 1;kase <= T;kase++) {
        int ans = 0,k,b; scanf("%d%d",&k,&b);
        while((c = getchar()) != '\n') {
            while(c == ' ') c = getchar();
            ans = (ans * b + c - '0') % (b - 1);
        }
        printf("%d %d\n",kase,ans);
    }
    return 0;
}
