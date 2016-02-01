/**
 * Problem  : RNA Secondary Structure
 * Author   : Sohel Hafiz
 * Date     : 2012-10-02
 * Category : Dynamic Programming
 * Level    : Moderate
**/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <cctype>
#include <algorithm>

using namespace std;

#define NUMBEROFTESTCASES 200
#define DEBUG 0

int n;
string rna;
int cg;

int dp[155][155][21];

bool complementary(char c1, char c2) {
	if( c1 > c2 ) swap(c1, c2);
	if( c1 == 'A' && c2 == 'U' ) return true;
	if( c1 == 'C' && c2 == 'G' ) return true;
	return false;
}

void extract(char &left, char &right, int &leftCount, int &rightCount, string rna) {
	int i;
	string s = "";
	left = rna[0];
	for(i = 1; isdigit(rna[i]); i++)
		s += rna[i];
	sscanf(s.c_str(), "%d", &leftCount);

	for(i = rna.size() - 1; i >= 0 && isdigit(rna[i]); i--);
	right = rna[i];
	s = "";
	for(++i; i < rna.size(); i++)
		s += rna[i];
	sscanf(s.c_str(), "%d", &rightCount);
}

string decodeRLE(string rna) {
	int start, end;
	int i, j;
	for(i = 1; isdigit(rna[i]); i++);
	start = i;
	for(i = rna.size() - 1; isdigit(rna[i]); i--);
	end = i - 1;

	string res = "";

	for(i = start; i <= end; i++) {
		char ch = rna[i];
		string s = "";
		int cnt;
		for(j = i + 1; j <= end && isdigit(rna[j]); j++) {
			s += rna[j];
		}
		sscanf(s.c_str(), "%d", &cnt);
		while(cnt--) res += ch;
		i = j - 1;
	}
	
	return res;
}

int memo(int start, int end, int cg) {
	if( start >= end ) return 0;
	if( dp[start][end][cg] != -1 ) return dp[start][end][cg];
	int res = 0;
	int i, a;

	if( complementary(rna[start], rna[end]) && (rna[start] == 'A' || rna[start] == 'U') ) {
		int res = 1 + memo(start + 1, end - 1, cg);
		return dp[start][end][cg] = res;
	}

	for(i = start + 1; i <= end; i++) {
		if( complementary(rna[start], rna[i]) ) {
			if(rna[start] == 'C' || rna[start] == 'G') {
				if( cg == 0 ) continue;
				for(a = 0; a <= cg - 1; a++) {
					int k1 = memo(start + 1, i - 1, a);
					int k2 = memo(i + 1, end, cg - 1 - a);
					if( res < k1 + k2 + 1 ) 
						res = k1 + k2 + 1;
				}	
			}
			else {
				for(a = 0; a <= cg; a++) {
					int k1 = memo(start + 1, i - 1, a);
					int k2 = memo(i + 1, end, cg - a);
					if( res < k1 + k2 + 1 ) 
						res = k1 + k2 + 1;
				}	
				
			}
		}
	}
	int k = memo(start + 1, end, cg);
	if( k > res ) res = k;

	return dp[start][end][cg] = res;
}

int main() {
	int test;
	char left, right;
	int leftCount, rightCount;
	string input;
	cin >> test; assert(test <= NUMBEROFTESTCASES);
	for(int cases = 1; cases <= test; cases++) {
		cin >> input >> cg;
		cout << input << endl;
		assert(cg >= 0 && cg <= 20);
		extract(left, right, leftCount, rightCount, input);
		rna = decodeRLE(input);
		cout << "First RNA = " << rna << endl;
		assert(rna.size() <= 50);
		int res = 0;
		if( complementary(left, right) ) {
			res += min(leftCount, rightCount);
			leftCount -= res;
			rightCount -= res;
			if( left == 'C' || left == 'G' ) {
				res = min(res, cg);
				cg -= res;
			}
		}

		leftCount = min(leftCount, 52);
		rightCount = min(rightCount, 52);
		string s = "";
		while(leftCount--) s += left;
		rna = s + rna;
		while(rightCount--) rna += right;

		if( DEBUG ) { cout << "--" << rna << "--" << endl; }

		n = rna.size();
		cout << rna << endl;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k <= cg; k++)
					dp[i][j][k] = -1;


		res += memo(0, n - 1, cg);

		printf("Case %d: %d\n", cases, res);
		
	}
	return 0;
}

