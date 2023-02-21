def isPalindrom(s):
    l, r = 0, len(s)-1
    while s[l] == s[r]: 
        l, r = l+1, r-1
        if r <= l : return 1
    return 0

print(isPalindrom(input()))