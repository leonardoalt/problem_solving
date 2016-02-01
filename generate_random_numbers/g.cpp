#include <bits/stdc++.h>

using namespace std;
int main()
{
		long long a;
			map<long long, int> m;
				
				
				while(1)
						{
									cin >> a;
											if (!a) return 0;
													
													while(m[a] == 0)
																{
																				m[a]++;
																							
																							a*= a;
																										a/= 100;
																													a%= 10000;
																															}
															cout << m.size() << '\n';
																	
																	m.clear();
																		}
}
