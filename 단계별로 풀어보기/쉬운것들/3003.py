import sys
inL = list(map(int, sys.stdin.readline().strip().split()))
L = [1, 1, 2, 2, 2, 8]
for i in range(6): print(L[i] - inL[i], end=' ')