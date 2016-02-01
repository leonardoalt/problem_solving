#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define fori(n) for(int i = 0; i < n; ++i)
#define forj(n) for(int j = 0; j < n; ++j)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 25

int larg[MAXN], cheg[MAXN];

int
main()
{
	int n, ans, p;

	while(scanf("%d", &n) != EOF)
	{
		fori(n) scanf("%d", &larg[i]);
		fori(n) scanf("%d", &cheg[i]);

		ans = 0;
		fori(n)
		{
			forj(n) if(larg[j] == cheg[i]) { p = j; break; }
			for(int k = p; k > i; --k) swap(larg[k], larg[k-1]);
			ans += p - i;
		}

		printf("%d\n", ans);
	}

	return 0;
}

