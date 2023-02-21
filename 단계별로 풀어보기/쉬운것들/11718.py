answer = []
while 1:
    try: x = input()
    except EOFError: break
    answer.append(x)
for a in answer: print(a)