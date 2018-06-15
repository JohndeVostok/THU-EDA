import os
import sys
import numpy as np

def compatible(l1, l2):
	for i, j in zip(l1, l2):
		if i != -1 and j != -1 and i != j:
			return False
	return True

def clique_partition(connmat):
	n = connmat.shape[0]
	rest = range(n)
	result = [-1] * n
	k = 0

	while len(rest) > 0:
		flag = True
		for i in rest:
			for j in rest:
				if not connmat[i, j]:
					node = [i, j]
					flag = False
					break
			if not flag:
				break
		
		if flag: 
			for i in rest:
				result[i] = k
				k += 1
			break

		for i in rest:
			flag = True
			for j in node:
				if connmat[i, j]:
					flag = False
					break
			if flag:
				node.append(i)
	
		pack = [[i] for i in node]
		left = []
		for i in rest:
			for idx, j in enumerate(pack):
				flag = True
				for o in j:
					if not connmat[i, o]:
						flag = False
						break
				if flag:
					result[i] = k + idx
					if j[0] != i:
						j.append(i)
					break
			if result[i] == -1:
			 	left.append(i)

		k += len(pack)
		rest = left
	
	return result

def main(infile, outfile):
	
	with open("test2.in", "r") as f:
		data = [[int(j) for j in i.strip().split()] for i in f.readlines()]

	n, m = data[0]
	next_state = data[1:n+1]
	output = data[n+1:]

	compmat = np.ones((n, n), dtype = bool)
	flag = False
	for i in range(n):
		for j in range(n):
			if not compatible(output[i], output[j]):
				flag = True
				compmat[i, j] = False
	
	while flag:
		flag = False
		for i in range(n):
			for j in range(n):
				if compmat[i, j]:
					for k in range(m):
						if next_state[i][k] != -1 and next_state[j][k] != -1 and not compmat[next_state[i][k], next_state[j][k]]:
							flag = True
							compmat[i, j] = False
							break
	
	result = clique_partition(compmat)
	with open("test2.out", "w") as f:
		f.write(" ".join([str(i) for i in result]))
