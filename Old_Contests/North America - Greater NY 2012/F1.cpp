#include <cstdio>
#include <iostream>

using namespace std;


long long ans[] = { 1LL ,2LL ,4LL ,10LL ,32LL ,122LL ,544LL ,2770LL ,15872LL ,101042LL ,707584LL ,5405530LL ,44736512LL ,398721962LL ,3807514624LL ,38783024290LL ,419730685952LL ,4809759350882LL ,58177770225664LL ,740742376475050LL ,};

int main() {
    int T,N,kase; cin >> T;
    while(T--) {
        cin >> kase >> N;
        cout << kase << " " << ans[N - 1] << endl;
    }
    return 0;
}
