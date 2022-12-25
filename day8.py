#!python3
import numpy as np


def scan(arr, arr_v):
    for i in range(1, len(arr)-1):
        ma = arr[i][0]
        for j in range(1, len(arr[i])-1):
            if arr[i][j] > ma:
                ma = arr[i][j]
                arr_v[i][j] = 1


file = open("8.in")
lines = [line.strip() for line in file]

arr = []
for line in lines:
    _arr = [int(c) for c in line]
    arr.append(_arr)

arr = np.array(arr)

arr_v = []
for i in range(len(arr)):
    arr_v.append([0 for i in range(len(arr[0]))])
arr_v = np.array(arr_v)

for _ in range(4):
    scan(arr, arr_v)
    arr = np.rot90(arr)
    arr_v = np.rot90(arr_v)

count = np.sum(arr_v)
print(count + 98*4)
