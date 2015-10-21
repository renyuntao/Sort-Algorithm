#!/usr/bin/env python
import itertools

def topologicalsort(graph):
	S,L = [],[]
	length = len(graph)
	for col in range(length):    #initial S
		have_incoming_edge = False
		for row in range(length):
			if graph[row][col] == 1:    #1 denote have edge 
				have_incoming_edge = True
				break
		if not have_incoming_edge:
			S.append(col)
	test_node = []
	while S:
		test_node.clear()
		tmp = S.pop()
		L.append(tmp+1)
		for col in range(length):
			if graph[tmp][col] == 1:
				graph[tmp][col] = 0   #0 denote don't have edge
				test_node.append(col)
		for t_node in test_node:
			have_incoming_edge = False
			for row in range(length):
				if graph[row][t_node] == 1:
					have_incoming_edge = True
					break
			if not have_incoming_edge:
				S.append(t_node)
	for row,col in itertools.product(range(length),range(length)):
		if graph[row][col] == 1:
			print('Error:have cycle')
	print(*L)

vertex_num,edge_num = [int(i) for i in input().split()]
graph = [[0 for j in range(vertex_num)] for i in range(vertex_num)]
for i in range(edge_num):
	src,des = [int(j)-1 for j in input().split()]
	graph[src][des] = 1
topologicalsort(graph)
