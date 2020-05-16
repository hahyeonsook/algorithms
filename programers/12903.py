def solution(s):
    n = int(len(s) / 2)
    if len(s) % 2 == 0:
        return s[n-1:n+1]
    else:
        return s[n]


def solution(str):
    return str[(len(str)-1)//2:len(str)//2+1]


# //몫 연산자
print(solution("abcde"))
print(solution("qwer"))
