#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define INF 1500000000

#define fori(n) for(i=0;i<n;++i)
#define forj(n) for(j=0;j<n;++j)
#define forid(n) for(int i=0;i<n;++i)
#define forjd(n) for(int j=0;j<n;++j)

typedef vector<int> vi;
typedef pair<int, int> edge;
typedef pair<int, edge> edge2;
typedef pair<edge2, bool> edge3;
typedef vector<edge> vii;
typedef vector<edge2> vii2;

#define MAXN 110
#define UNK -1
#define NOP -2

int ans[MAXN][MAXN];
vii adj[MAXN];
vi pset;
vii2 edgelist;
int n, m;
bool visited[MAXN];

/* union find set (usado no kruskal) */
void
initset(int n)
{
	pset.assign(n, 0);
	forid(n) pset[i]=i;
}

int findset(int i) { return (pset[i] == i) ? i : (pset[i] = findset(pset[i])); }

bool issameset(int i, int j) { return findset(i) == findset(j); }

void unionset(int i, int j) { pset[findset(i)] = findset(j); }
/**/

void
calc(int u, int v, int p, int q)
{
	int l = (int)adj[v].size();
	forid(l)
	{
		int w0 = adj[v][i].first;
		int w1 = adj[v][i].second;
		if(w0 == p) continue;
		ans[u][w0] = ans[w0][u] = max(q, w1);
		calc(u, w0, v, ans[u][w0]);
	}
}

void
fw(int n)
{
	forid(n) forjd(n) for(int k = 0; k < n; ++k)
	if(adj

int
main()
{
	int a, b, h, p, ca=0;
	bool first = true;

	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			break;

		if(!first) printf("\n");
		first = false;

		forid(n)
		{
			adj[i].clear();
			forjd(n) ans[i][j] = UNK;
		}

		edgelist.clear();

		forid(m)
		{
			scanf("%d %d %d", &a, &b, &p);
			--a; --b;
			edgelist.push_back(edge2(abs(p), edge(a, b)));
		}

		/* Kruskal */
		sort(edgelist.begin(), edgelist.end());

		initset(n);
		forid(m)
		{
			edge2 front = edgelist[i];
			a = front.second.first;
			b = front.second.second;
			p = front.first;
			if(!issameset(a, b))
			{
				unionset(a, b);
				adj[a].push_back(edge(b, p));
				adj[b].push_back(edge(a, p));
			}
		}
		/**/

		forid(n) calc(i, i, i, 0);

		printf("Instancia %d\n", ++ca);
		scanf("%d", &h);
		forid(h)
		{
			scanf("%d %d", &a, &b);
			--a; --b;
			p = 0;
			if(a != b)
				p = ans[a][b];
			printf("%d\n", p);
		}
	}

	return 0;
}
