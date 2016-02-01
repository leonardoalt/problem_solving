#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 5010

vector<int> adj[MAXN];
bool visited[MAXN];

bool
func(int u, int v, vector<int>& path)
{
	int x;
	if(visited[u]) return 0;
	visited[u] = true;
	if(u == v) return 1;
	for(int i = 0; i < (int)adj[u].size(); ++i)
	{
		x = adj[u][i];
		if(func(x, v, path))
		{
			path.push_back(x);
			return 1;
		}
	}
	return 0;
}

int
main()
{
	int n, a, b, s, l;
	while(1)
	{
		scanf("%d", &n);
		if(!n) break;

		for(int i = 0; i <= n; ++i) adj[i].clear();

		for(int i = 0; i < n-1; ++i)
		{
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		scanf("%d", &l);
		while(l--)
		{
			vector<int> path;
			scanf("%d %d", &a, &b);
			memset(visited, false, sizeof(visited));
			func(a, b, path);
			reverse(path.begin(), path.end());
			s = (int)path.size();
			if(s == 1) printf("The fleas jump forever between %d and %d.\n", min(a, b), max(a, b));
			else if(s & 1) printf("The fleas jump forever between %d and %d.\n", min(path[s/2], path[s/2-1]), max(path[s/2], path[s/2-1]));
			else printf("The fleas meet at %d.\n", path[s/2-1]);
		}
	}

	return 0;
}

