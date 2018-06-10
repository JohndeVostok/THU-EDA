#include <cstdio>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void inter(vector <int> &a, vector <int> &b, vector <vector <int>> &res) {
	vector <int> c(6);
	for (int i = 0; i < 3; i++) {
		c[i] = max(a[i], b[i]);
	}
	for (int i = 3; i < 6; i++) {
		c[i] = min(a[i], b[i]);
	}
	for (int i = 0; i < 3; i++) {
		if (c[i] >= c[i + 3]) {
			return;
		}
	}
	res.emplace_back(c);
}

bool inside(vector <int> &a, vector <int> &b) {
	for (int i = 0; i < 3; i++) {
		if (a[i] < b[i]) {
			return 0;
		}
	}
	for (int i = 3; i < 6; i++) {
		if (a[i] > b[i]) {
			return 0;
		}
	}
	return 1;
}

void inter(vector <vector <int>> &a, vector <vector <int>> &b, vector <vector <int>> &c) {
	vector <vector <int>> tmp;
	for (auto &x : a) {
		for (auto &y : b) {
			inter(x, y, tmp);
		}
	}
	vector <int> flag(tmp.size(), 1);
	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.size(); j++) {
			if (i != j) {
				if (inside(tmp[i], tmp[j])) {
					flag[i] = 0;
				}
			}
		}
	}
	for (int i = 0; i < tmp.size(); i++) {
		if (flag[i]) {
			c.emplace_back(tmp[i]);
		}
	}
}

int main() {
	int n, m, x;
	vector <vector <int>> a, b, c;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		a.emplace_back(0);
		for (int j = 0; j < 6; j++) {
			scanf("%d", &x);
			a[i].emplace_back(x);
		}
	}
	for (int i = 0; i < m; i++) {
		b.emplace_back(0);
		for (int j = 0; j < 6; j++) {
			scanf("%d", &x);
			b[i].emplace_back(x);
		}
	}
	inter(a, b, c);
	for (const auto &t : c) {
		for (int x : t) {
			printf("%d ", x);
		}
		printf("\n");
	}
}
