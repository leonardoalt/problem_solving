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

#define MAXN 40

int vec[MAXN];
int sorted[MAXN];
int orig[MAXN];
vector<int> flips;
int n;

void
flip(int p)
{
	flips.push_back(n-p);
	fori((p+1)/2) swap(vec[i], vec[p-i]);
}

int
main()
{
	string line;
	int x, bottom, r, p;
	while(getline(cin, line))
	{
		flips.clear();
		stringstream ss(line);
		bottom = 0;
		while(ss >> x) vec[bottom++] = x;
		n = bottom;
		memcpy(sorted, vec, bottom * sizeof(int));
		memcpy(orig, vec, bottom * sizeof(int));
		sort(sorted, sorted+bottom);
		while(bottom--)
		{
			r = sorted[bottom];
			if(vec[bottom] == r) continue;
			fori(bottom) if(vec[i] == r) { p = i; break; }
			if(p > 0) flip(p);
			flip(bottom);
		}
		fori(n-1) printf("%d ", orig[i]);
		printf("%d\n", orig[n-1]);
		fori(int(flips.size())) printf("%d ", flips[i]);
		printf("0\n");
	}
	return 0;
}

