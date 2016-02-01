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

char revlet[] = {'A', '#', '#', '#', '3', '#', '#', 'H', 'I', 'L', '#', 'J', 'M', '#', 'O', '#', '#', '#', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};
char revdig[] = {'#', '1', 'S', 'E', '#', 'Z', '#', '#', '8', '#'};

int
main()
{
	string word;
	int n, rp, mp, i;
	char c;
	while(cin >> word)
	{
		n = int(word.size());
		rp = true;
		mp = true;
		for(i = 0; i < n/2; ++i)
		{
			c = word[i];
			if(c != word[n-i-1]) rp = false;
			if(c >= 'A' && c <= 'Z')
			{
				if(revlet[c-'A'] != word[n-i-1]) mp = false;
			}
			else if(revdig[c-'0'] != word[n-i-1]) mp = false;
			if(!rp && !mp) break;
		}
		if(i == n/2 && (n & 1))
		{
			c = word[i];
			if(c >= 'A' && c <= 'Z')
			{
				if(c != revlet[c-'A']) mp = false;
			}
			else if(c != revdig[c-'0']) mp = false;
		}
		if(!rp && !mp) printf("%s -- is not a palindrome.", word.c_str());
		else if(rp && !mp) printf("%s -- is a regular palindrome.", word.c_str());
		else if(!rp && mp) printf("%s -- is a mirrored string.", word.c_str());
		else printf("%s -- is a mirrored palindrome.", word.c_str());
		printf("\n\n");
	}
	return 0;
}

