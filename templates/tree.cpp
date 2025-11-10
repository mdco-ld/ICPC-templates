#include <bits/stdc++.h>

using namespace std;

// begin template //
struct Tree {
	vector<vector<int>> adj;
	vector<int> cnt, dst, par, tin, tout;
	int tm;
	Tree(int n) : adj(n), cnt(n), dst(n, 0), par(n, -1), tin(n), tout(n), tm(0) {}
	void addEdge(int x, int y) {
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	void build(int r) {
		build(r, -1);
		hld(r);
	}
	void build(int x, int pre) {
		par[x] = pre;
		tin[x] = tm++;
		cnt[x] = 1;
		for (int &y: adj[x]) if (y != pre) {
			dst[y] = dst[x] + 1;
			build(y);
			cnt[x] += cnt[y];
			if (cnt[y] > cnt[adj[x][0]]) swap(y, adj[x][0]);
		}
		tout[x] = tm;
	}
	// begin HLD
	vector<int> nxt;
	void hld(int r) {
		nxt.assign(adj.size(), r);
		hld(r, -1);
	}
	void hld(int x, int pre) {
		for (int y: adj[x]) if (y != pre) {
			nxt[y] = (y == adj[x][0] ? nxt[x] : y);
			hld(y, x);
		}
	}
	// end HLD
	// begin LCA
	int lca(int x, int y) {
		while (nxt[x] != nxt[y]) {
			if (dst[nxt[x]] > dst[nxt[y]]) {
				x = par[nxt[x]];
			} else {
				y = par[nxt[y]];
			}
		}
		return dst[x] < dst[y] ? x : y;
	}
	// end LCA
};
// end template //
