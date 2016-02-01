#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#include <map>
#include <set>

#define MAXV 1010

using namespace std;

vector<int> adj[MAXV];
int lbl[MAXV];
int low[MAXV];
int parent[MAXV];
int nchild[MAXV];
bool arts[MAXV];
int kpta;
int cams;
int root;

int N, M;

void
set_art(int v)
{
	if(!arts[v])
	{
		if(v != root || nchild[v] >= 2)
		{
			arts[v] = true;
			++cams;
		}
	}
}

void
bridgeR(int v)
{
	int i, w;
	vector<int>& refv = adj[v];
	lbl[v] = kpta++;
	low[v] = lbl[v];
	for(i = 0; i < refv.size(); ++i)
	{
		w = refv[i];
		if(lbl[w] == -1)
		{
			parent[w] = v;
			++nchild[v];
			bridgeR(w);
			if(low[v] > low[w])
				low[v] = low[w];

			if(low[w] >= lbl[v])
			{
				set_art(v);
			}
		}
		else if(w != parent[v] && low[v] > lbl[w])
			low[v] = lbl[w];
	}
}

void
all_arts()
{
	int v;
	kpta = cams = 0;

	memset(lbl, -1, N * sizeof(int));
	memset(parent, -1, N * sizeof(int));
	memset(nchild, 0, N * sizeof(int));
	memset(arts, false, N * sizeof(bool));
	memset(low, INT_MAX, N * sizeof(int));

	for(v = 0; v < N; ++v)
	{
		root = v;
		if(lbl[v] == -1)
		{
			parent[v] = v;
			bridgeR(v);
		}
	}
}

int
main()
{
	int i, to, from;

	while(1)
	{
		cin >> N >> M;
		if(N == 0 && M == 0)
			break;

		for(i = 0; i < N; ++i)
			adj[i].clear();

		for(i = 0; i < M; ++i)
		{
			cin >> to >> from;
			adj[to].push_back(from);
			adj[from].push_back(to);
		}

		all_arts();

		cout << cams << endl;
	}

	return 0;
}

