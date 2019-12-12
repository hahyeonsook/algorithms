N = int(input())
M = 0

for m in range(N):
    mn = m
    num = m
    for j in range(len(str(num))):
        mn += num % 10
        num = int(num/10)
    if N == mn:
        M = m
        break

print(M)
