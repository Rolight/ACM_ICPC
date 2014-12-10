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

string getnum(int num) {
    char tmp[10];
    sprintf(tmp,"%d",num);
    return string(tmp);
}

void display(int n,int cur,int d) {
    string out("");
    if(cur == 1) out += "[<<]";
    else out += "(<<)";

    if(cur - d > 1) out += "[...]";

    for(int i = cur - d; i <= cur + d; i++) if(i >= 1 && i <= n) {
        if(i == cur) out += "[" + getnum(i) + "]";
        else out += "(" + getnum(i) + ")";
    }

    if(cur + d < n) out += "[...]";

    if(cur == n) out += "[>>]";
    else out += "(>>)";
    cout << out << endl;
}

int main() {
    int a,b,c,kase = 1;
    while(scanf("%d%d%d",&a,&b,&c) != EOF) {
        printf("Case #%d: ",kase++);
        display(a,b,c);
    }
    return 0;
}
