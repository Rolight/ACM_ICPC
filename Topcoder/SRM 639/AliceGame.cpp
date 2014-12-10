// BEGIN CUT HERE

// END CUT HERE
#line 5 "AliceGame.cpp"
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

typedef long long LL;

class AliceGame
{

	public:
		long long findMinimumValue(long long x, long long y)
		{
			LL t = 0, sum = 0;
			while(sum < x + y) {
				t++;
				sum += t * 2 - 1;
			}
			if(sum != x + y) return -1;
			if(x == 0) return 0;
			LL nowsum = 0, minval = t * 2 + 1, cnt = 0;
			for(LL i = t * 2 - 1; i >= 1; i -= 2) {
				nowsum += i; cnt++;
				if(nowsum >= x && (nowsum - x) % 2 == 0) {
					minval = i;
					break;
				}
			}
			LL cc = (nowsum - x) / 2;
			if(cc == 0) return cnt;
			if(cc > cnt * ((minval + 1) / 2 - 1)) {
				return -1;
			}
			return cnt;
		}

		// BEGIN CUT HERE
	public:
		void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
		template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
		void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
		void test_case_0() { long long Arg0 = 8LL; long long Arg1 = 17LL; long long Arg2 = 2LL; verify_case(0, Arg2, findMinimumValue(Arg0, Arg1)); }
		void test_case_1() { long long Arg0 = 17LL; long long Arg1 = 8LL; long long Arg2 = 3LL; verify_case(1, Arg2, findMinimumValue(Arg0, Arg1)); }
		void test_case_2() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 0LL; verify_case(2, Arg2, findMinimumValue(Arg0, Arg1)); }
		void test_case_3() { long long Arg0 = 9LL; long long Arg1 = 9LL; long long Arg2 = -1LL; verify_case(3, Arg2, findMinimumValue(Arg0, Arg1)); }
		void test_case_4() { long long Arg0 = 500000LL; long long Arg1 = 500000LL; long long Arg2 = 294LL; verify_case(4, Arg2, findMinimumValue(Arg0, Arg1)); }

		// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	AliceGame ___test;
	cout << ___test.findMinimumValue(999999999998LL, 2LL) << endl;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
