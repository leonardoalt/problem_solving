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

map<int, int> mapa;
vector<int> vec;

int
main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		if(mapa.count(n)) ++mapa[n];
		else
		{
			mapa[n] = 1;
			vec.push_back(n);
		}
	}
	fori(int(vec.size())) printf("%d %d\n", vec[i], mapa[vec[i]]);

	return 0;
}

