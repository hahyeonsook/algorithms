direction = [[0, -1], [1, 0], [0, 1], [-1, 0]]
office = [[5, -1, 4], [6, 3, -1], [2, -1, 1]]
r = 1
c = 0
move = ["go", "go", "right", "go", "right", "go", "left", "go"]


def isRange(n, r, c, d):
    return (n > r + d[1]) and(0 <= r + d[1])and (n > c+d[0]) and (0 <= c+d[0])


def command(cmd, r, c, d):
    answer = 0
    if cmd == "go":
        r += d[1]
        c += d[0]
    elif cmd == "left":
        n = direction.index(d)
        n = (n-1) % 4
        d = direction[n]
    elif cmd == "right":
        n = direction.index(d)
        n = (n+1) % 4
        d = direction[n]
    return answer


def solution(office, r, c, move):
    answer = 0
    if len(move) == 0:
        if office[r][c] == -1:
            return 0
        else:
            return office[r][c]
    n = len(office)
    d = direction[0]
    answer = office[r][c]
    office[r][c] = 0
    for cmd in move:
        if cmd == "go" and (isRange(n, r, c, d) is False):
            continue
        if cmd == "go":
            if office[r+d[1]][c+d[0]] != -1:
                r = r + d[1]
                c = c + d[0]
                answer += office[r][c]
                office[r][c] = 0
        elif cmd == "left":
            n = direction.index(d)
            n = (n-1) % 4
            d = direction[n]
        elif cmd == "right":

            n = direction.index(d)
            n = (n+1) % 4
            d = direction[n]
    return answer


print(solution(office, r, c, move))
