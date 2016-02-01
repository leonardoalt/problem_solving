#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXN 10010

int vec[MAXN];

int
main()
{
	int p = -1, u = 0, x0, x1, y, l, i;
	memset(vec, 0, sizeof(vec));
	while(scanf("%d %d %d", &x0, &y, &x1) != EOF)
	{
		if(p == -1) p = x0;
		if(x1 > u) u = x1;
		for(int i = x0; i < x1; ++i) vec[i] = max(vec[i], y);
	}
	l = p;
	printf("%d %d", l, vec[l]);
	while(1)
	{
		i = l + 1;
		while(vec[i] == vec[l]) ++i;
		l = i;
		printf(" %d %d", l, vec[l]);
		if(l == u) break;
	}
	printf("\n");
	return 0;
}

