#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXN 20

int cd[MAXN];
int n, t;
int ansbm, ansv;

int
main()
{
	int s;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &t);
		fori(t) scanf("%d", &cd[i]);

		ansv = 0;
		fori(1<<t)
		{
			s = 0;
			forj(t)
			{
				if(i & (1 << j)) s += cd[j];
				if(s > n) break;
			}
			if(s > n) continue;
			if((n - s) < (n - ansv))
			{
				ansv = s;
				ansbm = i;
			}
		}
		forj(t) if(ansbm & (1 << j)) printf("%d ", cd[j]);
		printf("sum:%d\n", ansv);
	}
	return 0;
}

