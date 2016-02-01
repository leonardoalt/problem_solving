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

typedef pair<int, int> par;
typedef pair<par, int> triple;
typedef pair<int, triple> lala;

set<lala> seta;

#define MAXN 8000010

bool iscbrt[MAXN];

map<int, int> p2c;

int
main()
{
	int t, c=2;
	memset(iscbrt, false, sizeof(iscbrt));
	while(c <= 200)
	{
		iscbrt[c*c*c] = true;
		p2c[c*c*c] = c;
		++c;
	}
	for(int i = 2; i <= 200; ++i)
	{
		for(int j = i + 1; j <= 200; ++j)
		{
			for(int k = j + 1; k <= 200; ++k)
			{
				t = i*i*i + j*j*j + k*k*k;
				if(t >= MAXN) continue;
				if(iscbrt[t]) seta.insert(lala(p2c[t], triple(par(i, j), k)));
			}
		}
	}
	for(set<lala>::iterator it = seta.begin(); it != seta.end(); ++it)
		printf("Cube = %d, Triple = (%d,%d,%d)\n", it->first, it->second.first.first, it->second.first.second, it->second.second);
	return 0;
}

