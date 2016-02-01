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

#define MAXN 510

int vec[MAXN];

int
func(int x, int n)
{
	int r = 0;
	fori(n) r += abs(vec[i] - vec[x]);
	return r;
}

int
main()
{
	int t, n, ans;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		fori(n) scanf("%d", &vec[i]);
		sort(vec, vec + n);
		if(n & 1) ans = func((n-1) / 2, n);
		else ans = min(func(n / 2, n), func(n / 2 - 1, n));
		printf("%d\n", ans);
	}
	return 0;
}

