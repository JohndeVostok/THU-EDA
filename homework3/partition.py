if __name__ == "__main__":
	with open("test1.in", "r") as f:
		lines = f.readlines();

	data = [[int(term) for term in line.strip().split()] for line in lines]

	n, m = data[0]
	next, output = [], []
	for i in range(1, n + 1):
		next.append(data[i][0:m])
		output.append(data[i][m:])
	
	tmp = sorted(enumerate(output), key = lambda x : x[1])
	
	t = 0
	res = [0 for i in range(n)]
	pre = None
	for idx, val in tmp:
		if pre != val:
			t += 1
		pre = val
		res[idx] = t - 1
	
	tp = -1
	while t != tp:
		tp = t
		t = 0
		s = [[] for i in range(tp)]
		for idx, val in enumerate(next):
			suc = [res[i] for i in val]
			s[res[idx]].append((idx, suc))
		for i in range(tp):
			pre = None
			tmp = sorted(s[i], key = lambda x : x[1])
			for idx, val in tmp:
				if pre != val:
					t += 1
				res[idx] = t - 1
				pre = val
	
	str = " ".join([str(i) for i in res])
	with open("test1.out", "w") as f:
		f.write(str)
