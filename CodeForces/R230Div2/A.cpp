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

using namespace std;

typedef long long LL;
int cnt[26];
char buf[123],word[9] = "nineteen";

int main() {
    scanf("%s",buf);
    int len = strlen(buf);
    for(int i = 0;i < len;i++) {
        cnt[buf[i] - 'a']++;
    }
    int pos = 0,ans = 0;
    while(1) {
        int nc = word[pos] - 'a';
        cnt[nc]--;
        if(cnt[nc] < 0) break;
        pos++;
        if(pos == 8) {
            ans++;
            pos = 1;
        }
    }
    printf("%d\n",ans);
    return 0;
}


