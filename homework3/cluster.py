def compatible(a, b):
	if len(a) != len(b):
		return False
	n = len(a)
	for i in range(n):
		if a[i] != -1 and b[i] != -1 and a[i] != b[i]:
			return False
	return True

def partition(comp):
	n = len(comp)
	rest = range(n)
	res = [-1 for i in range(n)]
	t = 0

	while len(rest) > 0:
		flag = 1
		for i in rest:
			for j in rest:
				if not comp[i][j]:
					nodes = [i, j]
					flag = 0
					break
			if not flag:
				break
		
		if flag: 
			for i in rest:
				res[i] = t
				t += 1
			break

		for i in rest:
			flag = 1
			for node in nodes:
				if comp[i][j]:
					flag = 0
					break
			if flag:
				nodes.append(i)
	
		s = [[i] for i in nodes]
		restt = []
		for i in rest:
			for idx, group in enumerate(s):
				flag = 1
				for node in group:
					if not comp[i][node]:
						flag = 0
						break
				if flag:
					res[i] = t + idx
					if group[0] != i:
						group.append(i)
					break
			if res[i] == -1:
			 	restt.append(i)

		t += len(s)
		rest = restt
	
	return res

if __name__ == "__main__":
	with open("test2.in", "r") as f:
		lines = f.readlines()

	data = [[int(term) for term in line.strip().split()] for line in lines]

	n, m = data[0]
	next, output = [], []
	for i in range(1, n + 1):
		next.append(data[i][0:m])
		output.append(data[i][m:])

	comp = [[1 for i in range(n)] for i in range(n)]
	flag = 0
	for i in range(n):
		for j in range(n):
			if not compatible(output[i], output[j]):
				flag = 1
				comp[i][j] = 0
	
	while flag:
		flag = 0
		for i in range(n):
			for j in range(n):
				if comp[i][j]:
					for k in range(m):
						if next[i][k] != -1 and next[j][k] != -1 and not comp[next[i][k]][next[j][k]]:
							flag = 1
							comp[i][j] = 0
							break
	
	res = partition(comp)
	str = " ".join([str(term) for term in res])
	with open("test2.out", "w") as f:
		f.write(str)
