#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 5;

int val[maxn];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 0;i < n;i++) scanf("%d",&val[i]);
        double sum = 0,ans = -1;
        for(int i = n - 1;i >= 0;i--) {
            sum += val[i];
            ans = max(ans,sum / (n - i));
        }
        printf("%.6f\n",ans);
    }
    return 0;
}

