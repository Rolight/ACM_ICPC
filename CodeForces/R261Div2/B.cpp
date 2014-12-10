#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <iostream>

using namespace std;

typedef long long LL;
map<LL,LL> mp;
int n;
LL minval = 1e17,maxval = -1;

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        LL tmp; cin >> tmp;
        minval = min(minval,tmp);
        maxval = max(maxval,tmp);
        mp[tmp]++;
    }
    cout << maxval - minval << " ";
    if(maxval - minval == 0) {
        cout << mp[maxval] * (mp[maxval] - 1) / 2 << endl;
    }
    else cout << mp[maxval] * mp[minval] << endl;
    return 0;
}


