#include <cstring>
#include <climits>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 110

typedef long long ll;

ll cap[MAXN][MAXN];
ll cost[MAXN][MAXN];
ll fnet[MAXN][MAXN];
vector<ll> adj[MAXN];
ll par[MAXN], d[MAXN];
ll pi[MAXN];

#define CLR(a, x) memset(a, x, sizeof(a))
#define INF (LLONG_MAX/2)

// Dijkstra's using non-negative edge weights (cost + potential)
#define Pot(u,v) (d[u] + pi[u] - pi[v])

bool
dijkstra(ll n, ll s, ll t)
{
	for(ll i = 0; i < n; ++i) d[i] = INF, par[i] = -1;
	d[s] = 0;
	par[s] = -n - 1;

	while( 1 ) 
	{
		// find u with smallest d[u]
		ll u = -1, bestD = INF;
		for(ll i = 0; i < n; ++i) if(par[i] < 0 && d[i] < bestD) bestD = d[u = i];
		if(bestD == INF) break;

		// relax edge (u,i) or (i,u) for all i;
		par[u] = -par[u] - 1;
		for(ll i = 0; i < (ll)adj[u].size(); ++i)
		{
			// try undoing edge v->u
			ll v = adj[u][i];
			if(par[v] >= 0) continue;
			if(fnet[v][u] && d[v] > Pot(u,v) - cost[v][u])
			d[v] = Pot(u, v) - cost[v][u], par[v] = -u-1;

			// try edge u->v
			if(fnet[u][v] < cap[u][v] && d[v] > Pot(u,v) + cost[u][v])
			d[v] = Pot(u,v) + cost[u][v], par[v] = -u - 1;
		}
	}

	for(ll i = 0; i < n; ++i) if(pi[i] < INF) pi[i] += d[i];

	return par[t] >= 0;
}
#undef Pot

ll
mcmf3(ll n, ll s, ll t, ll &fcost)
{
	CLR(fnet, 0);
	CLR(pi, 0);
	ll flow = fcost = 0;

	// repeatedly, find a cheapest path from s to t
	while(dijkstra(n, s, t))
	{
		// get the bottleneck capacity
		ll bot = LLONG_MAX;
		for(ll v = t, u = par[v]; v != s; u = par[v = u])
			bot = min(bot, fnet[v][u] ? fnet[v][u] : (cap[u][v] - fnet[u][v]));

		// update the flow network
		for(ll v = t, u = par[v]; v != s; u = par[v = u])
			if(fnet[v][u]) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
			else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }

		flow += bot;
	}

	return flow;
}

int
main()
{
  ll n, m;
	while(scanf("%lld %lld", &n, &m) != EOF)
	{
    memset( cap, -1, sizeof( cap ) );
    memset( cost, 0, sizeof( cost ) );

    ll a, b, c, d, k;
    ll s = 0, t = n++;
    
		for(ll i = 0; i < n; ++i) adj[i].clear();
		adj[0].push_back(1);
		adj[1].push_back(0);
		cost[0][1] = cost[1][0] = 0;
    for (ll i=0; i<m; i++)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
      cost[a][b] = cost[b][a] = c;
			adj[a].push_back(b);
			adj[b].push_back(a);
    }

		scanf("%lld %lld", &d, &k);
		for(ll i = 0; i < n; ++i) for(ll j = 0; j < n; ++j) cap[i][j] = cap[j][i] = k;
		cap[0][1] = cap[1][0] = d;

    ll fcost;
    ll flow = mcmf3( n, s, t, fcost );
		if(flow < d) printf("Impossible.\n");
		else printf("%lld\n", fcost);
	}

  return 0;
}

