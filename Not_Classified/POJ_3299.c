#include <stdio.h>
#include <math.h>

#define exp(x) pow(2.71828182,(x))

int main()
{
	char ch1,ch2;
	double data1,data2;
	while((ch1 = getchar()) != 'E')
	{
		double H = 0.0,T = 0.0,D = 0.0;
		scanf(" %lf %c %lf\n",&data1,&ch2,&data2);
		if(ch1 == 'T' && ch2 == 'H') T = data1,H = data2;
		if(ch1 == 'H' && ch2 == 'T') H = data1,T = data2;
		if(ch1 == 'T' && ch2 == 'D') T = data1,D = data2;
		if(ch1 == 'D' && ch2 == 'T') D = data1,T = data2;
		if(ch1 == 'H' && ch2 == 'D') H = data1,D = data2;
		if(ch1 == 'D' && ch2 == 'H') D = data1,H = data2;
		if(H == 0.0)
		{
			double e = 6.11 * exp(5417.7530 * (((1/273.16)) - (1 / (D + 273.16))));
			double h = 0.5555 * (e - 10.0);
			H = T + h;
		}
		else if(T == 0.0)
		{
			double e = 6.11 * exp(5417.7530 * (((1/273.16)) - (1 / (D + 273.16))));
			double h = 0.5555 * (e - 10.0);
			T = H - h;
		}
		else
		{
			double h = H - T;
			double e = h / 0.5555 + 10.0;
			D = 1 /  (1 / 273.16 - (log(e / 6.11) / 5417.7530)) - 273.16;
		}
		printf("T %.1f D %.1f H %.1f\n",T,D,H);
	}
	return 0;
}
