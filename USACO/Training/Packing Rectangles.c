/*
ID: flsnnx1
LANG: C
TASK: packrec
*/

#include <stdio.h>
#include <limits.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MAX3(a,b,c) (MAX((a),MAX((b),(c))))

int height[4],width[4],ninh[50001],ninw[50001],count = 0,minsqr = INT_MAX;

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void checksqr(int h,int w)
{
	int sqr = h * w;
	if(sqr <= minsqr)
	{
		minsqr = sqr;
		ninh[count++] = h;
		ninw[count - 1] = w;
	}
}

void checkcase1()
{
	int h = 0,w = 0,i;
	for(i = 0;i < 4;i++)
	{
		w += width[i];
		if(height[i] > h)
			h = height[i];
	}
	checksqr(h,w);
}

void checkcase2()
{
	int h = 0,w = 0,i;
	for(i = 0;i < 3;i++)
	{
		w += width[i];
		if(height[i] > h)
			h = height[i];
	}
	w = MAX(w,width[3]);
	h = h + height[3];
	checksqr(h,w);
}

void checkcase3()
{
	int h = 0,w = 0,i;
	for(i = 0;i < 3;i++) w += width[i];
	h = MAX(height[0],height[1]) + height[3];
	h = MAX(h,height[2]);
	w = MAX(w,width[2] + width[3]);
	checksqr(h,w);
}

void checkcase4()
{
	int h = 0,w = 0;
	h = MAX(height[0],height[3]);
	h = MAX(h,height[1] + height[2]);
	w = width[0] + width[3] + MAX(width[1],width[2]);
	checksqr(h,w);
}

void checkcase5()
{
	int h = 0,w = 0,sqr;
	h = MAX(height[0] + height[1],height[2] + height[3]);
	if(height[1] >= height[2] + height[3])
		w = MAX3(width[1] + width[2],width[1] + width[3],width[0]);
	else if(height[1] > height[3] && height[1] < height[2] + height[3])
		w = MAX3(width[0] + width[2],width[1] + width[2],width[1] + width[3]);
	else if(height[1] < height[3] && height[3] < height[0] + height[1])
		w = MAX3(width[0] + width[2],width[3] + width[1],width[3] + width[0]);
	else if(height[1] == height[3])
		w = MAX(width[0] + width[2],width[1] + width[3]);
	else w = MAX3(width[2],width[0] + width[3],width[1] + width[3]);
	checksqr(h,w);
}

void dfsrotate(int step)
{
	if(step == 4)
	{
		checkcase1();
		checkcase2();
		checkcase3();
		checkcase4();
		checkcase5();
		return;
	}
	dfsrotate(step + 1);
	swap(&height[step],&width[step]);
	dfsrotate(step + 1);
	swap(&height[step],&width[step]);
}

void dfsrec(int step)
{
	int i;
	if(step == 4)
	{
		dfsrotate(0);
		return;
	}
	dfsrec(step + 1);
	for(i = step + 1;i < 4;i++)
	{
		swap(&height[i],&height[step]);
		swap(&width[i],&width[step]);
		dfsrec(step + 1);
		swap(&height[i],&height[step]);
		swap(&width[i],&width[step]);
	}
}

int cmp(int h1,int h2,int w1,int w2)
{
	if(h1 * w1 == h2 * w2)
		if(h1 == h2)
			return w1 - w2;
		else return h1 - h2;
	else return h1 * w1 - h2 * w2;
}

void qsort(int str,int end)
{
	if(str >= end) return;
	int mid = (str + end) / 2,stdh = ninh[mid],stdw = ninw[mid],i = str,j = end;
	while(1)
	{
		while(cmp(ninh[i],stdh,ninw[i],stdw) < 0) i++;
		while(cmp(ninh[j],stdh,ninw[j],stdw) > 0) j--;
		if(i < j)
		{
			swap(&ninw[i],&ninw[j]);
			swap(&ninh[i],&ninh[j]);
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
	FILE *in = fopen("packrec.in","r"),*out = fopen("packrec.out","w");
	int i;
	for(i = 0;i < 4;i++)
		fscanf(in,"%d%d",&height[i],&width[i]);
	dfsrec(0);
	for(i = 0;i < count;i++)
		if(ninh[i] > ninw[i])
			swap(&ninh[i],&ninw[i]);
	
	qsort(0,count - 1);
	fprintf(out,"%d\n",minsqr);
	for(i = 0;i < count && ninw[i] * ninh[i] == minsqr;i++)
		if(i == 0 || (ninw[i] != ninw[i - 1] && ninh[i] != ninh[i - 1])) 
			fprintf(out,"%d %d\n",ninh[i],ninw[i]);
	return 0;
}
