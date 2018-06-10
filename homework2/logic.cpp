#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

void inter(string &a, string &b, vector <string> &res) {
	string c = "";
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'X') {
			c += b[i];
			continue;
		}
		if (b[i] == 'X') {
			c += a[i];
			continue;
		}
		if (a[i] != b[i]) {
			return;
		}
		c += a[i];
	}
	res.emplace_back(c);
}

bool inside(string &a, string &b) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i] and b[i] != 'X') {
			return 0;
		}
	}
	return 1;
}

void inter(vector <string> &a, vector <string> &b, vector <string> &c) {
	vector <string> tmp;
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

void unionl(vector <string> &a, vector <string> &b, vector <string> &c) {
	vector <string> tmp;
	for (auto &x : a) {
		tmp.emplace_back(x);
	}
	for (auto &x : b) {
		tmp.emplace_back(x);
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
	int n, m, t;
	char str[100];
	vector <string> a, b, c, d;
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		a.emplace_back(str);		
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		b.emplace_back(str);		
	}
	inter(a, b, c);
	printf("Intersection:\n");
	for (const auto &s : c) {
		printf("%s\n", s.c_str());
	}
	unionl(a, b, d);
	printf("Union:\n");
	for (const auto &s : d) {
		printf("%s\n", s.c_str());
	}
}
