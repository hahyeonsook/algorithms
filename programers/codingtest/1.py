p = "82195"
s = "64723"


def solution(p, s):
    answer = 0
    if p == s:
        return 0
    for i in range(len(p)):
        if int(p[i]) == int(s[i]):
            continue
        fw = (10+int(s[i])-int(p[i])) % 10
        rv = (10-int(s[i])+int(p[i])) % 10
        if(fw < rv):
            answer += fw
        else:
            answer += rv
    return answer


print(solution(p, s))
