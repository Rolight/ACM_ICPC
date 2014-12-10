#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void p(char *s)
{
	puts(s);
}

int main()
{
	int n,g;
	cin >> n;
	char goal[50];
	for(int i = 0;i < n;i++)
	{
		g = -1;
		scanf("%d",&g);
		if(g >= 0)
		{
			if(g >= 90) p("4.0");
			else if(g >= 85) p("3.6");
			else if(g >= 80) p("3.2");
			else if(g >= 75) p("2.8");
			else if(g >= 70) p("2.3");
			else if(g >= 65) p("1.8");
			else if(g >= 60) p("1.3");
			else p("0");
		}
		else
		{
			scanf("%s",goal);
			if(strcmp(goal,"YX") == 0) p("4.0");
			if(strcmp(goal,"LH") == 0) p("3.4");
			if(strcmp(goal,"ZD") == 0) p("2.7");
			if(strcmp(goal,"JG") == 0) p("1.5");
			if(strcmp(goal,"BJG") == 0)p("0");
		}
	}
	return 0;
}
