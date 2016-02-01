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

int vec[55];

int
main()
{
	int n, tot, h, ans, idx, ca=0;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		tot = 0;
		fori(n) { scanf("%d", &vec[i]); tot += vec[i]; }
		h = tot / n;
		sort(vec, vec + n);
		ans = 0;
		idx = 0;
		while(1)
		{
			if(vec[idx] >= h) break;
			ans += h - vec[idx];
			++idx;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++ca, ans);
	}
	return 0;
}

