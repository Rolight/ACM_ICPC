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
vector<int> num;
int n;

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}

int ok() {
    int ff = num[0];
    for(int i = 1;i < n;i++) {
        ff = gcd(ff,num[i]);
    }
    return ff;
}


int main() {
    scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        int tmp; scanf("%d",&tmp);
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());
    int yy = ok();
    if((num[n - 1] / yy - n) % 2) {
        puts("Alice");
    } else puts("Bob");
    return 0;
}
