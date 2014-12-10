// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoardFolding.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

const int maxn = 256;
int mp[maxn][maxn];
int tmp[maxn][maxn];
int f[maxn][maxn];
bool vis[maxn][maxn];
bool col_same[maxn][maxn], can[maxn][maxn];

class BoardFolding
{
	public:
		int tonumber(char c) {
			if(c >= '0' && c <= '9') return c - '0';
			if(c >= 'a' && c <= 'z') return c - 'a' + 10;
			if(c >= 'A' && c <= 'Z') return c - 'A' + 36;
			if(c == '#') return 62;
			return 63;
		}

		int gao(int n, int m) {
			memset(vis, 0, sizeof(vis));
			memset(col_same, 0, sizeof(col_same));
			memset(can, 0, sizeof(can));
			for(int i = 1; i <= m; i++) {
				for(int j = 1; j <= i; j++) {
					bool ok = true;
					for(int k = 1; k <= n; k++) if(mp[k][i] != mp[k][j]) {
						ok = false; break;
					}
					col_same[i][j] = col_same[j][i] = ok;
				}
			}
			for(int i = 1; i <= m; i++) {
				for(int j = i + 1; j <= m; j += 2) {
					bool ok = true;
					int midval = (j - i + 1) / 2;
					for(int k = 0; k < midval; k++) if(!col_same[i + k][j - k]) {
						ok = false; break;
					}
					can[i][j] = ok;
				}
			}
			queue< pair<int, int> > q; q.push(make_pair(1, m));
			int ret = 0;
			vis[1][m] = true;
			while(!q.empty()) {
				pair<int, int> nowval = q.front(); q.pop();
				int nowl = nowval.first, nowr = nowval.second;
				ret++;
				for(int i = nowl; i <= nowr; i++) {
					int pl = i - nowl + 1, pr = nowr - i;
					if(i + pl <= nowr && can[nowl][i + pl] && !vis[i + 1][nowr]) {
						vis[i + 1][nowr] = true;
						q.push(make_pair(i + 1, nowr));
					} 
					if(nowr - pr * 2 >= 0 && can[nowr - pr * 2 + 1][nowr] && !vis[nowl][nowr - pr]) {
						vis[nowl][nowr - pr] = true;
						q.push(make_pair(nowl, nowr - pr));
					}
				}
			}
			return ret;
		}

		int howMany(int N, int M, vector <string> compressedPaper)
		{
			for(int i = 0; i < N; i++) {
				for(int j = 0 ; j < M; j++) {
					mp[i + 1][j + 1] = (tonumber(compressedPaper[i][j / 6]) >> (j % 6)) % 2;
				}
			}
			int rowCount = gao(N, M);
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= M; j++) {
					tmp[j][i] = mp[i][j];
				}
			}
			memcpy(mp, tmp, sizeof(tmp));
			int colCount = gao(M, N);
			return rowCount * colCount;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"1", "3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
		void test_case_1() { int Arg0 = 2; int Arg1 = 7; string Arr2[] = {"@@", "@@"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 84; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
		void test_case_2() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = {"6", "9", "9", "6"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
		void test_case_3() { int Arg0 = 6; int Arg1 = 1; string Arr2[] = {"0", "2", "6", "@", "4", "A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
		void test_case_4() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0", "2", "0"}
			; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	BoardFolding ___test;
	string sb[] = {"OL4sPt", "3WY0Os", "OL4sPZ", "3WY0Os", "3WY0Os", "3WY0Os", "OL4sPt", "OL4sPt", "OL4sPt", "OL4sPt", "3WY0Os", "3WY0Os", "OL4sPt", "OL4sPl", "OL4sPt", "3WY0Os", "OL4sPt", "3WY0Os", "OL4sPl", "OL4sPl", "3WY0Os", "OL4sPl"};
	cout << ___test.howMany(22, 32, vector<string>(sb, sb + (sizeof(sb) / sizeof(sb[0])))) << endl;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
