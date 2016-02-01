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
	float x, y, x0, y0, x1, y1, d0, d1;
	int n;
	bool esc;
	while(scanf("%d %f %f %f %f", &n, &x0, &y0, &x1, &y1) != EOF)
	{
		esc = false;
		fori(n)
		{
			scanf("%f %f", &x, &y);
			d0 = hypot(x - x0, y - y0);
			d1 = hypot(x - x1, y - y1)/2.;
			if(d0 <= d1)
			{
				esc = true;
				printf("The gopher can escape through the hole at (%.3f,%.3f).\n", x, y);
			}
		}
		if(!esc) printf("The gopher cannot escape.\n");
	}
	return 0;
}

