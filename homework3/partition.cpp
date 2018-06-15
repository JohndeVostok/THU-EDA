#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct status {
	vector <int> next, output;
	int id, type;
};

bool cmp1(const status &a, const status &b) {
	int n = a.output.size();
	for (int i = 0; i < n; i++) {
		if (a.output[i] != b.output[i]) {
			return a.output[i] < b.output[i];
		}
	}
	return 0;
}

bool cmp2(const status &a, const status &b) {
	return a.id < b.id;
}

bool cmp3(const status &a, const status &b) {
	return a.type < b.type;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector <status> s(n);
	for (int i = 0; i < n; i++) {
		s[i].id = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			s[i].next.emplace_back(x);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			s[i].output.emplace_back(x);
		}
	}
	sort(s.begin(), s.end(), cmp1);
	int t = 1;
	s[0].type = 0;
	for (int i = 1; i < n; i++) {
		if (cmp1(s[i - 1], s[i]) || cmp1(s[i], s[i - 1])) {
			s[i].type = t++;
		} else {
			s[i].type = t - 1;
		}
	}
	vector <int> tmp(n);
	while (true) {
		sort(s.begin(), s.end(), cmp2);
		for (int i = 0; i < n; i++) {
			tmp[i] = s[i].type;
		}
		sort(s.begin(). s.end(). cmp3);
		int t = 1;
		for (int i = 1; i < n; i++) {
			
		}
	}
}
