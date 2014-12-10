#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;

class GameOfStones {
public:
    int count(vector<int> stones) {
        int n = stones.size(), sum = 0;
        for(int i = 0; i < n; i++) sum += stones[i];
        if(sum % n != 0) return -1;
        int avg = sum / n, ret = 0;
        for(int i = 0; i < n; i++) if(stones[i] >= 3 && stones[i] - avg >= 2) {
            if((stones[i] - avg) % 2 != 0) return -1;
            ret += (stones[i] - avg) / 2;
        }
        return ret;
    }
};

GameOfStones gp;

int main() {
    int tmp;
    vector<int> sb; 
    while(scanf("%d", &tmp) != EOF) {
        sb.PB(tmp);
    }
    cout << gp.count(sb) << endl;
    return 0;
}
