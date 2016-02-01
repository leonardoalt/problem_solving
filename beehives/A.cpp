// Problem: Beehives
// Author: Jane Alam Jan (jan876@gmail.com)

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
const int NN = 505;

int cases, caseno;
int n, m, adj[NN][NN], deg[NN], d[NN], pr[NN];

int bfs(int s) {
  queue<int> q;
  int res = INF;

  for (int i = 0; i < n; i++) d[i] = INF;
  d[s] = 0;
  pr[s] = -1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < deg[u]; i++) {
      int v = adj[u][i];
      if (v != pr[u]) {
        if (d[v] == INF) {
          d[v] = d[u] + 1;
          pr[v] = u;
          q.push(v);
                      //  cout << "Using " << u << " -> " << v << endl;
        } else {
	  int cl = d[v] + d[u] + 1;
//          if(cl == 8) cout << "Cycle " << cl << ' ' << d[u] << ' ' << d[v] << ' ' << u << ' ' << v << endl;
          res = min(res, d[v] + d[u] + 1);
          if (res == 3) return 3;
        }
      }
    }
  }
  return res;
}

int main() {
  double cl = clock();

  scanf("%d", &cases);
  while (cases--) {
    scanf("%d %d", &n, &m);
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u][deg[u]++] = v;
      adj[v][deg[v]++] = u;
    }
    int res = INF;
    for (int u = 0; u < n && res != 3; u++) res = min(res, bfs(u));
    printf("Case %d: ", ++caseno);
    if (res == INF) puts("impossible");
    else printf("%d\n", res);
  }

  fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
  return 0;
}

