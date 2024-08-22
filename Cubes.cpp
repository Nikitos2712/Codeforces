#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main()
{
	std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
	int n, m;
	std::string s = "", add, S;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> add;
		s += add;
	}
	S = s + "$"; std::reverse(s.begin(), s.end()); S += s;
	std::vector<int> z = { 0 };
	for (int i = 1, l = 0, r = 0; i < S.size(); i++) {
		z.push_back(i < r ? std::min(z[i - l], r - i) : 0);
		while (i + z[i] < S.size() && S[z[i]] == S[i + z[i]]) z[i]++;
		if (r < i + z[i]) l = i, r = i + z[i];
		if (i > s.size() && i != S.size() - 1 && z[i - (S.size() - i - 2)] >= (S.size() - i - 1)) {
			std::cout << s.size() - (S.size() - i - 1) << " ";
		}
	}
	std::cout << s.size();
}
