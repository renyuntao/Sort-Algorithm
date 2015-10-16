#!/usr/bin/env python
import random
def inOrder(ls):
	length = len(ls)
	if length == 0:
		return True
	for i in range(length-1):
		if ls[i] > ls[i+1]:
			return False
	return True

ls = [1,0,-1,20,7,15,23]
while not inOrder(ls):
	random.shuffle(ls)
print(ls)
