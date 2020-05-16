def solution(a, b):
    days = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU']
    month_days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    total = 0
    for month in range(a-1):
        total += month_days[month]
    total += (b-1)
    return days[total % 7]
    # 배열의 인덱스 연산에서는 음수값이 나오지 않는 연산으로만 구성하도록 주의


def solution(a, b):
    days = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU']
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    return days[sum(months[:a-1]) + (b-1) % 7]
