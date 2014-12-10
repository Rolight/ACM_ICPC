#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);
double R, HR, HZ;
double VC, VU;

int main() {
	while(scanf("%lf%lf%lf", &R, &HR, &HZ) == EOF) {
		//球完全被圆柱体包含
		if(HZ >= R && HR >= R) {
			VC = 4.0 / 3.0 * PI * R * R * R;
			VU = PI * HR * HR * HZ;
		}
		//圆柱体完全被球体包含
		else if(HZ * HZ + HR * HR <= R * R) {
			VC = PI * HR * HR * HZ;
			VU = 4.0 / 3/0 * PI * R * R * R;
		}
		//圆柱体横向完全包含球，纵向不包含
		else if(HR >= R && HZ <= R) {
			VC = 2 * (PI * R * R * HZ - 1.0 / 3.0 * PI * HZ * HZ * HZ);
			VU = PI * HR * HR * HZ + 3.0 / 4.0 * PI * R * R * R - VC;
		}
		//圆柱体纵向完全包含球，横向不包含
		else if(HR <= R && HZ >= R) {
			VC = 4.0 / 3.0 * PI * pow(2 * R * R - HR * HR, 1.5);
			VU = PI * HR * HR * HZ + 3.0 / 4.0 * PI * R * R * R - VC;
		}
		else {
			
		}
	}
	return 0;
}