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
const int maxn = 40;
const int maxm = maxn * maxn;
int N,M,u[maxm],v[maxm];
double d[maxn],w[maxm];
map<string,int> mp;
string buf[maxn];

void bellmanford() {
    for(int i = 1;i <= N;i++) d[i] = 0;
    d[1] = 1;
    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= M;j++) {
            int x = u[j],y = v[j];
            double z = w[j];
            if(d[x] != 0) {
                d[y] = max(d[y],d[x] * z);
            }
        }
    }
}

int main() {
    int kase = 1;
    while(cin >> N,N) {
        mp.clear();
        for(int i = 1;i <= N;i++) {
            cin >> buf[i];
            mp[buf[i]] = i;
        }
        cin >> M;
        for(int i = 1;i <= M;i++) {
            string str1,str2;
            double p;
            cin >> str1 >> p >> str2;
            u[i] = mp[str1];
            v[i] = mp[str2];
            w[i] = p;
        }
        bellmanford();
        cout << "Case " << kase++ << ": ";
        if(d[1] > 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
