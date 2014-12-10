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
const int maxn = 105;
vector<int> num;

int main() {
    int n; scanf("%d",&n);
    for(int i = 0;i < n;i++) {
        int tmp; scanf("%d",&tmp);
        num.push_back(tmp);
    }
    sort(num.begin(),num.end());
    swap(num[0],num[num.size() - 1]);
    for(int i = 0;i < num.size();i++) {
        if(i) putchar(' ');
        printf("%d",num[i]);
    }
    putchar('\n');
    return 0;
}
