#include <iostream>

#define REP(i,n) for (int i = 0; i < n; i++)

const int K = 2;

using namespace std;

int [][]
mul(int A[2][2], int B[2][2])
{
    int C[2][2];
    REP(i, K) REP(j, K) REP(k, K)
        C.T[i][j] = (C.T[i][j] + A.T[i][k] * B.T[k][j]) % MOD;
    return C;
}
