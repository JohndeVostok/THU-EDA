#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> type, rest;
vector <vector <int>> pre, suc;
vector <int> lres, rres;

void asap(vector <int> &res) {
	vector <int> count(n), used(m);
	res.clear();
	for (int i = 0; i < n; i++) {
		count[i] = pre[i].size();
		res.emplace_back(0);
	}
	vector <int> q, quse, qwait;
	for (int i = 0; i < n; i++) {
		if (!count[i]) {
			q.emplace_back(i);
		}
	}
	int t = 0;
	while (q.size()) {
		for (int i = 0; i < m; i++) {
			used[i] = 0;
		}
		quse.clear();
		qwait.clear();
		for (const auto &x : q) {
			if (used[type[x]] < rest[type[x]]) {
				used[type[x]]++;
				quse.emplace_back(x);
				res[x] = t;
			} else {
				qwait.emplace_back(x);
			}
		}
		q.clear();
		for (const auto &x : qwait) {
			q.emplace_back(x);
		}
		for (const auto &x : quse) {
			for (const auto &y : suc[x]) {
				count[y]--;
				if (!count[y]) {
					q.emplace_back(y);
				}
			}
		}
		t++;
	}
	printf("ASAP\n");
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			if (res[j] == i) printf("%d ", j);
		}
		printf("\n");
	}
}

void alap(vector <int> &res) {
	vector <int> count(n), used(m);
	res.clear();
	for (int i = 0; i < n; i++) {
		count[i] = suc[i].size();
		res.emplace_back(0);
	}
	vector <int> q, quse, qwait;
	for (int i = 0; i < n; i++) {
		if (!count[i]) {
			q.emplace_back(i);
		}
	}
	int t = 0;
	while (q.size()) {
		for (int i = 0; i < m; i++) {
			used[i] = 0;
		}
		quse.clear();
		qwait.clear();
		for (const auto &x : q) {
			if (used[type[x]] < rest[type[x]]) {
				used[type[x]]++;
				quse.emplace_back(x);
				res[x] = t;
			} else {
				qwait.emplace_back(x);
			}
		}
		q.clear();
		for (const auto &x : qwait) {
			q.emplace_back(x);
		}
		for (const auto &x : quse) {
			for (const auto &y : pre[x]) {
				count[y]--;
				if (!count[y]) {
					q.emplace_back(y);
				}
			}
		}
		t++;
	}
	for (auto &x : res) {
		x = t - x - 1;
	}
	printf("ALAP\n");
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			if (res[j] == i) printf("%d ", j);
		}
		printf("\n");
	}
}

bool cmp(pair <int, int> &a, pair <int, int> &b) {
	return a.second < b.second;
}

void grid() {
	vector <int> count(n), used(m), res(n);
	for (int i = 0; i < n; i++) {
		count[i] = pre[i].size();
	}
	vector <pair <int, int>> q, quse, qwait;
	for (int i = 0; i < n; i++) {
		if (!count[i]) {
			q.emplace_back(i, rres[i] - lres[i]);
		}
	}
	int t = 0;
	while (q.size()) {
		for (int i = 0; i < m; i++) {
			used[i] = 0;
		}
		quse.clear();
		qwait.clear();
		sort(q.begin(), q.end(), cmp);
		for (const auto &x : q) {
			if (used[type[x.first]] < rest[type[x.first]]) {
				used[type[x.first]]++;
				quse.emplace_back(x);
				res[x.first] = t;
			} else {
				qwait.emplace_back(x);
			}
		}
		q.clear();
		for (const auto &x : qwait) {
			q.emplace_back(x);
		}
		for (const auto &x : quse) {
			for (const auto &y : suc[x.first]) {
				count[y]--;
				if (!count[y]) {
					q.emplace_back(y, rres[y] - lres[y]);
				}
			}
		}
		t++;
	}
	printf("GRID\n");
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			if (res[j] == i) printf("%d ", j);
		}
		printf("\n");
	}
}

int main() {
	int t, x;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		type.emplace_back(x);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		rest.emplace_back(x);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		pre.emplace_back(0);
		for (int j = 0; j < t; j++) {
			scanf("%d", &x);
			pre[i].emplace_back(x);
		}
	}
	for (int i = 0; i < n; i++) {
		suc.emplace_back(0);
	}
	for (int i = 0; i < n; i++) {
		for (const auto &x : pre[i]) {
			suc[x].emplace_back(i);
		}
	}
	asap(lres);
	alap(rres);
	grid();
//	for (const auto &t : pre) {for (const auto &x : t) printf("%d ", x); printf("*\n");}
//	printf("\n");
//	for (const auto &t : suc) {for (const auto &x : t) printf("%d ", x); printf("/\n");}
}
