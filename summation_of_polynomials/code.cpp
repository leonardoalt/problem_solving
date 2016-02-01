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

typedef unsigned long long ull;

#define MAXN 50010

ull vec[MAXN];

void
func()
{
	ull tmp = 0;
	for(ull i = 0; i < MAXN; ++i)
	{
		ull c = i*i*i;
		vec[i] = tmp + c;
		tmp += c;
	}
}

int
main()
{
	int n;
	func();
	while(scanf("%d", &n) != EOF) printf("%llu\n", vec[n]);
	return 0;
}

