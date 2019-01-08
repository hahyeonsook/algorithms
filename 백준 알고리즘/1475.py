import math
class Backjon1475:
    def solve(self, inpt):
        # N(다솜이의 방 번호)를 받아온다.
        numBase = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        numSet = [0] * 10
        setNum = 0
        N = list(inpt)

        # N의 값의 번호를 추출하기 위해 10^n으로 나눈 나머지 값을 구하고
        # (N의 값을 10으로 나눈 값으로 update)
        # numSet의 k번째 숫자를 1++한다.

        for i in range(len(N)):
            for j in range(len(numBase)):
                if N[i] == numBase[j]:
                    numSet[j] += 1



            # 6과 9는 같이 쓸 수 있으므로 값을 더한 후, 나누고, 올림한다.
        if (numSet[6]+numSet[9]) > 1:
            numSet[6] = math.ceil((numSet[6] + numSet[9])/2)

        # 리스트의 가장 큰 값을 알아낸다.
        for k in range(len(numSet)-1):
            if setNum < numSet[k]:
                setNum = numSet[k]
        
        print(setNum)


print("백준 1475 문제\n\n")

bj = Backjon1475()

"""
bj.solve(49) # 1
bj.solve(1) # 1
bj.solve(0000) # 4
bj.solve(11) # 2
bj.solve(9999) # 2
bj.solve(99699) # 3
bj.solve(900966) # 2

for i in range(7):
    N = str(input())
    bj.solve(N)
"""


for i in range(1000000):
    k = str(i)
    bj.solve(k)

"""
방번호가 숫자가 아니라 번호이기 때문에 0이 여러개인 경우가 있다. 그때의 경우를 구하지 않음.
그럼 처음부터 다시해야 되는데, 숫자가 아닌 문자로 받아서 같은지 비교해야 한다.
"""