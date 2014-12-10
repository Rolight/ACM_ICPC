#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int tri[4];
	int f1 = 0, f2 = 0;
	for(int i = 0; i < 4; i++) {
		scanf("%d", tri+i);
	}
	sort(tri, tri+4); 
	if(tri[0] + tri[1] > tri[2])
		f1 = 1;
	else if(tri[0] + tri[1] == tri[2])
		f2 = 1;
	if(tri[0] + tri[1] > tri[3])
		f1 = 1;
	else if(tri[0] + tri[1] == tri[3])
		f2 = 1; 
	if(tri[0] + tri[2] > tri[3])
		f1 = 1;
	else if(tri[0] + tri[2] == tri[3])
		f2 = 1; 
	if(tri[1] + tri[2] > tri[3])
		f1 = 1;
	else if(tri[1] + tri[2] == tri[3])
		f2 = 1; 
	if(f1)
		puts("TRIANGLE");
	else if(f2)
		puts("SEGMENT");
	else
		puts("IMPOSSIBLE");
	return 0;
}
