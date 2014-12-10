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
const int maxn = 100000 + 5;
int arr[maxn],arr1[maxn];

int main() {
    bool bad = false,eq = true;
    int n,l = -1,r = -1; cin >> n;
    arr[0] = -INT_MAX;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    for(int i = 1;i <= n;i++) arr1[i] = arr[i];
    sort(arr1 + 1,arr1 + 1 + n);
    for(int i = 1;i <= n;i++) {
        if(arr[i] != arr1[i]) eq = false;
        if(arr[i] > arr[i - 1]) {
            if(l != -1 && r == -1) r = i - 1;
        } else if(arr[i] <= arr[i - 1]) {
            if(r != -1) bad = true;
            else if(l == -1) l = i - 1;
        }
    }
    if(r == -1 && l != -1) r = n;
    if(eq) puts("yes\n1 1");
    else if(bad || arr[r] < arr[l - 1] || (r < n && arr[l] > arr[r + 1])) puts("no");
    else printf("yes\n%d %d\n",l,r);
    return 0;
}
