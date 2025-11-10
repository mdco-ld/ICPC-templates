#include <bits/stdc++.h>
using namespace std;

// begin template //
vector<int> kmp(string &s) {
	int n = ssize(s);
	vector<int> pre(n);
	int len = 0;
	for (int i = 1; i < n; i++) {
		while (len > 0 && s[i] != s[len]) len = pre[len - 1];
		if (s[len] == s[i]) pre[i] = ++len;
	}
	return pre;
}
// end template //
