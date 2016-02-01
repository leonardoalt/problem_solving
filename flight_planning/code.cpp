#include <cmath>
#include <climits>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
typedef vector<int> vi;

#define MAXN 2510

vi adj[MAXN];
vector<edge> edges;
edge fedge, dedge;
int ans, dvalue;

int
bfs(int u)
{
	bool visited[MAXN];
	int r = 0, node, v, x, d;
	memset(visited, false, sizeof(visited));
	queue<edge> q; q.push(edge(u, 0));
	visited[u] = true;
	while(!q.empty())
	{
		edge e = q.front(); q.pop();
		v = e.first;
		d = e.second;
		//cout << "Olhando " << v << " com dist " << d << endl;
		if(d > r)
		{
			r = d;
			node = v;
		}

		for(int i = 0; i < (int)adj[v].size(); ++i)
		{
			x = adj[v][i];
			if(edge(x, v) == fedge || edge(v, x) == fedge) continue;
			if(!visited[x])
			{
				//cout << "Colocando filho " << x << endl;
				q.push(edge(x, d+1));
				visited[x] = true;
			}
		}
	}
	dvalue = r;
	return node;
}

int
diam(int u)
{
	cout << "Diametro parte 1 saindo de " << u << endl;
	int node = bfs(u);
	cout << "Diametro parte 2 saindo de " << node << endl;
	node = bfs(node);
	cout << "DValue = " << dvalue << endl;
	return dvalue;
}

int
main()
{
	int t, n, ans, r0, r1, a, b;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) adj[i].clear();
		edges.clear();

		for(int i = 0; i < n-1; ++i)
		{
			scanf("%d %d", &a, &b);
			--a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			edges.push_back(edge(a, b));
		}

		ans = INT_MAX;
		for(int i = 0; i < (int)edges.size(); ++i)
		{
			fedge = edges[i];
			r0 = ceil(diam(fedge.first) / 2.);
			r1 = ceil(diam(fedge.second) / 2.);
			cout << "r0 = " << r0 << " | r1 = " << r1 << endl;
			if((r0 + r1 + 1) < ans)
			{
				ans = r0 + r1 + 1;
				dedge = fedge;
			}
		}

		printf("%d\n%d %d\n", ans, dedge.first, dedge.second);
	}

	return 0;
}

