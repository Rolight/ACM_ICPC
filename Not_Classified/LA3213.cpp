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
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

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
const int maxn = 105;
char str1[maxn], str2[maxn];
int mpp[300];

int main() {
    int n;
    while(scanf("%s%s",str2,str1) != EOF) {
        n = strlen(str1);
        memset(mpp,-1,sizeof(mpp));
        bool ok = true;
        for(int i = 0;i < n;i++) {
            if(mpp[str1[i]] == -1) {
                mpp[str1[i]] = str2[i];
                printf("%c -> %c\n",str1[i], str2[i]);
            }
            else if(mpp[str1[i]] != str2[i]) {
                ok = false; break;
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
    return 0;
}
