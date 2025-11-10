#include <kmp.cpp>

signed main() {
	string s = "abcabcabc";
	auto pre = kmp(s);
	assert(pre == vector({0, 0, 0, 1, 2, 3, 4, 5, 6}));
	return 0;
}
