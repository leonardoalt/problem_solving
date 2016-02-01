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

#define MAXN 510

vector<int> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];
bool used[MAXN][MAXN];
int N;

int
func(int n)
{
	int u, v, ans=INT_MAX;
	memset(visited, false, sizeof(visited));
	memset(used, false, sizeof(used));
	memset(dist, 0, sizeof(dist));
	queue<int> q; q.push(n);
	dist[n] = 0;
	visited[n] = true;
	while(!q.empty())
	{
		u = q.front(); q.pop();
		fori(int(adj[u].size()))
		{
			v = adj[u][i];
			if(used[u][v]) continue;
			used[u][v] = used[v][u] = true;
			if(visited[v])
			{
				ans = min(ans, dist[u]+dist[v]+1);
				if(ans == 3) return 3;
			}
			else
			{
				q.push(v);
				dist[v] = dist[u]+1;
				visited[v] = true;
			}
		}
	}
	return ans;
}

int
main()
{
	int t, n, m, a, b, ans, ca=0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		fori(n) adj[i].clear();
		N = n;
		fori(m)
		{
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		ans = INT_MAX;
		fori(n) { ans = min(ans, func(i)); if(ans == 3) break; }
		printf("Case %d: ", ++ca);
		if(ans == INT_MAX) printf("impossible\n");
		else printf("%d\n", ans);
	}
	return 0;
}

