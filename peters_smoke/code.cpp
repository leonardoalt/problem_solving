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
	int n, k, ans, a;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		ans = n;
		while(n >= k)
		{
			a = n / k;
			ans += a;
			n %= k;
			n += a;
		}
		printf("%d\n", ans);
	}
	return 0;
}

