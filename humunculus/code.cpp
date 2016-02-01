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
#define REP(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
ll MOD;
const int K = 2;
ll powers[20];

struct matrix
{
	matrix() { T[0][0] = T[0][1] = T[1][0] = T[1][1] = 0; }
	ll T[2][2];
};

matrix
mul(matrix A, matrix B)
{
    matrix C;
    REP(i, K) REP(j, K) REP(k, K)
        C.T[i][j] = (C.T[i][j] + A.T[i][k] * B.T[k][j]) % MOD;
    return C;
}

matrix
pow(matrix A, int p)
{
    if(p == 1)
        return A;
    if(p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

ll
fib(int N)
{
    ll F1[2];
    F1[0] = 1;
    F1[1] = 1;

    matrix mat;
    mat.T[0][0] = 0, mat.T[0][1] = 1;
    mat.T[1][0] = 1, mat.T[1][1] = 1;

    if(N == 1)
        return 1;
    mat = pow(mat, N-1);

    ll res = 0;
    REP(i, K)
        res = (res + mat.T[0][i] * F1[i]) % MOD;
    return res;
}

int
main()
{
	int n, m;
	powers[0] = 1;
	for(int i = 1; i < 20; ++i)
		powers[i] = powers[i-1]*2;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		MOD = powers[m];
		printf("%lld\n", fib(n));
	}
	return 0;
}

