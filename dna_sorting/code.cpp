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

vector<string> vec;
typedef pair<int, int> par;
vector<par> vs;

int
func(string& s)
{
	int ans = 0;
	int l = int(s.size());
	fori(l)
	{
		for(int j = i+1; j < l; ++j)
			if(s[i] > s[j]) ++ans;
	}
	return ans;
}

int
main()
{
	int t, l, n;
	string w;
	scanf("%d", &t);
	while(t--)
	{
		vec.clear();
		vs.clear();
		scanf("%d %d", &l, &n);
		fori(n)
		{
			cin >> w;
			vec.push_back(w);
			vs.push_back(par(func(w), i));
		}
		sort(vs.begin(), vs.end());
		fori(n) cout << vec[vs[i].second] << '\n';
		if(t) printf("\n");
	}
	return 0;
}

