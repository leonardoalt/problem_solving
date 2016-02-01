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

#define MAXN 7500

int dp[MAXN];
int coins[5] = {50, 25, 10, 5, 1};
int ma;

int
func(int n)
{
	if(n <= ma) return dp[n];
	for(int i = ma + 1; i <= n; ++i)
	{
		forj(5)
		{
			int x = i - coins[j];
			if(x >= 0) dp[i] += dp[x];
		}
	}
	return dp[n];
}

int
main()
{
	int n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	ma = 0;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n", func(n));
		if(n > ma) ma = n;
	}
	return 0;
}

