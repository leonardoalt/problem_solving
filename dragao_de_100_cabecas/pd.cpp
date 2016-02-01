#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

#define MAXC 1000
#define MAXG 100

int cut[MAXG];
int born[MAXG];
int visited[MAXC+10];
int n;

typedef pair<int, int> state;

int dp[MAXC+10];

int
func(int c, int ng)
{
	cout << "DP " << c << " com " << ng << " golpes ate agora" << endl;
	if(c > 1000 || c < 0) return INT_MAX;
	if(dp[c] != INT_MAX) return dp[c];
	int ans = INT_MAX;
	fori(n)
	{
		int g = cut[i];
		int b = born[i];
		if(g > c) continue;
		if((c - g) == 0) ans = min(ans, ng + 1);
		else
		{
			int np = (c - g) + b;
			ans = min(ans, func(np, ng + 1));
		}
	}
	return dp[c] = ans;
}

int
main()
{
	int ans;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;
		fori(n) scanf("%d", &cut[i]);
		fori(n) scanf("%d", &born[i]);
		fori(MAXC) dp[i] = INT_MAX;
		memset(visited, false, sizeof(visited));
		int ans = func(100, 0);
		if(ans == INT_MAX) printf("cavaleiro morreu\n");
		else printf("%d\n", ans);
	}
	return 0;
}

