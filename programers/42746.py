import itertools


def sort_str(numbers):
    answer = ''
    for i in range(len(numbers)-1):
        if len(numbers[i]) != len(numbers[i+1]):
            if numbers[i] < numbers[i+1][-1]:
                numbers[i], numbers[i+1] = numbers[i+1], numbers[i]
            answer += numbers[i]
        else:
            answer += numbers[i]
    answer += numbers[-1]
    return answer


def solution(numbers):
    numstr = [str(numbers[i]) for i in range(len(numbers))]
    numstr.sort(key=lambda number: (-len(number), number), reverse=True)
    return sort_str(numstr)


print(solution([6, 10, 2]) == "6210")
print(solution([3, 30, 34, 5, 9]) == "9534330")

# um.... 1개 빼고 다 틀림
