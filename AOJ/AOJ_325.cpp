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
map<int,int> mp;

int main() {
    int n; cin >> n;
    for(int i = 0;i < n;i++) {
        int tmp; cin >> tmp;
        mp[tmp]++;
    }
    for(map<int,int>::iterator iter = mp.begin();iter != mp.end();++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
