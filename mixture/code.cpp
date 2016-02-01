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

#define MAXN 100
#define INF 1000000000

int colors[MAXN+10];
int m[MAXN+10][MAXN+10];
int p[MAXN+10][MAXN+10];

int
solve(int _n)
{
    int n = _n;
    int i, j, k, L, q, pk;
    for(i = 1; i <= n; ++i) m[i][i] = 0;

    for(i = 1; i <= _n; ++i)
        for(j = 1; j <= _n; ++j)
            p[i][j] = colors[i-1];

    for(L = 2; L <= n; ++L)
    {
        for(i = 1; i <= n-L+1; ++i)
        {
            j = i + L - 1;
            m[i][j] = INF;
            pk = -1;
            for(k = i; k <= j - 1; ++k)
            {
                q = m[i][k] + m[k+1][j] + p[i][k]*p[k+1][j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    pk = k;
                }
            }
            if(pk > 0)
            {
                int np = (p[i][pk] + p[pk+1][j]) % 100;
                p[i][j] = np;
            }
        }
    }

    return m[1][n];
}

int
main()
{
    int n;
    while(cin >> n)
    {
        fori(n) cin >> colors[i];
        cout << solve(n) << endl;
    }
    return 0;
}

