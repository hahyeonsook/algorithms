import copy

p = [20, 7, 23, 19, 10, 15, 25, 8, 13]
temp = []
i, j = 0, 0

for i in range(9):
    for j in range(9):
        if i == j:
            continue
        temp = sorted(copy.deepcopy(p))
        temp.remove(p[i])
        temp.remove(p[j])

        if sum(temp) == 100:
            break
    if sum(temp) == 100:
        break

for t in range(7):
    print(temp[t])
