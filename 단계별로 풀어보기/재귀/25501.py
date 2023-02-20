def isPalindrome(s):
    l, r = 0, len(s)-1
    count = 1
    while l < r:
        if s[l] == s[r]:
            count += 1
            l += 1
            r -= 1
        else: break
    
    if l >= r: return 1, count
    else: return 0, count
    
import sys
N = int(input())

isP, C = [], []
for _ in range(N):
    res, count = isPalindrome(input())
    isP.append(res)
    C.append(count)
    
for i in range(N):
    print(isP[i], end=' ')
    print(C[i])