#include <cstring>
#include <queue>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

typedef pair<bool, int> edge;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAXN 510
#define INF 1000000000

edge mat[MAXN][MAXN];
vi adj[MAXN];
vi pai;
bool rvisited[MAXN][MAXN];
vector<ii> redges;
vector<ii> allredges;
int N, M, S, T;

int
dij()
{
	vi dist(N, INF); dist[S] = 0;
	pai.assign(N, -1); pai[S] = S;
	priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, S));

	while(!pq.empty())
	{
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d == dist[u])
		{
			for(int j = 0; j < (int)adj[u].size(); ++j)
			{
				int v = adj[u][j];
				if(!mat[u][v].first) continue;
				int cost = mat[u][v].second;
				if(dist[u] + cost < dist[v])
				{
					dist[v] = dist[u] + cost;
					pai[v] = u;
					pq.push(ii(dist[v], v));
				}
			}
		}
	}

	return dist[T];
}

void
remove(int v)
{
	//cout << v << ' ';
	if(v == S) return;
	int u = pai[v];
	if(!rvisited[u][v])
	{
		//cout << "Inserindo R aresta " << u << ' ' << v << endl;
		redges.push_back(ii(u, v));
		rvisited[u][v] = true;
	}
	remove(u);
}

int
main()
{
	int a, b, m, c, r, k, init, final;

	while(1)
	{
		scanf("%d %d", &N, &M);
		if(!N && !M) break;

		for(int i = 0; i < N; ++i) adj[i].clear();
		//while(!redges.empty()) redges.pop();
		redges.clear();
		allredges.clear();
		memset(mat, 0, sizeof(mat));

		scanf("%d %d", &S, &T);
		for(int i = 0; i < M; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(b);
			mat[a][b] = edge(true, c);
		}

		r = m = dij();
		//cout << "Dij = " << m << endl;
		if(m != INF)
		{
			memset(rvisited, false, sizeof(rvisited));
			remove(T);
			init = 0;
			final = int(redges.size()) - 1;
			while(init <= final)
			{
				for(int i = init; i <= final; ++i)
				{
					ii e = redges[i];
					//allredges.push_back(e);
					int u = e.first, v = e.second;
					mat[u][v].first = false;
					//cout << "Removendo temp aresta " << u << ' ' << v << endl;
					if((k = dij()) == m)
					{
						remove(T);
					}

					//cout << "K = " << k << endl;
					mat[u][v].first = true;
				}

				for(int i = init; i <= final; ++i)
				{
					ii e = redges[i];
					int u = e.first, v = e.second;
					mat[u][v].first = false;
					//cout << "Cancelando aresta " << u << ' ' << v << endl;
				}

				init = final + 1;
				final = int(redges.size()) - 1;
			}
			r = dij();
		}
		if(r == INF) printf("-1\n");
		else printf("%d\n", r);
	}

	return 0;
}

