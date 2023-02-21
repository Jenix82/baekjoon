N = int(input())
answer = []
for _ in range(N):
    tmp = input()
    answer.append(tmp[0] + tmp[-1])
    
for s in answer : print(s)