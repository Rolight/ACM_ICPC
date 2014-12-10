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

int N,C[7] = {1,2,5,10,20,50,100};
int f[100][7][250];
int dfs(int now,int prev,int sum) {
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(now == 100) return 0;
    int ret = 0,&note = f[now][prev][sum];
    if(note != -1) return note;
    for(int i = prev;i < 7;i++) {
        ret += dfs(now + 1,i,sum - C[i]);
    }
    return note = ret;
}

int main() {
    memset(f,-1,sizeof(f));
    while(cin >> N,N) {
        cout << dfs(0,0,N) << endl;
    }
    return 0;
}
