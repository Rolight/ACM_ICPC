#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double PI = acos(-1);

void swap(double &a,double &b) {
	double t = a; a = b; b = t;
}

int main() {
	int T;
	double a,b,r;
	scanf("%d",&T);
	while(T--) {
		scanf("%lf%lf%lf",&a,&b,&r);
		if(a < b) swap(a,b);
		double d = sqrt(a * a + b * b);
		if(d <= 2 * r) {
			printf("%.4f\n",a * b);
		}
		else if(2 * r <= b) {
			printf("%.4f\n",r * r * PI);
		}
		/*
		else if(2 * r >= a) {
			double sum = sqrt(r * r - a * a / 4) * a + sqrt(r * r - b * b / 4) * b;
			double j = acos(a / (2 * r)) * 4 + acos(b / (2 * r)) * 4;
			j = 2 * PI - j;
			sum += j * r * r / 2;
			printf("%.4f\n",sum);
		}
		*/
		else {
			double j1 = asin(b / 2 / r);
			a = sqrt(r * r - (b / 2) * (b / 2));
			double sum = 2 * r * r * j1 + a * b;
			printf("%.4f\n",sum);
		}
	}
	return 0;
} 
