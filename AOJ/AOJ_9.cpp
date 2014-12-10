#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	char tart[27] = {"ECFAJKLBDGHIVWZYMNOPQRSTUX"},tarl[27] = {"erwqtyghbnuiopsjkdlfazxcvm"};
	char a;
	while(scanf("%c",&a) && a != '#')
	{
		if(a >= 'a' && a <= 'z') putchar(tarl[a - 'a']);
		else if(a >= 'A' && a <= 'Z') putchar(tart[a - 'A']);
		else putchar(a);
	}
	return 0;
}
