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
func(int n, int k)
{
	if(n == 1) return 1;
	int ans = 1;
	for(int i = 2; i <= n; ++i)
	{
		ans = (ans + (k-1)) % i + 1;
	}
	return ans;
}

int
main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF)
	{
		printf("%d\n", func(n, k));
	}
	return 0;
}

