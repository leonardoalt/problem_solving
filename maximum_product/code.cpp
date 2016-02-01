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

#define MAXN 20

typedef long long ll;

int vec[MAXN];

int
main()
{
	int n, ca=0;
	ll ans, acc;
	while(scanf("%d", &n) != EOF)
	{
		fori(n) scanf("%d", &vec[i]);
		ans = 0;
		fori(n)
		{
			acc = ll(vec[i]);
			ans = max(ans, acc);
			for(int j = i + 1; j < n; ++j)
			{
				acc *= ll(vec[j]);
				ans = max(ans, acc);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++ca, ans);
	}
	return 0;
}

