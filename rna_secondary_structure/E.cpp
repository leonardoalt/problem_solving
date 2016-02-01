#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;

string seq;
int n, k, pre;
char pairing[256];

void preprocess(string s) {
  stringstream ss(s);
  vector<int> f;
  string allnuc = "";
  char nuc;
  int c, L = 0;
  while(ss >> nuc) {
    allnuc += nuc;
    ss >> c;
    f.push_back(c);
    L += c;
  }
  n = f.size();
  if(n == 1) return; // no pairinging possible

  // Greedily pairing leftmost and rightmost
  L -= f[0] + f[n-1];
  pre = 0;
  if(pairing[allnuc[0]] == allnuc[n-1]) {
    int p = min(f[0], f[n-1]);
    if(allnuc[0] == 'C' || allnuc[0] == 'G') {
      p = min(p, k);
      k -= p;
    }
    pre += p;
    f[0] -= p;
    f[n-1] -= p;
  }

  // remove redundant ones
  f[0] = min(f[0], L);
  f[n-1] = min(f[n-1], L);

  // reconstruct the primary sequence
  seq = "";
  for(int i = 0; i < n; i++)
    for(int j = 0; j < f[i]; j++) seq += allnuc[i];
}

const int maxn = 50 * 3;
const int maxk = 20;
int dp[maxn][maxn][maxk+1];

int doit(int L, int R, int k) {
  if(L >= R) return 0;
  int& ans = dp[L][R][k];
  if(ans >= 0) return ans;
  ans = doit(L+1, R, k); // seq[L] is not pairinged

  if(seq[L] == 'C' || seq[L] == 'G') k--;
  if(k < 0) return ans; // can't pairing seq[L]

  for(int i = L+1; i <= R; i++) {
    if(pairing[seq[L]] != seq[i]) continue;
    for(int k1 = 0; k1 <= k; k1++)
      ans = max(ans, doit(L+1, i-1, k1) + doit(i+1, R, k-k1) + 1);
  }
  return ans;
}

int main() {
  pairing['A'] = 'U';
  pairing['C'] = 'G';
  pairing['G'] = 'C';
  pairing['U'] = 'A';
  int T;
  cin >> T;
  for(int kase = 1; kase <= T; kase++) {
    string input;
    cin >> input >> k;
//cout << "S = " << input << " K = " << k << endl;
    preprocess(input);
    memset(dp, -1, sizeof(dp));
  //  cout << "RNA = " << seq << endl;
    cout << "Case " << kase << ": " << pre + doit(0, seq.size()-1, k) << "\n";
  }
  return 0;
}
