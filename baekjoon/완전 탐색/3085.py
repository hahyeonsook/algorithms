"""
1. 몇 분에 문제를 이해했나? 2.13
2. 몇 분동안 풀이를 생각했나? 10.14
3. 몇 분동안 코딩했나? 33.31
4. 몇 분동안 디버깅했나? pass... 나중에 할거임..
"""

import copy

n = 5
candy = [
    list("YCPZY"),
    list("CYZZP"),
    list("CCPPP"),
    list("YCYZC"),
    list("CPPZZ"),
]  # 3
largest = 0

for i in range(n):
    for j in range(n):
        candy_b = copy.deepcopy(candy)
        if j != n-1:
            if candy_b[i][j] != candy_b[i][j+1]:
                candy_b[i][j], candy_b[i][j+1] = candy_b[i][j+1], candy_b[i][j]
            for m in range(n):
                for l in range(n):
                    cnt = 0
                    if l != n-1:
                        color = candy_b[m][l]
                        n_color = candy_b[m][l+1]
                        for k in range(l, n):
                            if color == n_color:
                                cnt += 1
                                n_color = candy_b[m][k]
                    if largest < cnt:
                        largest = cnt
                    cnt = 0
                    if m != n-1:
                        color = candy_b[m][l]
                        n_color = candy_b[m+1][l]
                        for k in range(m, n):
                            if color == n_color:
                                cnt += 1
                                n_color = candy_b[k][l]
                    if largest < cnt:
                        largest = cnt
        candy_b = copy.deepcopy(candy)
        if i != n-1:
            if candy_b[i][j] != candy_b[i+1][j]:
                candy_b[i][j], candy_b[i+1][j] = candy_b[i+1][j], candy_b[i][j]
            for m in range(n):
                for l in range(n):
                    cnt = 0
                    if l != n-1:
                        color = candy_b[m][l]
                        n_color = candy_b[m][l+1]
                        for k in range(l, n):
                            if color == n_color:
                                cnt += 1
                                n_color = candy_b[m][k]
                    if largest < cnt:
                        largest = cnt
                    cnt = 0
                    if m != n-1:
                        color = candy_b[m][l]
                        n_color = candy_b[m+1][l]
                        for k in range(m, n):
                            if color == n_color:
                                cnt += 1
                                n_color = candy_b[k][l]
                    if largest < cnt:
                        largest = cnt

print(largest)
