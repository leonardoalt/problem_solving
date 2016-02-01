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

int
main()
{
	int n, x, y, s;
	while(scanf("%d %d", &n, &x) != EOF)
	{
		s = 0;
		fori(n)
		{
			scanf("%d", &y);
			s += y;
		}
		if(s == 0)
		{
			printf("0\n");
			continue;
		}
		if(s < 0) s = -s;

		printf("%d\n", int(ceil(float(s)/x)));
	}
	return 0;
}

