array = [1, 5, 2, 6, 3, 7, 4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]


def solution(array, commands):
    answer = []

    for i in range(len(commands)):
        command = commands[i]
        start, end, index = command[0]-1, command[1], command[2]-1
        part = array[start:end]
        part.sort()
        answer.append(part[index])

    return answer


print(solution(array, commands))


def solution(array, commands):
    return list(map(lambda x: (sorted(array[x[0]-1:x[1]])[x[2]-1]), commands))


print(solution(array, commands))
