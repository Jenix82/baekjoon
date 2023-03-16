import sys
import numpy as np
import math

m, M = map(int, sys.stdin.readline().rstrip().split())
List = np.ones((M - m + 1, ), dtype=int)
i = 2
while i * i <= M:
    if i > 2 and i % 2 == 0 :
        i += 1
        continue
    
    left, right = math.ceil(m / (i * i)), math.floor(M / (i * i))
    #if (i == 23):
    #    print(left, right)
    #    print(right * i * i - m)
    tmp = ((np.arange(right - left + 1) + left) * (i * i)) - m
    #if (i == 23): print(tmp)
    np.put(List, list(tmp), 0)
    i += 1

print(np.count_nonzero(List))

    
