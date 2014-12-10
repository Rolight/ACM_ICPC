/*
ID: flsnnx1
LANG: C
TASK: frac1
*/

#include <stdio.h>

#define SIZE 160

struct fraction
{
	int numerator;
	int denominator;
};

typedef struct fraction frac;

frac number[SIZE * SIZE + 5];
int count = 0;

int maxfactor(int a,int b)
{
	if((a & 1) == 0 && (b & 1) == 0) return 2;
	if((a % 3) == 0 && (b % 3) == 0) return 3;
	while(a % b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return b;
}

void makenum(int n)
{
	number[0].numerator = 0;
	number[0].denominator = 1;
	int den,num;
	for(den = 1;den <= n;den++)
	{
		for(num = 1;num <= den;num++)
		{
			frac temp = {num,den};
			if(maxfactor(temp.denominator,temp.numerator) == 1)
				number[++count] = temp;
		}
	}
}

double value(frac n)
{
	double ans = (((double)n.numerator) / ((double)n.denominator));
	return ans;
}

void qsort(int str,int end)
{
	if(str >= end) return;
	int mid = (str + end) / 2,i = str,j = end;
	double std = value(number[mid]);
	while(1)
	{
		while(value(number[i]) < std) i++;
		while(value(number[j]) > std) j--;
		if(i < j)
		{
			frac temp = number[i];
			number[i] = number[j];
			number[j] = temp;
			i++;
			j--;
		}
		else break;
	}
	qsort(str,i - 1);
	qsort(j + 1,end);
}

int main()
{
	FILE *in = fopen("frac1.in","r"),*out = fopen("frac1.out","w");
	int n;
	fscanf(in,"%d",&n);
	makenum(n);
	int i;
	qsort(0,count);
	for(i = 0;i <= count;i++)
		fprintf(out,"%d/%d\n",number[i].numerator,number[i].denominator);
	return 0;
}
