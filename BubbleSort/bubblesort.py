#!/usr/bin/env python

def bubbleSort(arr,length):
	for i in range(length-1):
		inOrder = True
		for j in range(length-1-i):
			if arr[j] > arr[j+1]:
				t = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = t
				inOrder = False
		if inOrder:
			break
	
ls = [-5,9,1,0,3,-2,12,8]
bubbleSort(ls,len(ls))
print(*ls)
