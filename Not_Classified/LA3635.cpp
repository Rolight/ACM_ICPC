#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 10005;
const double PI = acos(-1.0);
const double eps = 1e-5;
int R[maxn];

inline double square(int R) {
	return PI * R * R;
}

int main() {
	int T,N,F;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&F);
		int maxR = 0;
		for(int i = 0;i < N;i++) {
			scanf("%d",&R[i]); 
			if(R[i] > maxR) {
				maxR = R[i];
			}
		}
		double str = 0,end = square(maxR);
		while(end - str > eps) {
			double mid = (str + end) / 2;
			int count = 0;
			for(int i = 0;i < N;i++) {
				count += (int)(square(R[i]) / mid);
				if(count >= F + 1) {
					break;
				}
			}
			if(count >= F + 1) {
				str = mid;
			} else {
				end = mid;
			}
		}
		printf("%.4lf\n",str);
	}
	return 0;
}
