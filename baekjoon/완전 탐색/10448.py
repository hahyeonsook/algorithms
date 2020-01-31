"""
1. 몇 분에 문제를 이해했나? 12.5
2. 몇 분동안 풀이를 생각했나?
3. 몇 분동안 코딩했나? 26.08
4. 몇 분동안 디버깅했나? 시간 초과함, 2개로도 되고 3개로도 되는 케이스가 있음 11.04
"""

n = int(input())
ks = []
for i in range(n):
    ks.append(int(input()))

triangle = [int(t*(t+1)/2) for t in range(1, 45)]

for m in range(n):
    for i in range(44):
        for j in range(44):
            sumtriangle = triangle[i] + triangle[j]
            if ks[m] - sumtriangle in triangle:
                ks[m] = 1
    if ks[m] != 1:
        ks[m] = 0

for i in range(n):
    print(ks[i])
